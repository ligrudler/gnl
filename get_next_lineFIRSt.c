/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_lineFIRSt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 20:50:38 by lgrudler          #+#    #+#             */
/*   Updated: 2018/12/16 16:24:21 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>

char		*readline(int fd, char *pouet)
{
	char	buf[BUFF_SIZE + 1];
	char	*temp;
	int		ret;

	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
	{
		buf[ret] = '\0';
		temp = pouet;
		if (!(pouet = ft_strjoin(temp, buf)))
			return (NULL);
		free(temp);
	}
	if (ret == -1)
		return (NULL);
	return (pouet);
}

int			get_next_line(const int fd, char **line)
{
	static char *str = NULL;
	char		*temp;
	int			i;

	i = 0;
	if (fd == -1 || line == NULL)
		return (-1);
	if (!(str))
		if (!(str = ft_strnew(1)))
			return (-1);
	temp = str;
	if (!(str = readline(fd, temp)))
		return (-1);
	if (str[i])
	{
		while (str[i] != '\n' && str[i] != '\0')
			i++;
		if (i == 0)
			*line = ft_strdup("");
		if (!(*line = ft_strsub(str, 0, i)))
			return (-1);
		str = str + i + 1;
		return (1);
	}
	if (!(*line = ft_strdup("")))
		return(-1);
//	free(str);
	return (0);
}
