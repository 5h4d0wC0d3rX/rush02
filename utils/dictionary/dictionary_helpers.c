/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 02:30:08 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 04:00:45 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dictionary_helpers.h"

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
t_dict_entry	*create_entry(const char *number, const char *word)
{
	t_dict_entry	*entry;

	entry = malloc(sizeof(t_dict_entry));
	if (!entry)
		return (NULL);
	entry->number = ft_strdup(trim((char *)number));
	entry->word = ft_strdup(trim((char *)word));
	entry->next = NULL;
	return (entry);
}

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
void	add_entry(t_dict_entry **head, t_dict_entry *new_entry)
{
	t_dict_entry	*current;

	if (*head == NULL)
	{
		*head = new_entry;
	}
	else
	{
		current = *head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_entry;
	}
}

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
void	process_line(char *line, t_dict_entry **head)
{
	char			*colon;
	t_dict_entry	*entry;

	colon = ft_strchr(line, ':');
	if (colon)
	{
		*colon = '\0';
		entry = create_entry(line, colon + 1);
		if (entry)
			add_entry(head, entry);
		else
		{
			free(line);
			free_dictionary(*head);
			write(1, "Dict Error\n", 11);
		}
	}
}