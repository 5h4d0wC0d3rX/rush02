/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_processing2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 03:15:14 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 04:03:28 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer_processing.h"
#include "common_dictionary.h"

/*
** process_buffer_part
** This function processes part of the buffer. It reads lines until it finds a newline character,
** and processes each line using process_newline.
**
** Parameters:
**  - t_line_info *line_info: Structure containing information about the current line.
**  - char *start: Pointer to the start of the buffer.
**  - t_dict_entry **head: Pointer to the head of the dictionary entries list.
**
** Returns:
**  - int: 1 if successful, 0 otherwise.
**
** process_buffer_part
** Cette fonction traite une partie du tampon. Elle lit les lignes jusqu'à trouver un caractère de nouvelle ligne,
** et traite chaque ligne en utilisant process_newline.
**
** Paramètres :
**  - t_line_info *line_info : Structure contenant des informations sur la ligne actuelle.
**  - char *start : Pointeur vers le début du tampon.
**  - t_dict_entry **head : Pointeur vers la tête de la liste des entrées du dictionnaire.
**
** Retourne :
**  - int : 1 si réussi, 0 sinon.
*/
int	process_buffer_part(t_line_info *line_info,
		char *start, t_dict_entry **head)
{
	char	*newline;

	newline = ft_strchr(start, '\n');
	while (newline != NULL)
	{
		if (line_info->len + (newline - start) + 1 > line_info->capacity)
		{
			if (!allocate_line_buffer(line_info))
			{
				free_dictionary(*head);
				return (0);
			}
		}
		if (!process_newline(line_info, start, newline, head))
		{
			free_dictionary(*head);
			return (0);
		}
		start = newline + 1;
		newline = ft_strchr(start, '\n');
	}
	return (handle_line_remainder(line_info, start, head));
}

/*
** process_buffer
** This function processes the entire buffer by marking the end of the buffer with a null character
** and then calling process_buffer_part to handle the actual line processing.
**
** Parameters:
**  - char *buffer: The buffer containing the data to process.
**  - size_t bytes_read: Number of bytes read into the buffer.
**  - t_line_info *line_info: Structure containing information about the current line.
**  - t_dict_entry **head: Pointer to the head of the dictionary entries list.
**
** Returns:
**  - int: 1 if successful, 0 otherwise.
**
** process_buffer
** Cette fonction traite l'ensemble du tampon en marquant la fin du tampon avec un caractère nul
** puis en appelant process_buffer_part pour gérer le traitement des lignes.
**
** Paramètres :
**  - char *buffer : Le tampon contenant les données à traiter.
**  - size_t bytes_read : Nombre d'octets lus dans le tampon.
**  - t_line_info *line_info : Structure contenant des informations sur la ligne actuelle.
**  - t_dict_entry **head : Pointeur vers la tête de la liste des entrées du dictionnaire.
**
** Retourne :
**  - int : 1 si réussi, 0 sinon.
*/
int	process_buffer(char *buffer,
		size_t bytes_read, t_line_info *line_info, t_dict_entry **head)
{
	if (!buffer || !line_info || !head)
	{
		return (0);
	}
	buffer[bytes_read] = '\0';
	return (process_buffer_part(line_info, buffer, head));
}

/*
** process_file
** This function processes the file by reading it into a buffer and then calling process_buffer
** to handle the line processing.
**
** Parameters:
**  - int fd: File descriptor of the file to process.
**  - t_line_info *line_info: Structure containing information about the current line.
**
** Returns:
**  - t_dict_entry*: Pointer to the head of the dictionary entries list if successful, NULL otherwise.
**
** process_file
** Cette fonction traite le fichier en le lisant dans un tampon, puis en appelant process_buffer
** pour gérer le traitement des lignes.
**
** Paramètres :
**  - int fd : Descripteur de fichier du fichier à traiter.
**  - t_line_info *line_info : Structure contenant des informations sur la ligne actuelle.
**
** Retourne :
**  - t_dict_entry* : Pointeur vers la tête de la liste des entrées du dictionnaire si réussi, NULL sinon.
*/
t_dict_entry	*process_file(int fd, t_line_info *line_info)
{
	char			buffer[BUFFER_SIZE + 1];
	int				bytes_read;
	t_dict_entry	*head;

	if (!line_info)
	{
		return (NULL);
	}
	head = NULL;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		if (!process_buffer(buffer, bytes_read, line_info, &head))
		{
			free(line_info->line);
			free_dictionary(head);
			return (NULL);
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	return (head);
}

/*
** read_lines_from_file
** This function reads lines from the file by first allocating memory for the line buffer,
** then calling process_file to process the file.
**
** Parameters:
**  - int fd: File descriptor of the file to read.
**
** Returns:
**  - t_dict_entry*: Pointer to the head of the dictionary entries list if successful, NULL otherwise.
**
** read_lines_from_file
** Cette fonction lit les lignes du fichier en allouant d'abord de la mémoire pour le tampon de ligne,
** puis en appelant process_file pour traiter le fichier.
**
** Paramètres :
**  - int fd : Descripteur de fichier du fichier à lire.
**
** Retourne :
**  - t_dict_entry* : Pointeur vers la tête de la liste des entrées du dictionnaire si réussi, NULL sinon.
*/
t_dict_entry	*read_lines_from_file(int fd)
{
	t_dict_entry	*head;
	t_line_info		line_info;

	line_info.line = NULL;
	line_info.len = 0;
	line_info.capacity = BUFFER_SIZE;
	line_info.line = malloc(line_info.capacity);
	if (!line_info.line)
	{
		write(1, "Memory Error\n", 13);
		return (NULL);
	}
	head = process_file(fd, &line_info);
	free(line_info.line);
	return (head);
}
