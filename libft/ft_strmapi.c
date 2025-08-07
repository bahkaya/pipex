/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:55:35 by bahkaya           #+#    #+#             */
/*   Updated: 2025/06/15 13:57:31 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	s_len;
	char	*str_ita;

	i = 0;
	s_len = ft_strlen(s);
	str_ita = malloc(sizeof(char) * s_len + 1);
	if (!str_ita)
		return (NULL);
	while (s[i] != '\0')
	{
		str_ita[i] = f(i, s[i]);
		i++;
	}
	str_ita[i] = '\0';
	return (str_ita);
}
