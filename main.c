/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrudler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:26:02 by lgrudler          #+#    #+#             */
/*   Updated: 2018/11/29 17:42:22 by lgrudler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void ft_exit(const char *str)
{
	if (str)
		ft_putendl(str);
	exit(1);
}

int main(int argc, char **argv)
{
	char *line;
	int fd;
	int code;
	int len;
	int i;

	i = 1;
	printf("BUFF_SIZE = %d\n", BUFF_SIZE);
	printf("Premier FD\n\n");
	while (i < argc)
	{
		if ((fd = open(argv[i], O_RDONLY)) == -1)
			ft_exit("Error: Can't open file");
		while ((code = get_next_line(fd, &line)) > 0)
		{
			len = ft_strlen(line);
			printf("%d - %d - |%s|\n", code, len, line);
			free(line);
		}
		i++;
		if (i < argc)
			printf("\n%d eme FD\n\n", i);
	}
	printf("LAST %d - |%s|\n", code, line);
	return (0);
}
