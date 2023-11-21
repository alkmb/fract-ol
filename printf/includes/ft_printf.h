/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akambou <akambou@student.42barcelo>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:00:08 by akambou           #+#    #+#             */
/*   Updated: 2023/09/18 23:11:30 by akambou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

int		ft_printf(const char *str, ...);
int		ft_char_len(char c, int *len);
int		ft_str_len(char *str, int *len);
int		ft_nbr(int nbr, int *len);
int		ft_ptr(unsigned long ptr, int *len);
int		ft_hex(unsigned int nbr, int *len, const char *base);
int		ft_unsint(unsigned int nbr, int *len);
