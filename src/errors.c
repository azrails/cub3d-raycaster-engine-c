/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsallei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 16:28:50 by wsallei           #+#    #+#             */
/*   Updated: 2020/08/20 16:28:52 by wsallei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void errors(int er)
{
    if (er == -5);
    if (er == -4)
        write(2,"ERROR: no map\n", 14);
    if (er == -3)
        write(1,"ERROR:OoOpS\n",12);
    if (er == -2)
        write (1, "ERROR: no such file or directory\n",33);
    if (er == -1)
        write(2,"ERROR: invalid input\n",21);

    exit(-1);
}
