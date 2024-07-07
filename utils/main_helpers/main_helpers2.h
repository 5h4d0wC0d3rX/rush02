/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helpers2.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 01:36:34 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 04:17:06 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HELPERS2_H
# define MAIN_HELPERS2_H

# include "main_helpers_common.h"
# include <unistd.h>
# include "../dictionary/dictionary.h"
# include "../functions.h"
# include "../parsings/parsing.h"
# include "../parsings/utility.h"

/*
** handle_non_zero_second_digit
** Handles the case where the second digit is non-zero by adding a hyphen
** and displaying the corresponding word.
**
** Paramètres :
** - t_dict_entry *dict: Le dictionnaire utilisé pour convertir le nombre.
** - const char *number: Le nombre à convertir.
** - char *buffer: Le buffer utilisé pour la conversion.
**
** Retourne : Rien.
*/
void	handle_non_zero_second_digit(t_dict_entry *dict, const char *number,
			char *buffer);

/*
** handle_word_output
** Displays the word corresponding to the number and adds a newline.
**
** Paramètres :
** - char *word: Le mot à afficher.
**
** Retourne : Rien.
*/
void	handle_word_output(char *word);

/*
** handle_buffer_error
** Handles buffer-related errors by displaying an error message.
**
** Paramètres : Aucun.
**
** Retourne : Rien.
*/
void	handle_buffer_error(void);

/*
** handle_two_digits
** Handles the case where the number consists of two digits.
**
** Paramètres :
** - t_dict_entry *dict: Le dictionnaire utilisé pour convertir le nombre.
** - const char *number: Le nombre à convertir.
**
** Retourne : Rien.
*/
void	handle_two_digits(t_dict_entry *dict, const char *number);

#endif