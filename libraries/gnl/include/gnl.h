/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pstengl <pstengl@student.42wolfsburg.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:14:10 by pstengl           #+#    #+#             */
/*   Updated: 2022/04/01 15:22:02 by pstengl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H
# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(char *str);
char	*ft_strext(char **base, char *ext, size_t size);
void	ft_bzero(void *space, size_t size);
void	ft_prune_front(void *space, size_t from, size_t max_size);

#endif
