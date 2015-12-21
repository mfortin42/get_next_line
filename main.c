/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 13:05:10 by mfortin           #+#    #+#             */
/*   Updated: 2015/12/18 15:34:17 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd;

//	(void)ac;
	fd = 0;
//	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
	}
	return (0);
}
