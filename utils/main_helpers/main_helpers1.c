/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helpers1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 01:36:57 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 16:38:18 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_helpers1.h"

void	print_error(const char *message)
{
	write(2, message, ft_strlen(message));
}

int	is_valid_number(const char *str)
{
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
		return (0);
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

void	handle_empty_number(void)
{
	print_error("Error\n");
}

void	handle_single_digit(t_dict_entry *dict, const char *number)
{
	char	*word;

	word = get_word(dict, number);
	if (word)
	{
		write(1, word, ft_strlen(word));
	}
	else
	{
		print_error("Dict Error\n");
	}
}
