/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_strs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkmb <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:20:04 by alkmb             #+#    #+#             */
/*   Updated: 2023/11/14 09:54:53 by akambou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "../includes/ft_printf.h"

int	ft_char_len(char c, int *len)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	(*len)++;
	return (*len);
}

int	ft_str_len(char *str, int *len)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		if (write (1, "(null)", 6) == -1)
			return (-1);
		(*len) += 6;
		return (*len);
	}
	while (str[i] != '\0')
	{
		if (ft_char_len(str[i], len) == -1)
			return (-1);
		i++;
	}
	return (*len);
}
