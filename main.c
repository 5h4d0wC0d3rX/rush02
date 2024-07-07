/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nerfy <nerfy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:10:06 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 03:44:10 by nerfy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Main file for the number-to-words conversion program.
** Fichier principal pour le programme de conversion de nombres en mots.
*/

#include <unistd.h>
#include "utils/dictionary/dictionary.h"
#include "utils/main_helpers/main_helpers1.h"
#include "utils/main_helpers/main_helpers2.h"
#include "utils/main_helpers/main_helpers3.h"
#include "utils/functions.h"

#define DEFAULT_DICT "dict/en.dict"
#define BUFFER_SIZE 1024

/*
** Main function of the program.
** Fonction principale du programme.
**
** This function handles the overall flow of the program:
** - It sets the default dictionary filename.
** - It initializes the number buffer.
** - It processes the command-line arguments.
** - It loads the dictionary from the specified file.
** - It converts the number to words and prints the result.
** - It frees the allocated memory for the dictionary.
**
** Cette fonction gère le flux global du programme :
** - Elle définit le nom de fichier du dictionnaire par défaut.
** - Elle initialise le tampon de nombre.
** - Elle traite les arguments de la ligne de commande.
** - Elle charge le dictionnaire à partir du fichier spécifié.
** - Elle convertit le nombre en mots et imprime le résultat.
** - Elle libère la mémoire allouée pour le dictionnaire.
**
** @param argc The number of command-line arguments. / Le nombre d'arguments de la ligne de commande.
** @param argv The array of command-line arguments. / Le tableau d'arguments de la ligne de commande.
** @return 0 on success, 1 on error. / 0 en cas de succès, 1 en cas d'erreur.
*/
int	main(int argc, char **argv)
{
	const char		*dict_filename;
	char			number[BUFFER_SIZE];
	t_dict_entry	*dict;

	dict_filename = DEFAULT_DICT;
	ft_bzero(number, BUFFER_SIZE);
	if (handle_args(argc, argv, number, &dict_filename))
		return (1);
	dict = load_dictionary(dict_filename);
	if (!dict)
	{
		print_error("Dict Error\n");
		return (1);
	}
	convert_number_to_words(dict, number);
	free_dictionary(dict);
	return (0);
}
