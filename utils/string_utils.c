/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:48:06 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 03:41:23 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Implementation of string utility functions.
** Implémentation des fonctions utilitaires de chaînes de caractères.
** 
** These functions perform common string operations such as calculating length,
** copying, comparing, and duplicating strings.
** Ces fonctions effectuent des opérations courantes sur les chaînes telles que
** calculer la longueur, copier, comparer et dupliquer des chaînes.
*/

#include "functions.h"
#include <stdlib.h>

/*
** Calculate the length of a string.
** Calculer la longueur d'une chaîne de caractères.
** 
** @param src The input string. / La chaîne d'entrée.
** @return The length of the string. / La longueur de la chaîne.
*/
int	ft_strlen(const char *src)
{
	int	n;

	n = 0;
	while (src[n])
		n++;
	return (n);
}

/*
** Copy a string.
** Copier une chaîne de caractères.
** 
** @param dest The destination buffer. / Le tampon de destination.
** @param src The source string to copy. / La chaîne source à copier.
** @return A pointer to the destination string. / Un pointeur vers la chaîne de destination.
*/
char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
** Copy a specified number of characters from a string.
** Copier un nombre spécifié de caractères d'une chaîne.
** 
** @param dest The destination buffer. / Le tampon de destination.
** @param src The source string to copy. / La chaîne source à copier.
** @param n The number of characters to copy. / Le nombre de caractères à copier.
** @return A pointer to the destination string. / Un pointeur vers la chaîne de destination.
*/
char	*ft_strncpy(char *dest, const char *src, int n)
{
	int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*
** Compare two strings.
** Comparer deux chaînes de caractères.
** 
** @param str1 The first string to compare. / La première chaîne à comparer.
** @param str2 The second string to compare. / La deuxième chaîne à comparer.
** @return An integer less than, equal to, or greater than zero if str1 is found,
** respectively, to be less than, to match, or be greater than str2.
** Un entier inférieur, égal ou supérieur à zéro si str1 est respectivement
** trouvé inférieur, égal ou supérieur à str2.
*/
int	ft_strcmp(const char *str1, const char *str2)
{
	int	i;

	i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

/*
** Duplicate a string.
** Dupliquer une chaîne de caractères.
** 
** @param src The source string to duplicate. / La chaîne source à dupliquer.
** @return A pointer to the newly allocated string, or NULL if memory allocation fails.
** Un pointeur vers la nouvelle chaîne allouée, ou NULL si l'allocation de mémoire échoue.
*/
char	*ft_strdup(const char *src)
{
	char	*a;
	int		len;
	int		i;

	len = ft_strlen(src);
	a = malloc((len * sizeof(char)) + 1);
	if (a == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		a[i] = src[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}