/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akambou <akambou@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 22:15:01 by akambou           #+#    #+#             */
/*   Updated: 2023/09/18 22:28:14 by akambou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr_n;

	ptr_n = malloc(count * size);
	if (ptr_n == NULL)
		return (NULL);
	ft_bzero(ptr_n, count * size);
	return (ptr_n);
}
