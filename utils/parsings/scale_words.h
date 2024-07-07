/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_words.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 22:10:16 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 10:48:13 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALE_WORDS_H
# define SCALE_WORDS_H

# include "main_helpers1.h"
# include "main_helpers2.h"
# include "main_helpers3.h"
# include "dictionary.h"

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
const char	*get_scale_word(t_dict_entry *dict, int scale);

#endif