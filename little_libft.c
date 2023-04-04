/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_libft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:05:40 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/03/31 19:05:42 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)str;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (str);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s1[i] == s2[i] && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;
	char		c1;

	c1 = c;
	i = ft_strlen(s);
	while (i && c1 != s[i])
		i--;
	if (c1 == s[i])
		return ((char *)&(s[i]));
	return (0);
}
