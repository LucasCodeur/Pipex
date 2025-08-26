/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 15:26:12 by lud-adam          #+#    #+#             */
/*   Updated: 2025/08/26 17:48:19 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

static void	fds_pipes(t_data *data, char *argv[], int argc, char *envp[]);

static void	error_message(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": ", 2);
	perror("");
}

static void	initialize_values(t_data *data, char *argv[], int argc,
		char *envp[])
{
	ft_bzero(data, sizeof(t_data));
	data->path_is_empty = false;
	data->fd.outfile = -1;
	data->fd.infile = -1;
	data->fd.first_pipe[0] = -1;
	data->fd.first_pipe[1] = -1;
	data->argv = argv;
	data->envp = envp;
	data->argc = argc;
	fds_pipes(data, argv, argc, envp);
}

static void	fds_pipes(t_data *data, char *argv[], int argc, char *envp[])
{
	data->fd.outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (data->fd.outfile == -1)
		error_message(argv[4]);
	data->fd.infile = open(argv[1], O_RDONLY, 0644);
	if (data->fd.infile == -1)
	{
		error_message(argv[2]);
		close(data->fd.outfile);
		exit(EXIT_FAILURE);
	}
	if (pipe(data->fd.first_pipe) == -1)
	{
		perror("");
		close(data->fd.outfile);
		close(data->fd.infile);
		exit(EXIT_FAILURE);
	}
	data->all_paths = get_path_bins(data, envp);
	if (!data->all_paths)
		data->all_paths = NULL;
}

static void	handle_return_of_status(t_data data)
{
	while (waitpid(data.pid, &data.status, 0) > 0)
	{
		if (data.status == 127)
			exit(127);
		else if (data.status == -1)
			exit(EXIT_FAILURE);
		else if (WIFEXITED(data.status))
			exit(WEXITSTATUS(data.status));
		else if (WIFSIGNALED(data.status))
			exit(128 + WTERMSIG(data.status));
		else
			return ;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc < 3)
		return (1);
	initialize_values(&data, argv, argc, envp);	
	pipeline(&data);
	free_and_close_all(&data);
	handle_return_of_status(data);
	return (0);
}
