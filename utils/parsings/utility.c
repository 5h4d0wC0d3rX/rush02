/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 23:58:48 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 10:50:20 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "dictionary.h"
#include "string_utils.h"
#include "utility.h"

/*
** fetch_hundred_word
** Recherche et retourne le mot correspondant à une clé donnée pour les centaines dans le dictionnaire.
** Si le mot n'est pas trouvé, une erreur est imprimée et NULL est retourné.
**
** Paramètres :
** - t_dict_entry *dict: Le dictionnaire utilisé pour la recherche.
** - const char *key: La clé utilisée pour la recherche (par exemple, "100").
**
** Retourne :
** - char*: Le mot correspondant à la clé, ou NULL si non trouvé.
**
** fetch_hundred_word
** Fetches and returns the word corresponding to a given key for hundreds in the dictionary.
** If the word is not found, an error is printed and NULL is returned.
**
** Parameters:
** - t_dict_entry *dict: The dictionary used for the lookup.
** - const char *key: The key used for the lookup (e.g., "100").
**
** Returns:
** - char*: The word corresponding to the key, or NULL if not found.
*/
char	*fetch_hundred_word(t_dict_entry *dict, const char *key)
{
	char	*word;

	word = get_word(dict, key);
	if (!word)
	{
		print_error("Dict Error\n");
		return (NULL);
	}
	return (word);
}

/*
** fetch_tens_word
** Recherche et retourne le mot correspondant à une clé donnée pour les dizaines dans le dictionnaire.
** Si le mot n'est pas trouvé, une erreur est imprimée et NULL est retourné.
**
** Paramètres :
** - t_dict_entry *dict: Le dictionnaire utilisé pour la recherche.
** - const char *key: La clé utilisée pour la recherche (par exemple, "20").
**
** Retourne :
** - char*: Le mot correspondant à la clé, ou NULL si non trouvé.
**
** fetch_tens_word
** Fetches and returns the word corresponding to a given key for tens in the dictionary.
** If the word is not found, an error is printed and NULL is returned.
**
** Parameters:
** - t_dict_entry *dict: The dictionary used for the lookup.
** - const char *key: The key used for the lookup (e.g., "20").
**
** Returns:
** - char*: The word corresponding to the key, or NULL if not found.
*/
char	*fetch_tens_word(t_dict_entry *dict, const char *key)
{
	char	*word;

	word = get_word(dict, key);
	if (!word)
	{
		print_error("Dict Error\n");
		return (NULL);
	}
	return (word);
}

/*
** print_hundred
** Imprime les mots pour une centaine avec un espace entre les mots.
**
** Paramètres :
** - char *word: Le mot pour le chiffre des centaines.
** - char *hundred_word: Le mot "cent" correspondant.
**
** Retourne :
** - void
**
** print_hundred
** Prints the words for a hundred with a space between the words.
**
** Parameters:
** - char *word: The word for the hundred digit.
** - char *hundred_word: The word "hundred".
**
** Returns:
** - void
*/
void	print_hundred(char *word, char *hundred_word)
{
	write(1, word, ft_strlen(word));
	write(1, " ", 1);
	write(1, hundred_word, ft_strlen(hundred_word));
	write(1, " ", 1);
}
