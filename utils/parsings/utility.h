/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 00:15:55 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 10:52:23 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_H
# define UTILITY_H

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
char	*fetch_hundred_word(t_dict_entry *dict, const char *key);

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
char	*fetch_tens_word(t_dict_entry *dict, const char *key);

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
void	print_hundred(char *word, char *hundred_word);

/*
** print_error
** Imprime un message d'erreur sur la sortie standard.
**
** Paramètres :
** - const char *message: Le message d'erreur à imprimer.
**
** Retourne :
** - void
**
** print_error
** Prints an error message to the standard output.
**
** Parameters:
** - const char *message: The error message to print.
**
** Returns:
** - void
*/
void	print_error(const char *message);

#endif