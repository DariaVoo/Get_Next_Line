/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 10:53:12 by snorcros          #+#    #+#             */
/*   Updated: 2019/09/16 21:21:37 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <stdio.h>
//#include <fcntl.h>
static char	*ft_del_line(char *s)
{
	char	*buf;

	buf = ft_strchr(s, '\n');
	if (!buf)
		return (NULL);
	buf++;
	buf = ft_strdup(buf);
	if (buf)
	{
		free(s);
		return (buf);
	}
	return (NULL);
}

static char	*ft_first_str(char *dst)
{
	size_t	i;
	char	*buf;

	i = 0;
	if (!*dst)
		return (NULL);
	while (dst[i] != '\0' && dst[i] != '\n')
		i++;
	buf = ft_strnew(i);
	if (!buf)
		return (NULL);
	ft_strlcat(buf, dst, i);
	return (buf);
}

int			get_next_line(const int fd, char **line)
{
	int			rd;
	static char	*descriptors[10240];
	char		buf[BUFF_SIZE];

	if (fd < 0)
		return (-1);
	if (!descriptors[fd]) 
		descriptors[fd] = ft_strnew(0);
	rd = read(fd, buf, BUFF_SIZE);
	if (rd <= 0)
		return (-1);
	while (!ft_strchr(descriptors[fd], '\n'))
	{
		descriptors[fd] = ft_strjoin(descriptors[fd], buf);
		rd = read(fd, buf, BUFF_SIZE);
	}
	*line = ft_first_str(descriptors[fd]);
	if (!*line)
	{
		free(descriptors[fd]);
		return (0);
	}
	descriptors[fd] = ft_del_line(descriptors[fd]);
	return (1);
}
/*
int		main(void)
{
	int		fd;
	int		i;
	char	*arr = NULL;

	fd = open("test", O_RDONLY);
	i = get_next_line(fd, &arr);
	printf("Int %d\n", i);
	printf("%s", arr);
//	i = get_next_line(fd, &arr);
//	printf("Int %d\n", i);
//	printf("%s", arr);
	close(fd);
	return (0);
}*/
