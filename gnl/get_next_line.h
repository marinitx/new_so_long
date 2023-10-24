/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhiguera <mhiguera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:36:39 by mhiguera          #+#    #+#             */
/*   Updated: 2023/10/23 18:35:53 by mhiguera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char		*get_next_line(int fd);
size_t      ft_strlen2(const char *str);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin2(char *s1, char *s2);
char		*ft_ending(char *str);
char		*ft_extra(char *aux);
char		*ft_save(int fd, char *aux);

#endif
