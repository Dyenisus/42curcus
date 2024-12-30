/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesoytur <yesoytur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:55:33 by yesoytur          #+#    #+#             */
/*   Updated: 2024/12/30 14:01:33 by yesoytur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*a;
	unsigned char	*b;
	size_t			i;

	a = malloc(count * size);
	if (!a)
		return (NULL);
	b = (unsigned char *)a;
	i = 0;
	while (i < (count * size))
	{
		b[i] = 0;
		i++;
	}
	return (a);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*n_s;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	if (!s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	n_s = (char *)ft_calloc(len_s1 + len_s2 + 1, sizeof(char));
	if (!n_s)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		n_s[i] = s1[i];
		i++;
	}
	while (i < len_s1 + len_s2)
	{
		n_s[i] = s2[i - len_s1];
		i++;
	}
	n_s[i] = '\0';
	return (n_s);
}

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	chr;

	chr = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == chr)
			return ((char *)&s[i]);
		i++;
	}
	if (chr == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*cpy_s1;

	len = ft_strlen(s1);
	cpy_s1 = (char *)ft_calloc((len + 1), sizeof(char));
	if (!cpy_s1)
		return (NULL);
	i = 0;
	while (i < len && s1[i])
	{
		cpy_s1[i] = s1[i];
		i++;
	}
	cpy_s1[i] = '\0';
	return (cpy_s1);
}
