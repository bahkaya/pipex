/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 14:09:38 by bahkaya           #+#    #+#             */
/*   Updated: 2025/06/18 13:57:25 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s_x;
	unsigned char	*dest_x;

	s_x = (unsigned char *) src;
	dest_x = (unsigned char *) dest;
	i = 0;
	if (!s_x && !dest_x)
		return (dest);
	if (dest < src)
	{
		ft_memcpy(dest, src, n);
		return (dest);
	}
	while (i < n)
	{
		dest_x[n -1] = s_x[n - 1];
		n--;
	}
	return (dest);
}
