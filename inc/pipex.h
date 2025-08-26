/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveil <eveil@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 10:50:55 by lud-adam          #+#    #+#             */
/*   Updated: 2025/08/26 15:58:01 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_fd
{
	int		first_pipe[2];
	int		second_pipe[2];
	int		infile;
	int		outfile;

}			t_fd;

typedef struct s_data
{
	size_t	i;
	int		count_command;
	int		pid;
	int		argc;
	int		status;
	char	*pathname;
	char	*path_bin;
	char	*path;
	char	**commands;
	char	**all_paths;
	char	**argv;
	char	**envp;
	char	buf[4096];
	bool	path_is_empty;
	t_fd	fd;
}			t_data;

char		**get_path_bins(t_data *data, char *envp[]);

void		exec_command(t_data *data, char *envp[], char *command);
void		free_and_close_all(t_data *data);
void		pipeline(t_data *data);

// Utils
char		*str_two_join(char *str, char *str_2, char *str_3);
char		**free_double_array(char **strs);

#endif
