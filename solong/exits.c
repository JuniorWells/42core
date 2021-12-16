/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:16:47 by kchaniot          #+#    #+#             */
/*   Updated: 2021/12/14 20:16:52 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_args(void)
{
	write(STDOUT, "Error\n", 7);
	write(STDOUT, "Invalid arguments\n", 19);
	exit(1);
}

void	exit_file(void)
{
	write(STDOUT, "Error\n", 7);
	write(STDOUT, "Invalid map file\n", 18);
	exit(1);
}
