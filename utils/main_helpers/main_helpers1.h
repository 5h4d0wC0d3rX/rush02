/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helpers1.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 01:36:14 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 04:13:33 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HELPERS1_H
# define MAIN_HELPERS1_H

# include "main_helpers_common.h"
# include <unistd.h>
# include "../dictionary/dictionary.h"
# include "../functions.h"
# include "../parsings/parsing.h"
# include "../parsings/utility.h"

/*
** print_error
** Affiche un message d'erreur sur la sortie standard.
**
** Paramètres :
** - const char *message: Le message d'erreur à afficher.
**
** Retourne : Rien.
*/
void	print_error(const char *message);

/*
** is_valid_number
** Vérifie si une chaîne de caractères est un nombre valide.
**
** Paramètres :
** - const char *str: La chaîne de caractères à vérifier.
**
** Retourne :
** - 1 si la chaîne est un nombre valide.
** - 0 sinon.
*/
int		is_valid_number(const char *str);

/*
** handle_empty_number
** Gère le cas où le nombre d'entrée est vide.
**
** Paramètres : Aucun.
**
** Retourne : Rien.
*/
void	handle_empty_number(void);

/*
** handle_single_digit
** Gère le cas où le nombre d'entrée est un chiffre unique.
**
** Paramètres :
** - t_dict_entry *dict: Le dictionnaire utilisé pour convertir le nombre.
** - const char *number: Le chiffre unique à convertir.
**
** Retourne : Rien.
*/
void	handle_single_digit(t_dict_entry *dict, const char *number);

#endif