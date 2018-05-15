/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:24:21 by opakhovs          #+#    #+#             */
/*   Updated: 2017/11/01 14:24:23 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*newstr;
	int		i;

	if (s == NULL)
		return (NULL);
	newstr = (char*)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (newstr == NULL)
		return (NULL);
	while (s[start] && len)
	{
		newstr[i] = s[start];
		start++;
		i++;
		len--;
	}
	newstr[i] = '\0';
	return (newstr);
}
