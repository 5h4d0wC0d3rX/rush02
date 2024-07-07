/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 21:56:39 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 10:47:41 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "scale_words.h"
#include "main_helpers1.h"
#include "main_helpers2.h"
#include "main_helpers3.h"
#include "string_utils.h"

#define BUFFER_SIZE 1024

/*
** get_scale_string
** Retourne la chaîne de caractères représentant l'échelle correspondant
** à l'indice donné. Si l'indice est hors limites, une chaîne vide est retournée.
**
** Paramètres :
** - int scale: L'indice de l'échelle (par exemple, 0 pour "", 1 pour "1000", etc.).
**
** Retourne :
** - const char*: La chaîne de caractères représentant l'échelle.
**
** get_scale_string
** Returns the string representing the scale corresponding to the given index.
** If the index is out of bounds, an empty string is returned.
**
** Parameters:
** - int scale: The index of the scale (e.g., 0 for "", 1 for "1000", etc.).
**
** Returns:
** - const char*: The string representing the scale.
*/
static const char	*get_scale_string(int scale)
{
	const char	*scale_strings[] = {
		"", "1000", "1000000", "1000000000", "1000000000000",
		"1000000000000000", "1000000000000000000",
		"1000000000000000000000", "1000000000000000000000000",
		"1000000000000000000000000000",
		"1000000000000000000000000000000",
		"1000000000000000000000000000000000",
		"1000000000000000000000000000000000000"
	};

	if (scale < 0
		|| scale >= (int)(sizeof(scale_strings) / sizeof(scale_strings[0])))
		return ("");
	return (scale_strings[scale]);
}

/*
** get_scale_word
** Retourne le mot correspondant à l'échelle donnée en recherchant dans le dictionnaire.
** Si le mot n'est pas trouvé dans le dictionnaire, une chaîne vide est retournée.
**
** Paramètres :
** - t_dict_entry *dict: Le dictionnaire utilisé pour la recherche.
** - int scale: L'indice de l'échelle (par exemple, 0 pour "", 1 pour "1000", etc.).
**
** Retourne :
** - const char*: Le mot représentant l'échelle, ou une chaîne vide si non trouvé.
**
** get_scale_word
** Returns the word corresponding to the given scale by looking it up in the dictionary.
** If the word is not found in the dictionary, an empty string is returned.
**
** Parameters:
** - t_dict_entry *dict: The dictionary used for the lookup.
** - int scale: The index of the scale (e.g., 0 for "", 1 for "1000", etc.).
**
** Returns:
** - const char*: The word representing the scale, or an empty string if not found.
*/
const char	*get_scale_word(t_dict_entry *dict, int scale)
{
	char		buffer[BUFFER_SIZE];
	const char	*scale_str;
	char		*word;

	scale_str = get_scale_string(scale);
	ft_strcpy(buffer, scale_str);
	word = get_word(dict, buffer);
	if (word)
		return (word);
	else
		return ("");
}
