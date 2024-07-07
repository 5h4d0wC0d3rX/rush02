/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:07:15 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 03:52:17 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "functions.h"

/*
** ft_strcat
** Concatenates the string pointed to by src to the end of the string pointed to by dest.
** The terminating null character of dest is overwritten by the first character of src, and a new null character is appended at the end of the new string.
**
** Parameters:
** - dest: the destination string.
** - src: the source string to be appended.
**
** Returns:
** - A pointer to the resulting string dest.
**
** ft_strcat
** Concatène la chaîne pointée par src à la fin de la chaîne pointée par dest.
** Le caractère nul de fin de dest est écrasé par le premier caractère de src, et un nouveau caractère nul est ajouté à la fin de la nouvelle chaîne.
**
** Paramètres :
** - dest : la chaîne de destination.
** - src : la chaîne source à ajouter.
**
** Retourne :
** - Un pointeur vers la chaîne résultante dest.
*/
char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

/*
** ft_atoi
** Converts the initial portion of the string pointed to by str to int.
**
** Parameters:
** - str: the string to be converted.
**
** Returns:
** - The converted value.
**
** ft_atoi
** Convertit la portion initiale de la chaîne pointée par str en entier.
**
** Paramètres :
** - str : la chaîne à convertir.
**
** Retourne :
** - La valeur convertie.
*/
int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r')
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

/*
** trim
** Removes leading and trailing white spaces from the string str.
**
** Parameters:
** - str: the string to be trimmed.
**
** Returns:
** - A pointer to the trimmed string.
**
** trim
** Supprime les espaces blancs en début et en fin de chaîne de la chaîne str.
**
** Paramètres :
** - str : la chaîne à nettoyer.
**
** Retourne :
** - Un pointeur vers la chaîne nettoyée.
*/
char	*trim(char *str)
{
	char	*end;

	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r')
		str++;
	if (*str == 0)
		return (str);
	end = str + ft_strlen(str) - 1;
	while (end > str && (*end == ' '
			|| *end == '\t' || *end == '\n' || *end == '\r'))
		end--;
	end[1] = '\0';
	return (str);
}
