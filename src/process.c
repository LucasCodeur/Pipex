/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eveil <eveil@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 09:25:47 by lud-adam          #+#    #+#             */
/*   Updated: 2025/08/26 17:48:22 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <unistd.h>

static void	launch_command(t_data *data, int read, int write, char *command);
static void	free_and_close(t_data *data);

void	pipeline(t_data *data)
{
	int		read;
	int		i;

	if (data->argc == 4)
	{
		launch_command(data, data->fd.infile, data->fd.outfile, data->argv[2]);
		wait (NULL);
		return ;
	}
	launch_command(data, data->fd.infile, data->fd.first_pipe[1], data->argv[2]);
	close(data->fd.first_pipe[1]);
	read = data->fd.first_pipe[0];
	i = 3;
	while (i < data->argc - 2)
	{
		if (pipe(data->fd.second_pipe) == -1)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}
		launch_command(data, read, data->fd.second_pipe[1], data->argv[i]);
		close(read);
		close(data->fd.second_pipe[1]);
		read = data->fd.second_pipe[0];
		i++;
	}
	launch_command(data, read, data->fd.outfile, data->argv[data->argc - 2]);
	close(read);
}

static void	launch_command(t_data *data, int read, int write, char *command)
{
	data->pid = fork();
	if (data->pid < 0)
	{
		free_and_close_all(data);
		exit(EXIT_FAILURE);
	}
	if (data->pid == 0)
	{
		if (dup2(read, STDIN_FILENO) == -1)
		{
			perror("");
			free_and_close_all(data);
			exit(EXIT_FAILURE);
		}
		if (dup2(write, STDOUT_FILENO) == -1)
		{
			perror("");
			free_and_close_all(data);
			exit(EXIT_FAILURE);
		}
		exec_command(data, data->envp, command);
	}
	free_and_close(data);
}


static void	free_and_close(t_data *data)
{
	free_double_array(data->commands);
	close(data->fd.infile);
}
