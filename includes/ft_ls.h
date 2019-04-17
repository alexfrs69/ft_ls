/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:04:58 by afrancoi          #+#    #+#             */
/*   Updated: 2019/04/17 22:47:07 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

/*
#define T_UNKNOWN 0
#define T_BLK 1
#define T_CHR 2
#define T_DIR 3
#define T_FIFO 4
#define T_LNK 5
#define T_REG 6
#define T_SOCK 7 */

/*
** Valid args options (char)
*/
#define OPT_a 1
#define OPT_G 2
#define OPT_l 4
#define OPT_R 8


#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct		stat t_stat;
typedef struct		dirent t_dirent;

typedef struct		s_file {
	t_stat			stat;
	t_dirent		file;
	struct s_file	*next;
}					t_file;

int		save_file(char *path);
t_file	*add_node(t_file *start, struct dirent *file);
t_file	*get_start_node(void);
void	display_list(t_file *start);
int		fill_node(t_file *elem, t_dirent *file);
int		parse_args(int argc, char **argv, int *decal);
#endif
