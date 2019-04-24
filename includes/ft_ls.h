/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:04:58 by afrancoi          #+#    #+#             */
/*   Updated: 2019/04/24 04:44:58 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

/*
** Args options
*/

#define OPT_A 1
#define OPT_G 2
#define OPT_L 4
#define OPT_R 8

#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/syslimits.h>

typedef struct		stat t_stat;
typedef struct		dirent t_dirent;

typedef struct		s_file {
	t_stat			stat;
	t_dirent		file;
	struct s_file	*next;
}					t_file;

typedef struct		s_queue {
	char			path[PATH_MAX];
	struct s_queue	*next;
}					t_queue;

/*
** File struct system
*/

t_file	*add_node(t_file *start, struct dirent *file);
t_file	*get_start_node(void);
void	display_list(t_file *start);
int		fill_node(t_file *elem, t_dirent *file);

/*
** Queue struct system
*/

void	queue_file(t_queue *queue, int listopt);
void	queue_fill(t_queue *elem, char *path);
t_queue *get_queue_node(void);
t_queue	*queue_add(t_queue *start, char *path);
void	display_queue(t_queue *queue);

/*
** Parser
*/
int		parse_args(int argc, char **argv, int *decal);

/*
** Router system
*/
void	route_to(t_queue *queu, int listopt);

/*
** Options
*/
void	options_recursive(t_queue *queue, int listoptions);

#endif
