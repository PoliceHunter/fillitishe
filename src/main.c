/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmyrcell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:44:29 by tmyrcell          #+#    #+#             */
/*   Updated: 2019/12/12 17:26:53 by tmyrcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillit.h"

int		no_open(void)
{
	ft_putendl("FILE NOT OPEN");
	exit(0);
}

int		no_usage(void)
{
	ft_putendl("Usage: Fillit source file");
	exit(0);
}

int		error(int fd, t_tetri *result)
{
    free_result(result);
	ft_putendl("error");
	close(fd);
	exit(0);
}

t_tetri    *fillit(int fd, t_tetri *result)
{
    char	buf[21];
    int     check_read;
    int     *temp_buf;

    check_read = 0;
    temp_buf = (int *)malloc(sizeof(int) * 2);
    buf[20] = 0;
    while ((temp_buf[0] = read(fd, buf, 21)))
    {
        temp_buf[1] = temp_buf[0];
        check_read += 1;
        if (temp_buf[0] < 20 ? error(fd, result) : (check(fd, buf, result)))
            read_coords(buf, &result);
    }
    if (!(check_last(fd, temp_buf)))
        error(fd, result);
    if (check_read < 1 || count_tetriminos(result) > 26)
        error(fd, result);
    return (result);
}


int		main(int ac, char **av)
{
	t_tetri		*result;
	if (ac != 2)
		no_usage();
	result = NULL;
	int fd = open(av[1], O_RDONLY);
	if (fd < 0)
		no_open();
    result = fillit(fd, result);
	solve(result);
	return (0);
}

