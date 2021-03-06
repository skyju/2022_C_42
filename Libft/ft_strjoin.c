/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:19:18 by mkwak             #+#    #+#             */
/*   Updated: 2022/04/05 16:23:14 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		s1_len;
	int		s2_len;

	if (!s1 && !s2)
		return (0);
	else if (!s1)
		return (ft_strdup((char *)s2));
	else if (!s2)
		return (ft_strdup((char *)s1));
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	res = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, (char *)s1, s1_len + 1);
	ft_strlcat(res + s1_len, (char *)s2, s2_len + 1);
	return (res);
}
