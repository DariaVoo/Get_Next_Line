/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 10:53:12 by snorcros          #+#    #+#             */
/*   Updated: 2019/09/18 20:15:41 by snorcros         ###   ########.fr       */
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
		s = NULL;
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
	ft_strncpy(buf, dst, i);
	return (buf);
}

int			get_next_line(const int fd, char **line)
{
	int			rd;
	static char	*descriptors[10240];
	char		buf[BUFF_SIZE + 1];

	if (fd < 0)
		return (-1);
	buf[BUFF_SIZE] = '\0';
	if (!descriptors[fd]) 
		descriptors[fd] = ft_strnew(1);
	while (!ft_strchr(descriptors[fd], '\n')
			&& (rd = read(fd, buf, BUFF_SIZE)) != 0)
 	{
		if (rd < 0)
			return (-1);
		descriptors[fd] = ft_strjoin(descriptors[fd], buf);
	}
	*line = ft_first_str(descriptors[fd]);
	if (!*line && !rd)
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
//	printf("\nFirst Descriptors %s \n", descriptors[fd]);
//	printf("\n\nNow i read: %s\n\n", buf);
// printf("%s", *line);
//	printf("\nOut Descriptors %s \n", descriptors[fd]);
	int		fd1, fd2, fd;
	int		i;
	char	*arr = NULL;

	i = 1;
	fd1 = open("f1", O_RDONLY);
	fd2 = open("f2", O_RDONLY);
		i = get_next_line(fd1, &arr);
//		printf("\n\nInt %d\n", i);
		printf("%s\n\n", arr);
		i = get_next_line(fd2, &arr);
//		printf("\n\nInt %d\n", i);
		printf("%s\n", arr);
		i = get_next_line(fd1, &arr);
//		printf("\n\nInt %d\n", i);
		printf("%s\n", arr);

		i = get_next_line(fd2, &arr);
//		printf("\n\nInt %d\n", i);
		printf("%s\n\n", arr);
		i = get_next_line(fd1, &arr);
//		printf("\n\nInt %d\n", i);
		printf("%s\n", arr);
		i = get_next_line(fd2, &arr);
//		printf("\n\nInt %d\n", i);
		printf("%s\n\n", arr);

	fd = open("Libft/ft_strjoin.c", O_RDONLY);
	while ((i = get_next_line(fd, &arr)) != 0)
	{
//		printf("Int %d\n", i);
		printf("%s\n", arr);
//		printf("\n");
	}
	
	close(fd1);
	close(fd2);
	close(fd);
	return (0);
}
*/
