/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:32:44 by lud-adam          #+#    #+#             */
/*   Updated: 2025/08/26 10:31:29 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

static char	*get_path(t_data *data, char *envp[]);

char	**get_path_bins(t_data *data, char *envp[])
{
	char	*path;
	char	**all_paths_bins;

	path = get_path(data, envp);
	if (!path)
		return (NULL);
	all_paths_bins = ft_split(path, ':');
	if (!all_paths_bins)
		return (NULL);
	return (all_paths_bins);
}

static char	*get_path(t_data *data, char *envp[])
{
	int	i;

	i = 0;
	while (envp && envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			if (ft_strlen(&envp[i][5]) > 1)
				return (&envp[i][5]);
			else
				data->path_is_empty = true;
		}
		i++;
	}
	return (NULL);
}
