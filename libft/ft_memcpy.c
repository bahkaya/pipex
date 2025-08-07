/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:25:17 by bahkaya           #+#    #+#             */
/*   Updated: 2025/06/19 16:48:28 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*c;
	unsigned char	*x;

	i = 0;
	c = (unsigned char *) dest;
	x = (unsigned char *) src;
	if (c == NULL && x == NULL)
		return (NULL);
	while (i < n)
	{
		c[i] = x[i];
		i++;
	}
	return (c);
}
