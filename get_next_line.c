/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfortin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 13:31:17 by mfortin           #+#    #+#             */
/*   Updated: 2015/12/18 13:32:41 by mfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	**ft_new_fd(char **tmp, int fd)
{
	char	**new_tmp;
	int		i;

	i = -1;
	if ((new_tmp = (char **)malloc(sizeof(char *) * (fd + 2))) == NULL)
		return (NULL);
	while (++i <= fd)
	{
		if (tmp != NULL && tmp[i] != '\0')
			new_tmp[i] = ft_strdup(tmp[i]);
		else
			new_tmp[i] = ft_strnew(0);
	}
	new_tmp[i] = NULL;
	return (new_tmp);
}

static int	ft_cnt_chr(char *tmp)
{
	unsigned int i;

	i = 0;
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	return (i);
}

int			get_next_line(int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static char		**tmp = NULL;
	int				vr;

	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0)
		return (-1);
	if (tmp == NULL || tmp[fd] == '\0')
		tmp = ft_new_fd(tmp, fd);
	while (!(ft_strchr(tmp[fd], '\n')) && (vr = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[vr] = '\0';
		tmp[fd] = ft_strjoin(tmp[fd], buff);
	}
	*line = ft_strsub(tmp[fd], 0, ft_cnt_chr(tmp[fd]));
	if (ft_strchr(tmp[fd], '\n'))
	{
		tmp[fd] = ft_strchr(tmp[fd], '\n') + 1;
		return (1);
	}
	tmp[fd] += ft_cnt_chr(tmp[fd]);
	return (vr ? 1 : 0);
}
