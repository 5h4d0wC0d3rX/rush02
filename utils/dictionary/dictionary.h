/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 02:30:38 by nerfy             #+#    #+#             */
/*   Updated: 2024/07/07 17:04:49 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICTIONARY_H
# define DICTIONARY_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../functions.h"

typedef struct s_dict_entry
{
	const char			*name;
	char				*number;
	char				*word;
	struct s_dict_entry	*next;
}	t_dict_entry;

typedef struct s_line_info
{
	char	*line;
	size_t	len;
	size_t	capacity;
}	t_line_info;

t_dict_entry	*load_dictionary(const char *filename);
char			*get_word(t_dict_entry *dict, const char *number);
void			free_dictionary(t_dict_entry *dict);

#endif