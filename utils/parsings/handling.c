/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 23:59:43 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 10:41:39 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
void	handle_hundreds(t_dict_entry *dict, const char *group)
{
	char	buffer[2];
	char	*word;
	char	*hundred_word;

	buffer[0] = group[0];
	buffer[1] = '\0';
	word = fetch_hundred_word(dict, buffer);
	if (!word)
		return ;
	hundred_word = fetch_hundred_word(dict, "100");
	if (!hundred_word)
		return ;
	print_hundred(word, hundred_word);
}

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
void	print_tens_and_units(t_dict_entry *dict, char *word, const char *group, int len)
{
	char	buffer[3];

	write(1, word, ft_strlen(word));
	if (group[len - 1] != '0')
	{
		write(1, "-", 1);
		buffer[0] = group[len - 1];
		buffer[1] = '\0';
		word = fetch_tens_word(dict, buffer);
		if (word)
			write(1, word, ft_strlen(word));
	}
}

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
void	handle_tens(t_dict_entry *dict, const char *group, int len)
{
	char	buffer[3];
	char	*word;

	if (len >= 2 && group[len - 2] != '0')
	{
		buffer[0] = group[len - 2];
		buffer[1] = '0';
		buffer[2] = '\0';
		word = fetch_tens_word(dict, buffer);
		if (word)
		{
			print_tens_and_units(dict, word, group, len);
		}
	}
	else if (len >= 1 && group[len - 1] != '0')
	{
		buffer[0] = group[len - 1];
		buffer[1] = '\0';
		word = fetch_tens_word(dict, buffer);
		if (word)
			write(1, word, ft_strlen(word));
	}
}