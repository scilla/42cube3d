/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 17:40:10 by scilla            #+#    #+#             */
/*   Updated: 2021/03/28 17:40:16 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		start_music(void)
{
	int		pid;
	char	**args;

	pid = fork();
	if (pid < 0)
	{
		printf("Music process couldn't be forked :(");
		return (-1);
	}
	else if (pid == 0)
	{
		if (MAC_OS)
		{
			args = ft_split("afplay audio/music.wav", ' ');
			execv("/usr/bin/afplay", args);
		}
		else
		{
			args = ft_split("aplay -q audio/music.wav", ' ');
			execv("/usr/bin/aplay", args);
		}
	}
	return (0);
}
