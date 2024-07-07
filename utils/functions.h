/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:15:28 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 03:50:19 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <stddef.h>

/*
** ft_strcpy
** Copies the string pointed to by src, including the terminating null byte, to the buffer pointed to by dest.
**
** Parameters:
** - dest: pointer to the destination array where the content is to be copied.
** - src: string to be copied.
**
** Returns:
** - A pointer to the destination string dest.
**
** ft_strcpy
** Copie la chaîne pointée par src, y compris l'octet nul de fin, dans le buffer pointé par dest.
**
** Paramètres :
** - dest : pointeur vers le tableau de destination où le contenu doit être copié.
** - src : chaîne à copier.
**
** Retourne :
** - Un pointeur vers la chaîne de destination dest.
*/
char	*ft_strcpy(char *dest, const char *src);

/*
** ft_strncpy
** Copies up to n characters from the string pointed to by src to dest.
** If the length of src is less than n, the remainder of dest will be padded with null bytes.
**
** Parameters:
** - dest: pointer to the destination array where the content is to be copied.
** - src: string to be copied.
** - n: maximum number of characters to be copied from src.
**
** Returns:
** - A pointer to the destination string dest.
**
** ft_strncpy
** Copie jusqu'à n caractères de la chaîne pointée par src vers dest.
** Si la longueur de src est inférieure à n, le reste de dest sera rempli avec des octets nuls.
**
** Paramètres :
** - dest : pointeur vers le tableau de destination où le contenu doit être copié.
** - src : chaîne à copier.
** - n : nombre maximum de caractères à copier depuis src.
**
** Retourne :
** - Un pointeur vers la chaîne de destination dest.
*/
char	*ft_strncpy(char *dest, const char *src, int n);

/*
** ft_strcmp
** Compares the two strings str1 and str2.
**
** Parameters:
** - str1: the first string to be compared.
** - str2: the second string to be compared.
**
** Returns:
** - An integer less than, equal to, or greater than zero if str1 is found, respectively, to be less than, to match, or be greater than str2.
**
** ft_strcmp
** Compare les deux chaînes str1 et str2.
**
** Paramètres :
** - str1 : la première chaîne à comparer.
** - str2 : la deuxième chaîne à comparer.
**
** Retourne :
** - Un entier inférieur, égal ou supérieur à zéro si str1 est respectivement inférieure, égale ou supérieure à str2.
*/
int		ft_strcmp(const char *str1, const char *str2);

/*
** ft_strlen
** Computes the length of the string src up to, but not including the terminating null byte.
**
** Parameters:
** - src: the string whose length is to be computed.
**
** Returns:
** - The number of characters in the string pointed to by src.
**
** ft_strlen
** Calcule la longueur de la chaîne src jusqu'à, mais sans inclure l'octet nul de fin.
**
** Paramètres :
** - src : la chaîne dont la longueur doit être calculée.
**
** Retourne :
** - Le nombre de caractères dans la chaîne pointée par src.
*/
int		ft_strlen(const char *src);

/*
** ft_strdup
** Returns a pointer to a new string which is a duplicate of the string src.
** Memory for the new string is obtained with malloc, and can be freed with free.
**
** Parameters:
** - src: the string to duplicate.
**
** Returns:
** - A pointer to the duplicated string, or NULL if insufficient memory was available.
**
** ft_strdup
** Renvoie un pointeur vers une nouvelle chaîne qui est un duplicata de la chaîne src.
** La mémoire pour la nouvelle chaîne est obtenue avec malloc et peut être libérée avec free.
**
** Paramètres :
** - src : la chaîne à dupliquer.
**
** Retourne :
** - Un pointeur vers la chaîne dupliquée, ou NULL si la mémoire disponible est insuffisante.
*/
char	*ft_strdup(const char *src);

/*
** ft_strchr
** Locates the first occurrence of c (converted to a char) in the string pointed to by str.
** The terminating null character is considered part of the string.
**
** Parameters:
** - str: the string to be scanned.
** - c: the character to be located.
**
** Returns:
** - A pointer to the first occurrence of the character c in the string, or NULL if the character is not found.
**
** ft_strchr
** Localise la première occurrence de c (converti en caractère) dans la chaîne pointée par str.
** Le caractère nul de fin est considéré comme faisant partie de la chaîne.
**
** Paramètres :
** - str : la chaîne à analyser.
** - c : le caractère à localiser.
**
** Retourne :
** - Un pointeur vers la première occurrence du caractère c dans la chaîne, ou NULL si le caractère n'est pas trouvé.
*/
char	*ft_strchr(const char *str, char c);

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
char	*ft_strcat(char *dest, const char *src);

/*
** ft_isdigit
** Checks if the passed character is a decimal digit character.
**
** Parameters:
** - c: the character to be checked.
**
** Returns:
** - Non-zero value if c is a digit, zero otherwise.
**
** ft_isdigit
** Vérifie si le caractère passé est un chiffre décimal.
**
** Paramètres :
** - c : le caractère à vérifier.
**
** Retourne :
** - Une valeur non nulle si c est un chiffre, zéro sinon.
*/
int		ft_isdigit(int c);

/*
** ft_bzero
** Sets the first n bytes of the memory area pointed to by s to zero.
**
** Parameters:
** - s: pointer to the memory area to be zeroed.
** - n: number of bytes to set to zero.
**
** ft_bzero
** Met à zéro les n premiers octets de la zone mémoire pointée par s.
**
** Paramètres :
** - s : pointeur vers la zone mémoire à mettre à zéro.
** - n : nombre d'octets à mettre à zéro.
*/
void	ft_bzero(void *s, size_t n);

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
int		ft_atoi(const char *str);

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
char	*trim(char *str);

#endif