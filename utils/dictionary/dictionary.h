/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 02:30:38 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 03:55:40 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICTIONARY_H
# define DICTIONARY_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../functions.h"

/*
** Struct s_dict_entry
** Represents an entry in the dictionary.
**
** Fields:
** - number: the numerical representation.
** - word: the word representation.
** - next: pointer to the next dictionary entry.
**
** Struct s_dict_entry
** Représente une entrée dans le dictionnaire.
**
** Champs :
** - number : la représentation numérique.
** - word : la représentation en mots.
** - next : pointeur vers l'entrée suivante du dictionnaire.
*/
typedef struct s_dict_entry
{
	char				*number;
	char				*word;
	struct s_dict_entry	*next;
}	t_dict_entry;

/*
** Struct s_line_info
** Holds information about a line being processed.
**
** Fields:
** - line: the line content.
** - len: the current length of the line.
** - capacity: the allocated capacity for the line.
**
** Struct s_line_info
** Contient des informations sur une ligne en cours de traitement.
**
** Champs :
** - line : le contenu de la ligne.
** - len : la longueur actuelle de la ligne.
** - capacity : la capacité allouée pour la ligne.
*/
typedef struct s_line_info
{
	char	*line;
	size_t	len;
	size_t	capacity;
}	t_line_info;

/*
** load_dictionary
** Loads the dictionary from a given file.
**
** Parameters:
** - filename: the name of the file to load the dictionary from.
**
** Returns:
** - A pointer to the head of the dictionary linked list.
**
** load_dictionary
** Charge le dictionnaire à partir d'un fichier donné.
**
** Paramètres :
** - filename : le nom du fichier à partir duquel charger le dictionnaire.
**
** Retourne :
** - Un pointeur vers la tête de la liste chaînée du dictionnaire.
*/
t_dict_entry	*load_dictionary(const char *filename);

/*
** get_word
** Retrieves the word associated with a given number from the dictionary.
**
** Parameters:
** - dict: the dictionary linked list.
** - number: the number to find the corresponding word for.
**
** Returns:
** - The word associated with the number, or NULL if not found.
**
** get_word
** Récupère le mot associé à un numéro donné dans le dictionnaire.
**
** Paramètres :
** - dict : la liste chaînée du dictionnaire.
** - number : le numéro pour lequel trouver le mot correspondant.
**
** Retourne :
** - Le mot associé au numéro, ou NULL s'il n'est pas trouvé.
*/
char			*get_word(t_dict_entry *dict, const char *number);

/*
** free_dictionary
** Frees the memory allocated for the dictionary.
**
** Parameters:
** - dict: the dictionary linked list to be freed.
**
** free_dictionary
** Libère la mémoire allouée pour le dictionnaire.
**
** Paramètres :
** - dict : la liste chaînée du dictionnaire à libérer.
*/
void			free_dictionary(t_dict_entry *dict);

#endif