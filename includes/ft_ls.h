/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 13:04:58 by afrancoi          #+#    #+#             */
/*   Updated: 2019/03/28 18:13:45 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#define T_UNKNOWN 0
#define T_BLK 1
#define T_CHR 2
#define T_DIR 3
#define T_FIFO 4
#define T_LNK 5
#define T_REG 6
#define T_SOCK 7

#include <dirent.h>

typedef struct		s_file {
	char			name[256];
	int				type;
	int				perm_user;
	int				perm_grp;
	int				perm_oth;
	struct s_file *next;
}					t_file;

int		get_files(char *path);
t_file	*add_node(t_file *start, struct dirent *file);

#endif
