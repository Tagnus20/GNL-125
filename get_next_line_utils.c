/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdejo <averdejo@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:37:48 by averdejo          #+#    #+#             */
/*   Updated: 2023/05/08 11:05:15 by averdejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	str = (char *) ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	if (s == 0)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		str = (char *) ft_calloc(2, sizeof(char));
		str = "";
		return (str);
	}
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		++i;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (c == '\0')
	{
		i = ft_strlen(s);
		return ((char *)&s[i]);
	}
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return ((char *) '\0');
}

char	*ft_strdup(const char *s1)
{
	char	*cs1;
	size_t	len;
	char	*c_dst;
	size_t	i;
	char	*c_src;

	len = ft_strlen(s1) + 1;
	cs1 = (char *) malloc(len * sizeof(char));
	if (!cs1)
		return (NULL);
	i = 0;
	c_src = (char *) s1;
	c_dst = (char *) cs1;
	if (c_src == 0 && c_dst == 0)
		return (0);
	while (len > i)
	{
		c_dst[i] = c_src[i];
		i++;
	}
	cs1 = (void *) c_dst;
	return (cs1);
}
