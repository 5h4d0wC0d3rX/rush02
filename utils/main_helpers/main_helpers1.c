/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helpers1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 01:36:57 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 04:12:37 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_helpers1.h"

/*
** print_error
** This function prints an error message to the standard output.
**
** Parameters:
** - const char *message: The error message to be printed.
**
** Retourne : Rien.
**
** Exécution :
** - Cette fonction utilise la fonction write pour afficher le message d'erreur.
*/
void	print_error(const char *message)
{
	write(1, message, ft_strlen(message));
}

/*
** is_valid_number
** This function checks if a given string is a valid number.
**
** Parameters:
** - const char *str: The string to be checked.
**
** Returns:
** - 1 if the string is a valid number.
** - 0 otherwise.
**
** Exécution :
** - La fonction parcourt la chaîne de caractères pour vérifier si elle contient
**   uniquement des chiffres, en ignorant les espaces et les signes au début.
*/
int	is_valid_number(const char *str)
{
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (!ft_isdigit((unsigned char)*str))
			return (0);
		str++;
	}
	return (1);
}

/*
** handle_empty_number
** This function handles the case when the input number is empty.
**
** Parameters: None.
**
** Retourne : Rien.
**
** Exécution :
** - La fonction affiche un message d'erreur.
*/
void	handle_empty_number(void)
{
	print_error("Error\n");
}

/*
** handle_single_digit
** This function handles the case when the input number is a single digit.
**
** Parameters:
** - t_dict_entry *dict: The dictionary used for converting the number.
** - const char *number: The single digit number to be converted.
**
** Retourne : Rien.
**
** Exécution :
** - La fonction cherche le mot correspondant au chiffre dans le dictionnaire
**   et l'affiche. Si le mot n'est pas trouvé, elle affiche un message d'erreur.
*/
void	handle_single_digit(t_dict_entry *dict, const char *number)
{
	char	*word;

	word = get_word(dict, number);
	if (word)
	{
		write(1, word, ft_strlen(word));
		write(1, "\n", 1);
	}
	else
	{
		print_error("Dict Error\n");
	}
}