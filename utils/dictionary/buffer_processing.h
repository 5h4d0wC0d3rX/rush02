/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_processing.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 02:31:00 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 04:07:13 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_PROCESSING_H
# define BUFFER_PROCESSING_H

# include "dictionary.h"
# include "dictionary_helpers.h"
# include "common_dictionary.h"

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
int				allocate_line_buffer(t_line_info *line_info);

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
int				process_newline(t_line_info *line_info, char *start,
					char *newline, t_dict_entry **head);

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
int				handle_line_remainder(t_line_info *line_info,
					char *start, t_dict_entry **head);

/*
** process_buffer_part
** This function processes parts of the buffer, handling newlines and
** calling the appropriate functions to manage the line buffer and dictionary entries.
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
** Cette fonction traite des parties du tampon, gérant les nouvelles lignes et
** appelant les fonctions appropriées pour gérer le tampon de ligne et les entrées du dictionnaire.
**
** Paramètres :
**  - t_line_info *line_info : Structure contenant des informations sur la ligne actuelle.
**  - char *start : Pointeur vers le début du tampon.
**  - t_dict_entry **head : Pointeur vers la tête de la liste des entrées du dictionnaire.
**
** Retourne :
**  - int : 1 si réussi, 0 sinon.
*/
int				process_buffer_part(t_line_info *line_info,
					char *start, t_dict_entry **head);

/*
** process_buffer
** This function processes the entire buffer, delegating parts to process_buffer_part.
**
** Parameters:
**  - char *buffer: The buffer containing the file contents.
**  - size_t bytes_read: The number of bytes read into the buffer.
**  - t_line_info *line_info: Structure containing information about the current line.
**  - t_dict_entry **head: Pointer to the head of the dictionary entries list.
**
** Returns:
**  - int: 1 if successful, 0 otherwise.
**
** process_buffer
** Cette fonction traite l'intégralité du tampon, déléguant des parties à process_buffer_part.
**
** Paramètres :
**  - char *buffer : Le tampon contenant le contenu du fichier.
**  - size_t bytes_read : Le nombre d'octets lus dans le tampon.
**  - t_line_info *line_info : Structure contenant des informations sur la ligne actuelle.
**  - t_dict_entry **head : Pointeur vers la tête de la liste des entrées du dictionnaire.
**
** Retourne :
**  - int : 1 si réussi, 0 sinon.
*/
int				process_buffer(char *buffer,
					size_t bytes_read, t_line_info *line_info,
					t_dict_entry **head);

/*
** process_file
** This function reads the file in chunks and processes each chunk using process_buffer.
**
** Parameters:
**  - int fd: The file descriptor of the file to read.
**  - t_line_info *line_info: Structure containing information about the current line.
**
** Returns:
**  - t_dict_entry*: Pointer to the head of the dictionary entries list.
**
** process_file
** Cette fonction lit le fichier par morceaux et traite chaque morceau en utilisant process_buffer.
**
** Paramètres :
**  - int fd : Le descripteur de fichier du fichier à lire.
**  - t_line_info *line_info : Structure contenant des informations sur la ligne actuelle.
**
** Retourne :
**  - t_dict_entry* : Pointeur vers la tête de la liste des entrées du dictionnaire.
*/
t_dict_entry	*process_file(int fd, t_line_info *line_info);

/*
** read_lines_from_file
** This function initializes the line buffer and starts processing the file.
**
** Parameters:
**  - int fd: The file descriptor of the file to read.
**
** Returns:
**  - t_dict_entry*: Pointer to the head of the dictionary entries list.
**
** read_lines_from_file
** Cette fonction initialise le tampon de ligne et commence le traitement du fichier.
**
** Paramètres :
**  - int fd : Le descripteur de fichier du fichier à lire.
**
** Retourne :
**  - t_dict_entry* : Pointeur vers la tête de la liste des entrées du dictionnaire.
*/
t_dict_entry	*read_lines_from_file(int fd);

#endif