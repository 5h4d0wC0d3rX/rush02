/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:15:27 by cbopp             #+#    #+#             */
/*   Updated: 2024/07/07 10:43:51 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "scale_words.h"
#include "main_helpers1.h"
#include "main_helpers2.h"
#include "main_helpers3.h"
#include "dictionary.h"
#include "string_utils.h"
#include "handling.h"

#define BUFFER_SIZE 1024

/*
** handle_scale
** Handle the conversion of the scale part (thousands, millions, etc.) of a number.
**
** Paramètres :
** - t_dict_entry *dict: Le dictionnaire utilisé pour convertir le nombre.
** - int scale: Le facteur d'échelle du nombre (e.g., 1 pour mille, 2 pour million).
**
** Retourne : Rien.
*/
void	handle_scale(t_dict_entry *dict, int scale)
{
	const char	*scale_word;

	if (scale > 0)
	{
		scale_word = get_scale_word(dict, scale);
		if (scale_word && ft_strlen(scale_word) > 0)
		{
			write(1, " ", 1);
			write(1, scale_word, ft_strlen(scale_word));
		}
		else
			print_error("Dict Error\n");
	}
}

/*
** convert_group_to_words
** Convertit un groupe de chiffres en mots et gère les centaines, dizaines et unités.
**
** Paramètres :
** - t_dict_entry *dict: Le dictionnaire utilisé pour convertir le nombre.
** - const char *group: Le groupe de chiffres à convertir.
** - int scale: Le facteur d'échelle associé à ce groupe de chiffres.
**
** Retourne : Rien.
*/
void	convert_group_to_words(t_dict_entry *dict, const char *group, int scale)
{
	int	len;

	len = ft_strlen(group);
	if (len == 3 && group[0] != '0')
		handle_hundreds(dict, group);
	handle_tens(dict, group, len);
	handle_scale(dict, scale);
}

/*
** process_group
** Traite un groupe de chiffres, les convertit en mots et applique le facteur d'échelle.
**
** Paramètres :
** - t_dict_entry *dict: Le dictionnaire utilisé pour convertir le nombre.
** - const char *number: Le groupe de chiffres à traiter.
** - int len: La longueur du groupe de chiffres.
** - int scale: Le facteur d'échelle associé à ce groupe de chiffres.
**
** Retourne : Rien.
*/
void	process_group(t_dict_entry *dict, const char *number, int len, int scale)
{
	char	group[4];

	ft_bzero(group, 4);
	ft_strncpy(group, number, len);
	convert_group_to_words(dict, group, scale);
}

/*
** convert_large_number_to_words
** Convertit un nombre de grande taille en mots, en divisant le nombre en groupes de centaines.
**
** Paramètres :
** - t_dict_entry *dict: Le dictionnaire utilisé pour convertir le nombre.
** - const char *number: Le nombre à convertir.
**
** Retourne : Rien.
*/
void	convert_large_number_to_words(t_dict_entry *dict, const char *number)
{
	int		len;
	int		scale;
	int		group_len;

	len = ft_strlen(number);
	scale = (len - 1) / 3;
	while (len > 0)
	{
		if (len <= 3)
		{
			process_group(dict, number, len, scale);
			break ;
		}
		else
		{
			if (len % 3 == 0)
				group_len = 3;
			else
				group_len = len % 3;
			process_group(dict, number, group_len, scale);
			number += group_len;
			len -= group_len;
			scale--;
		}
	}
}