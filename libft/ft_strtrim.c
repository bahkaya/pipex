/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 12:33:57 by bahkaya           #+#    #+#             */
/*   Updated: 2025/06/21 12:33:57 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_set_check(char const s1_char, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == s1_char)
			return (set[i]);
		i++;
	}
	return (0);
}

static size_t	ft_malloc_len_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;

	start = 0;
	i = 0;
	while (s1[i] == ft_set_check(s1[i], set))
	{
		start++;
		i++;
	}
	return (start);
}

static size_t	ft_malloc_len_end(char const *s1, char const *set)
{
	size_t	s1_len_x;
	size_t	end;

	s1_len_x = ft_strlen(s1);
	end = 0;
	while (s1_len_x > 0 && s1[s1_len_x - 1]
		== ft_set_check(s1[s1_len_x - 1], set))
	{
		end++;
		s1_len_x--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	size_t	s1_len_y;
	char	*str_trimmed;

	start = ft_malloc_len_start(s1, set);
	end = ft_malloc_len_end(s1, set);
	s1_len_y = ft_strlen(s1);
	i = 0;
	if (start + end > s1_len_y)
		s1_len_y = 0;
	else
		s1_len_y = s1_len_y - start - end;
	str_trimmed = malloc(sizeof(char) * (s1_len_y + 1));
	if (!str_trimmed)
		return (NULL);
	while (start < ft_strlen(s1) - end)
	{
		str_trimmed[i] = s1[start];
		start++;
		i++;
	}
	str_trimmed[i] = '\0';
	return (str_trimmed);
}
