/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_processing1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 02:30:24 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 04:05:26 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer_processing.h"
#include "common_dictionary.h"

/*
** allocate_line_buffer
** This function reallocates memory for the line buffer, doubling its capacity.
**
** Parameters:
**  - t_line_info *line_info: Structure containing information about the current line.
**
** Returns:
**  - int: 1 if successful, 0 otherwise.
**
** allocate_line_buffer
** Cette fonction réalloue de la mémoire pour le tampon de ligne, doublant sa capacité.
**
** Paramètres :
**  - t_line_info *line_info : Structure contenant des informations sur la ligne actuelle.
**
** Retourne :
**  - int : 1 si réussi, 0 sinon.
*/
int	allocate_line_buffer(t_line_info *line_info)
{
	char	*new_line;

	line_info->capacity *= 2;
	new_line = malloc(line_info->capacity);
	if (!new_line)
	{
		write(1, "Memory Error\n", 13);
		free(line_info->line);
		return (0);
	}
	ft_strcpy(new_line, line_info->line);
	free(line_info->line);
	line_info->line = new_line;
	return (1);
}

/*
** process_newline
** This function processes a single line by copying it into the line buffer and
** passing it to process_line for further processing.
**
** Parameters:
**  - t_line_info *line_info: Structure containing information about the current line.
**  - char *start: Pointer to the start of the buffer.
**  - char *newline: Pointer to the newline character in the buffer.
**  - t_dict_entry **head: Pointer to the head of the dictionary entries list.
**
** Returns:
**  - int: 1 if successful, 0 otherwise.
**
** process_newline
** Cette fonction traite une seule ligne en la copiant dans le tampon de ligne et
** en la passant à process_line pour un traitement ultérieur.
**
** Paramètres :
**  - t_line_info *line_info : Structure contenant des informations sur la ligne actuelle.
**  - char *start : Pointeur vers le début du tampon.
**  - char *newline : Pointeur vers le caractère de nouvelle ligne dans le tampon.
**  - t_dict_entry **head : Pointeur vers la tête de la liste des entrées du dictionnaire.
**
** Retourne :
**  - int : 1 si réussi, 0 sinon.
*/
int	process_newline(t_line_info *line_info, char *start,
		char *newline, t_dict_entry **head)
{
	if (!line_info || !start || !newline || !head)
	{
		return (0);
	}
	newline[0] = '\0';
	ft_strcpy(line_info->line + line_info->len, start);
	line_info->len += (newline - start);
	line_info->line[line_info->len] = '\0';
	process_line(line_info->line, head);
	line_info->len = 0;
	return (1);
}

/*
** handle_line_remainder
** This function handles the remainder of the line if it did not end with a newline character.
**
** Parameters:
**  - t_line_info *line_info: Structure containing information about the current line.
**  - char *start: Pointer to the start of the remaining part of the buffer.
**  - t_dict_entry **head: Pointer to the head of the dictionary entries list.
**
** Returns:
**  - int: 1 if successful, 0 otherwise.
**
** handle_line_remainder
** Cette fonction traite le reste de la ligne si elle ne se termine pas par un caractère de nouvelle ligne.
**
** Paramètres :
**  - t_line_info *line_info : Structure contenant des informations sur la ligne actuelle.
**  - char *start : Pointeur vers le début de la partie restante du tampon.
**  - t_dict_entry **head : Pointeur vers la tête de la liste des entrées du dictionnaire.
**
** Retourne :
**  - int : 1 si réussi, 0 sinon.
*/
int	handle_line_remainder(t_line_info *line_info,
		char *start, t_dict_entry **head)
{
	if (!line_info || !start || !head)
	{
		return (0);
	}
	if (*start != '\0')
	{
		if (line_info->len + ft_strlen(start) + 1 > line_info->capacity)
		{
			if (!allocate_line_buffer(line_info))
			{
				free_dictionary(*head);
				return (0);
			}
		}
		ft_strcpy(line_info->line + line_info->len, start);
		line_info->len += ft_strlen(start);
	}
	return (1);
}
