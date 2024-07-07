/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 00:36:24 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 03:40:49 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Header file for string utility functions.
** Fichier d'en-tête pour les fonctions utilitaires de chaînes de caractères.
** 
** This file declares functions for common string operations such as
** calculating length, copying, comparing, and duplicating strings.
** Ce fichier déclare des fonctions pour les opérations courantes sur les chaînes
** de caractères telles que calculer la longueur, copier, comparer et dupliquer des chaînes.
*/

#ifndef STRING_UTILS_H
# define STRING_UTILS_H

/*
** Calculate the length of a string.
** Calculer la longueur d'une chaîne de caractères.
** 
** @param src The input string. / La chaîne d'entrée.
** @return The length of the string. / La longueur de la chaîne.
*/
int		ft_strlen(const char *src);

/*
** Copy a string.
** Copier une chaîne de caractères.
** 
** @param dest The destination buffer. / Le tampon de destination.
** @param src The source string to copy. / La chaîne source à copier.
** @return A pointer to the destination string. / Un pointeur vers la chaîne de destination.
*/
char	*ft_strcpy(char *dest, const char *src);

/*
** Copy a specified number of characters from a string.
** Copier un nombre spécifié de caractères d'une chaîne.
** 
** @param dest The destination buffer. / Le tampon de destination.
** @param src The source string to copy. / La chaîne source à copier.
** @param n The number of characters to copy. / Le nombre de caractères à copier.
** @return A pointer to the destination string. / Un pointeur vers la chaîne de destination.
*/
char	*ft_strncpy(char *dest, const char *src, int n);

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
int		ft_strcmp(const char *str1, const char *str2);

/*
** Duplicate a string.
** Dupliquer une chaîne de caractères.
** 
** @param src The source string to duplicate. / La chaîne source à dupliquer.
** @return A pointer to the newly allocated string, or NULL if memory allocation fails.
** Un pointeur vers la nouvelle chaîne allouée, ou NULL si l'allocation de mémoire échoue.
*/
char	*ft_strdup(const char *src);

#endif
