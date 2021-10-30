/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msierra- <msierra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:03:17 by msierra-          #+#    #+#             */
/*   Updated: 2021/10/25 14:52:44 by msierra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*a;
	size_t	i;
	size_t	lens;

	lens = ft_strlen(s);
	i = 0;
	if (!s)
		return (NULL);
	if (start >= lens)
		len = 0;
	if (len > lens)
		len = lens;
	a = (char *)malloc((len + 1) * sizeof(char));
	if (!a)
		return (NULL);
	while (i < len && s[start + i])
	{
		a[i] = s[start + i];
		i++;
	}
	a[i] = '\0';
	return (a);
}
