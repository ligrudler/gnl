/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:20:12 by lgrudler          #+#    #+#             */
/*   Updated: 2018/12/16 16:59:53 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*str;
	int		l1;
	int		l2;

	l1 = (s1) ? ft_strlen(s1) : 0;
	l2 = (s2) ? ft_strlen(s2) : 0;
	if (!(str = (char *)malloc(sizeof(char) * (l1 + l2 + 1))))
		return (NULL);
	ft_memcpy(str, s1, l1);
	ft_memcpy(str + l1, s2, l2);
	str[l1 + l2] = '\0';
	return (str);
}

int		wallah(char **str, char **line, int ret)
{
	char *tmp;

	if (*str && (tmp = ft_strchr(*str, '\n')) != NULL)
	{
		tmp[0] = '\0';
		*line = ft_strdup(*str);
		tmp = ft_strdup(tmp + 1);
		free(*str);
		*str = tmp;
		if (ret <= BUFF_SIZE && tmp[0] == '\0')
		{
			free(*str);
			*str = NULL;
		}
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str = NULL;
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char		*temp;

	if (fd <= -1 || line == NULL)
		return (-1);
	if (wallah(&str, line, 1))
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		temp = str;
		if (!(str = ft_strjoin_gnl(temp, buf)))
			return (-1);
		free(temp);
		if (wallah(&str, line, ret))
			return (1);
	}
	if (ret <= -1)
		return (-1);
	if (str != NULL)
	{
		*line = ft_strdup(str);
		free(str);
		str = NULL;
		return (1);
	}
	return (0);
}
