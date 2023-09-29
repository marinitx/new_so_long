/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:08:16 by mhiguera          #+#    #+#             */
/*   Updated: 2023/09/29 10:15:18 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int i;
    int j;
    int save;
    char *format;

    i = 0;
    j = 0;
    save = 0;
    format = "HOLA.txt";
    while (argv[2][i])
    {
        if (argv[2][i++] == format[j++])
            save++;
        else
            i++;
    }
    printf("%d", save);
    return (0);
}