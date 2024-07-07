/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 02:29:36 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 03:56:57 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary.h"
#include "dictionary_helpers.h"
#include "buffer_processing.h"

/*
** load_dictionary
** Loads the dictionary from a file.
**
** Parameters:
** - filename: the name of the file to load the dictionary from.
**
** Returns:
** - A pointer to the head of the dictionary linked list, or NULL if an error occurs.
**
** load_dictionary
** Charge le dictionnaire à partir d'un fichier.
**
** Paramètres :
** - filename : le nom du fichier à partir duquel charger le dictionnaire.
**
** Retourne :
** - Un pointeur vers la tête de la liste chaînée du dictionnaire, ou NULL en cas d'erreur.
*/
t_dict_entry	*load_dictionary(const char *filename)
{
	int				fd;
	t_dict_entry	*head;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Dict Error\n", 11);
		return (NULL);
	}
	head = read_lines_from_file(fd);
	close(fd);
	return (head);
}

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
char	*get_word(t_dict_entry *dict, const char *number)
{
	while (dict)
	{
		if (ft_strcmp(dict->number, number) == 0)
			return (dict->word);
		dict = dict->next;
	}
	return (NULL);
}

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
void	free_dictionary(t_dict_entry *dict)
{
	t_dict_entry	*temp;

	while (dict)
	{
		temp = dict;
		dict = dict->next;
		free(temp->number);
		free(temp->word);
		free(temp);
	}
}