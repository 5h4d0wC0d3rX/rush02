/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:48:41 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 03:47:31 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

/* 
** ft_bzero
** This function sets the first n bytes of the memory area pointed to by s to zero.
**
** Parameters:
** - s: pointer to the memory area to be zeroed.
** - n: number of bytes to set to zero.
**
** ft_bzero
** Cette fonction met à zéro les n premiers octets de la zone mémoire pointée par s.
**
** Paramètres :
** - s : pointeur vers la zone mémoire à mettre à zéro.
** - n : nombre d'octets à mettre à zéro.
*/
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n--)
	{
		*ptr++ = 0;
	}
}

/* 
** ft_strchr
** This function locates the first occurrence of c (converted to a char) in the string pointed to by str.
** The terminating null character is considered part of the string.
**
** Parameters:
** - str: pointer to the string to be scanned.
** - c: character to be located.
**
** Return:
** - A pointer to the located character, or NULL if the character does not appear in the string.
**
** ft_strchr
** Cette fonction localise la première occurrence de c (converti en caractère) dans la chaîne pointée par str.
** Le caractère nul de fin est considéré comme faisant partie de la chaîne.
**
** Paramètres :
** - str : pointeur vers la chaîne à analyser.
** - c : caractère à localiser.
**
** Retour :
** - Un pointeur vers le caractère localisé, ou NULL si le caractère n'apparaît pas dans la chaîne.
*/
char	*ft_strchr(const char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	return (0);
}

/* 
** ft_isdigit
** This function checks if the passed character is a decimal digit character.
**
** Parameters:
** - c: character to be checked.
**
** Return:
** - Non-zero value if c is a digit, zero otherwise.
**
** ft_isdigit
** Cette fonction vérifie si le caractère passé est un chiffre décimal.
**
** Paramètres :
** - c : caractère à vérifier.
**
** Retour :
** - Une valeur non nulle si c est un chiffre, zéro sinon.
*/
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
