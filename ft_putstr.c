/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zengxin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 16:42:43 by zengxin           #+#    #+#             */
/*   Updated: 2017/09/26 16:42:45 by zengxin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putstr(char const *s)
{
	size_t	i;

	i = 0;
	if (s == 0)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}
