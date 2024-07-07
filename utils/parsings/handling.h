/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 00:17:15 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 10:42:04 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLING_H
# define HANDLING_H

#include "dictionary.h"

/*
** handle_hundreds
** Handles the conversion of the hundreds place in a given number group.
**
** Paramètres :
** - t_dict_entry *dict: Le dictionnaire utilisé pour convertir le nombre.
** - const char *group: Le groupe de chiffres représentant les centaines.
**
** Retourne : Rien.
*/
void	handle_hundreds(t_dict_entry *dict, const char *group);

/*
** handle_tens
** Handles the conversion of the tens and units place in a given number group.
**
** Paramètres :
** - t_dict_entry *dict: Le dictionnaire utilisé pour convertir le nombre.
** - const char *group: Le groupe de chiffres représentant les dizaines et unités.
** - int len: La longueur du groupe de chiffres.
**
** Retourne : Rien.
*/
void	handle_tens(t_dict_entry *dict, const char *group, int len);

/*
** print_tens_and_units
** Prints the tens and units place for a given number group.
**
** Paramètres :
** - t_dict_entry *dict: Le dictionnaire utilisé pour convertir le nombre.
** - char *word: Le mot représentant les dizaines.
** - const char *group: Le groupe de chiffres représentant les dizaines et unités.
** - int len: La longueur du groupe de chiffres.
**
** Retourne : Rien.
*/
void	print_tens_and_units(t_dict_entry *dict, char *word, const char *group, int len);

#endif
