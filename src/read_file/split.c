/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelard <lmelard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:15:20 by lmelard           #+#    #+#             */
/*   Updated: 2022/05/20 17:46:15 by lmelard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static char	*ft_malloc_str(const char *s, char c)
{
	char		*str;
	size_t		i;

	i = 0;
	while (s[i] && s[i] != '\n' && (s[i] != c))
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	i--;
	while (i > 0)
	{
		str[i] = s[i];
		i--;
	}
	str[i] = s[i];
	return (str);
}

static void	*ft_free(char **str, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(str[j]);
		j++;
	}
	free(str);
	return (NULL);
}

char	**ft_split_fdf(char *s, char c, int width)
{
	char	**str;
	size_t	i;
	size_t	j;

	str = (char **)malloc(sizeof(char *) * (width + 1));
	if (!str)
		return (NULL);
	j = width;
	i = 0;
	while (*s && *s != '\n' && i < j)
	{
		while (*s && *s != '\n' && *s == c)
			s++;
		if (*s && *s != c && *s != '\n')
		{
			str[i] = ft_malloc_str(s, c);
			if (!str[i])
				return (ft_free(str, i));
			while (*s && *s != '\n' && *s != c)
				s++;
			i++;
		}
	}
	return (str[i] = 0, str);
}
