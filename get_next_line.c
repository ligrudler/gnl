/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 20:50:38 by lgrudler          #+#    #+#             */
/*   Updated: 2018/12/03 22:50:50 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char *readline(int fd, char *str)
{
	char buf[BUFF_SIZE + 1];
	char *temp;
	int ret;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		temp = str;
		free(str);
		if (!(str = ft_strjoin(temp, buf)))
 			return (NULL);
	}
	return (str);
}

int	get_next_line(const int fd, char **line)
{
	static char *str;
	char *temp;
	int i;
	int j;

	j = 0;
	i = 0;
	if (fd == -1 || line == NULL)
		return (-1);
	if (!(str))
		if (!(str = ft_strnew(100000)))
				return (-1);
	temp = str;
	str = readline(fd, temp);
	if (str[i])
	{
		while (str[i] != '\n' && str[i] != '\0')
			i++;
		if (i == 0)
			*line = ft_strdup(" ");
		if (!(*line = ft_strsub(str, 0, i)))
			return (-1);
		str = &str[i + 1];
		return (1);
	}
	return (0);
}

