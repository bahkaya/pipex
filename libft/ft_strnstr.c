/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:31:09 by bahkaya           #+#    #+#             */
/*   Updated: 2025/06/20 15:35:39 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		k;
	size_t		little_len;

	little_len = ft_strlen(little);
	i = 0;
	if (little[i] == '\0')
		return ((char *)&big[i]);
	if (len == 0)
		return (NULL);
	while (i <= len && big[i] != '\0')
	{
		k = 0;
		while (big[i + k] == little[k] && i + k < len && big[i + k] != '\0')
		{
			k++;
			if (k == little_len)
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
