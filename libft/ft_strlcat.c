/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:26:35 by hbui-vu           #+#    #+#             */
/*   Updated: 2022/09/28 21:18:11 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;

	i = 0;
	j = 0;
	if (!dstsize)
		return (ft_strlen(src));
	dst_len = ft_strlen(dst);
	if (dst_len < dstsize && dstsize > 0)
	{
		while (dst[i])
			i++;
		while (i < dstsize - 1 && src[j])
			dst[i++] = src[j++];
		dst[i] = '\0';
	}
	else
		dst_len = dstsize;
	return (dst_len + ft_strlen(src));
}

/*#include <stdio.h>
#include <string.h>
int main(void)
{
	char dst[10] = "cat";
	char *src = "dog";
	size_t size = 2;

	printf("ft: %lu ..... %s \n", ft_strlcat(dst, src, size), dst);

	char dst1[10] = "cat";
	char *src1 = "dog";
	size_t size1 = 2;

	printf("or: %lu ..... %s \n", strlcat(dst1, src1, size1), dst1);
	
}*/
