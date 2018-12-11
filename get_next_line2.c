/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 19:08:57 by lgrudler          #+#    #+#             */
/*   Updated: 2018/12/11 15:26:32 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(const int fd, char **line)
{
	static char *str = NULL;
	int ret;
	char buf[BUFF_SIZE + 1];
	char *temp;
	int i;

	i = 0;
	ret = 1;
	temp = str;
	if (fd == -1 || line == NULL)
		return (-1);
	while (ret > 0)
	{
		if ((str = ft_strchr(temp, '\n')) != NULL)
		{
			*line = ft_strdup(str);
/*			while (str[i] != '\n')
				i++;
			str = str + i + 1;
*/			return (1);
		}
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		temp = str;
		if (!(str = ft_strjoin(temp, buf)))
			return (-1);
		free(temp);
	}
	return (0);
}
