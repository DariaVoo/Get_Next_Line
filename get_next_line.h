/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snorcros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 10:54:04 by snorcros          #+#    #+#             */
/*   Updated: 2019/09/18 19:07:59 by snorcros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "./libft/includes/libft.h"

# define BUFF_SIZE 500
# define FD_MAX    10240

int		get_next_line(const int fd, char **line);

#endif
