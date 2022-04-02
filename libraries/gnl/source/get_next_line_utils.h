/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:14:34 by pstengl           #+#    #+#             */
/*   Updated: 2022/04/02 14:36:13 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_UTILS_H
# define GET_NEXT_LINE_UTILS_H
# include <unistd.h>
# include <stdlib.h>

void	*gnl_calloc(size_t nmemb, size_t size);
size_t	gnl_strlen(char *str);
char	*gnl_strext(char **base, char *ext, size_t size);
void	gnl_bzero(void *space, size_t size);
void	gnl_prune_front(void *space, size_t from, size_t max_size);

#endif
