/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary_helpers.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 02:30:50 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 03:58:09 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICTIONARY_HELPERS_H
# define DICTIONARY_HELPERS_H

# include "dictionary.h"

/*
** create_entry
** Creates a new dictionary entry with the given number and word.
**
** Parameters:
** - number: the number associated with the word.
** - word: the word associated with the number.
**
** Returns:
** - A pointer to the newly created dictionary entry, or NULL if memory allocation fails.
**
** create_entry
** Crée une nouvelle entrée de dictionnaire avec le numéro et le mot donnés.
**
** Paramètres :
** - number : le numéro associé au mot.
** - word : le mot associé au numéro.
**
** Retourne :
** - Un pointeur vers la nouvelle entrée de dictionnaire créée, ou NULL si l'allocation de mémoire échoue.
*/
t_dict_entry	*create_entry(const char *number, const char *word);

/*
** add_entry
** Adds a new entry to the dictionary linked list.
**
** Parameters:
** - head: a pointer to the head of the dictionary linked list.
** - new_entry: the new entry to be added to the dictionary.
**
** add_entry
** Ajoute une nouvelle entrée à la liste chaînée du dictionnaire.
**
** Paramètres :
** - head : un pointeur vers la tête de la liste chaînée du dictionnaire.
** - new_entry : la nouvelle entrée à ajouter au dictionnaire.
*/
void			add_entry(t_dict_entry **head, t_dict_entry *new_entry);

/*
** process_line
** Processes a line from the dictionary file and adds the corresponding entry to the dictionary.
**
** Parameters:
** - line: the line from the dictionary file.
** - head: a pointer to the head of the dictionary linked list.
**
** process_line
** Traite une ligne du fichier de dictionnaire et ajoute l'entrée correspondante au dictionnaire.
**
** Paramètres :
** - line : la ligne du fichier de dictionnaire.
** - head : un pointeur vers la tête de la liste chaînée du dictionnaire.
*/
void			process_line(char *line, t_dict_entry **head);

#endif