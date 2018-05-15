/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:02:56 by opakhovs          #+#    #+#             */
/*   Updated: 2017/11/15 17:35:40 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*holder1;
	unsigned char	*holder2;

	holder1 = (unsigned char*)src;
	holder2 = (unsigned char*)dst;
	while (n)
	{
		*holder2++ = *holder1++;
		n--;
	}
	return (dst);
}
