/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 12:27:08 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/04/30 12:31:26 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

/* 
 * If for some reason the code get_next_line is not compile with the 
 * -D BUFFER_SIZE=<int> - if BUFFER_SIZE is not defined, BUFFER_SIZE will be
 * defined with 1 as it's value.
*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

/*
 * used fr the read()
*/
# include <unistd.h>

/*
 * used for malloc() and free().
*/
# include <stdlib.h>

int		get_next_line(int fd, char **line);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);

#endif
