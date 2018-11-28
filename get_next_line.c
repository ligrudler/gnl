/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 20:50:38 by lgrudler          #+#    #+#             */
/*   Updated: 2018/11/28 21:30:04 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

// Test fcts lire une ligne
char *readline(int fd, char *str)
{
	char buf[BUFF_SIZE + 1];
	char *temp;
	int ret;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		temp = str;
		str = ft_strjoin(temp, buf);
		if (str == NULL)
 			return (NULL);
	}
	return (str);
}

int	get_next_line(const int fd, char **line)
{
	static char *str;
	char *temp;
	int i;

	i = 0;
	if (fd == -1)
		return (-1);
	temp = str;
	str = readline(fd, temp);
	if (str[i])
	{
		while (str[i] != '\n')
			i++;
		*line = ft_strsub(str, 0, i);
		if (*line == NULL)	
			return (-1);
		str = &str[i + 1];
	}
	return (0);
}

