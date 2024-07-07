/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helpers3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 01:37:26 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 10:36:28 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_helpers3.h"
#include "main_helpers1.h"
#include "main_helpers2.h"

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
void	convert_number_to_words(t_dict_entry *dict, const char *number)
{
	int	len;

	len = ft_strlen(number);
	if (len == 0)
	{
		handle_empty_number();
		return ;
	}
	if (len == 1 || (len == 2 && number[0] == '1')
		|| (len == 2 && number[1] == '0'))
	{
		handle_single_digit(dict, number);
		return ;
	}
	if (len == 2)
	{
		handle_two_digits(dict, number);
		return ;
	}
	if (len >= 3)
	{
		convert_large_number_to_words(dict, number);
		return ;
	}
}

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
int	handle_two_args(char *arg, char *number)
{
	if (!is_valid_number(arg))
	{
		print_error("Error\n");
		return (1);
	}
	ft_strncpy(number, arg, BUFFER_SIZE);
	number[BUFFER_SIZE - 1] = '\0';
	return (0);
}

/*
** handle_three_args
** Handles the case where the program is called with three arguments.
**
** Paramètres :
** - char *arg1: Le premier argument (le nom de fichier du dictionnaire).
** - char *arg2: Le deuxième argument (le nombre à convertir).
** - const char **dict_filename: Pointeur pour stocker le nom du fichier dictionnaire.
** - char *number: Le buffer où stocker le nombre validé.
**
** Retourne : 0 si succès, 1 si erreur.
*/
int	handle_three_args(char *arg1,
		char *arg2, const char **dict_filename, char *number)
{
	*dict_filename = arg1;
	if (!is_valid_number(arg2))
	{
		print_error("Error\n");
		return (1);
	}
	ft_strncpy(number, arg2, BUFFER_SIZE);
	number[BUFFER_SIZE - 1] = '\0';
	return (0);
}

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
int	handle_args(int argc, char **argv, char *number, const char **dict_filename)
{
	if (argc == 2)
		return (handle_two_args(argv[1], number));
	else if (argc == 3)
		return (handle_three_args(argv[1], argv[2], dict_filename, number));
	else
	{
		print_error("Error\n");
		return (1);
	}
}
