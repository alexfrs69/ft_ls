/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:04:58 by afrancoi          #+#    #+#             */
/*   Updated: 2019/05/25 03:20:45 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

/*
** Args options
*/

# define OPT_A 1
# define OPT_G 2
# define OPT_L 4
# define OPT_R 8

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
	ino_t				ino;
	__uint8_t			type;
	char				name[1024];
	int					infodir;
	char				path[PATH_MAX + 1];
	struct s_file		*next;
}						t_file;

typedef struct			s_queue {
	char				path[PATH_MAX + 1];
	struct s_queue		*next;
}						t_queue;

/*
** File struct system
*/

t_file					*add_node(t_file *start, t_dirent *dirent, char *path);
t_file					*init_node(t_file *start, t_dirent *dirent, char *path);
void					list_del(t_file **start);
void					display_list(t_file *start, char *path);
int						fill_node(t_file *elem, t_dirent *dirent, char *path);
int						save_file(char *path, int listoptions);

/*
** Queue struct system
*/
void					queue_file(t_queue *queue, int listopt);
void					queue_fill(t_queue *elem, char *path);
t_queue					*get_queue_node(void);
t_queue					*queue_add(t_queue *start, char *path);
t_queue					*init_queue(t_queue *start, char *path);
void					queue_del(t_queue **start);
void					display_queue(t_queue *queue);

/*
** Parser
*/
int						parse_args(int argc, char **argv, int *decal);

/*
** Router system
*/
void					route_to(t_queue *queu, int listopt);
char					*join_path(char *path, char *name);

/*
** Options
*/
int						options_recursive(t_queue *queue, int listoptions);

/*
** Error
*/
void					ft_error(int errnb, char *path);
#endif
