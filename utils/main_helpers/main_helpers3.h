/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helpers3.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 01:36:46 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 10:38:11 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HELPERS3_H
# define MAIN_HELPERS3_H

# include "main_helpers_common.h"
# include <unistd.h>
# include "../dictionary/dictionary.h"
# include "../functions.h"
# include "../parsings/parsing.h"
# include "../parsings/utility.h"

/*
** convert_number_to_words
** Converts a given number to words using the provided dictionary.
**
** Paramètres :
** - t_dict_entry *dict: Le dictionnaire utilisé pour convertir le nombre.
** - const char *number: Le nombre à convertir.
**
** Retourne : Rien.
*/
void	convert_number_to_words(t_dict_entry *dict, const char *number);

/*
** handle_two_args
** Handles the case where the program is called with two arguments.
**
** Paramètres :
** - char *arg: Le premier argument (le nombre à convertir).
** - char *number: Le buffer où stocker le nombre validé.
**
** Retourne : 0 si succès, 1 si erreur.
*/
int		handle_two_args(char *arg, char *number);

/*
** handle_three_args
** Handles the case where the program is called avec three arguments.
**
** Paramètres :
** - char *arg1: Le premier argument (le nom de fichier du dictionnaire).
** - char *arg2: Le deuxième argument (le nombre à convertir).
** - const char **dict_filename: Pointeur pour stocker le nom du fichier dictionnaire.
** - char *number: Le buffer où stocker le nombre validé.
**
** Retourne : 0 si succès, 1 si erreur.
*/
int		handle_three_args(char *arg1, char *arg2, const char **dict_filename, char *number);

/*
** handle_args
** Handles the command-line arguments and validates them.
**
** Paramètres :
** - int argc: Le nombre d'arguments passés au programme.
** - char **argv: Les arguments passés au programme.
** - char *number: Le buffer où stocker le nombre validé.
** - const char **dict_filename: Pointeur pour stocker le nom du fichier dictionnaire.
**
** Retourne : 0 si succès, 1 si erreur.
*/
int		handle_args(int argc, char **argv, char *number, const char **dict_filename);

#endif