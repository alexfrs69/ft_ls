/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:04:58 by afrancoi          #+#    #+#             */
/*   Updated: 2019/06/17 04:02:04 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

/*
** Args options
*/

# define OPT_A		1
# define OPT_L		2
# define OPT_R		4
# define OPT_T		8
# define OPT_REV	16
# define OPTS		32

# include <dirent.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <sys/types.h>

typedef struct stat		t_stat;
typedef struct dirent	t_dirent;

typedef struct			s_file {
	t_stat				stat;
	char				name[1024];
	int					dir;
	char				path[PATH_MAX + 1];
	struct s_file		*next;
}						t_file;

typedef int (*t_cmp)(t_file*, t_file*);

/*
** File struct system
*/

t_file					*add_node(t_file *start, t_dirent *dirent, t_stat *stat, char *path);
t_file					*init_node(t_file *start, t_dirent *dirent, t_stat *stat, char *path);
void					list_del(t_file **start);
void					display_list(t_file *start, char *path, int opts);
void					display_file(t_file *list, int opts);
int						fill_node(t_file *elem, t_dirent *dirent, t_stat *stat, char *path);
int						save_dir(char *path, int listoptions);
void					save_list_dir(t_file *list, int listopts);

/*
** Parser
*/
int						parse_args(int argc, char **argv, int *decal);

/*
** Router system
*/
void					route_to(t_file *list, int listopt);
char					*join_path(char *path, char *name);

/*
** Options
*/
int						options_recursive(t_file *queue, int listoptions);
void					display_opt_l(t_file *list, char *path, int opts);
void					display_l_wrapper(t_file *elem);
int						get_total_size(t_file *list);
int						is_link_dir(char *path);

/*
** Error
*/
void					ft_error(int errnb, char *path);


/*
** Sorting functions
*/
void					ft_mergesort(t_file **start, int opts);
int						check_strcmp(t_file *a, t_file *b);
int						check_time(t_file *a, t_file *b);
t_cmp					ft_getcmp(int opts);
#endif
