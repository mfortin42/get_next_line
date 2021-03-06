/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 13:05:10 by mfortin           #+#    #+#             */
/*   Updated: 2016/02/04 14:28:00 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd;

	fd = 0;
	while (1)
	{
		get_next_line(fd, &line);
		if (line)
		{
			printf("%s\n", line);
			line = NULL;
		}
	}
	return (0);
}
