/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarecha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 16:04:44 by bmarecha          #+#    #+#             */
/*   Updated: 2020/07/11 15:25:50 by bmarecha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float		ft_atof(char *str)
{
	float	res;
	int		coma;
	int		i;

	i = 6;
	coma = 0;
	res = 0;
	while (i && *str)
	{
		if (*str == '.')
			if (coma > 0)
				break;
			else
				coma++;
		else if (*str < 48 || *str > 57)
			break;
		else if (!(*str == 48 && res == 0 && coma == 0))
		{
			i--;
			res = res * 10 + *str - 48;
			if (coma > 0)
				coma++;
		}
		str++;
	}
	while (--coma > 0)
		res = res / 10;
	return res;
}
/*
143
456.12
78654.3
45.645.1
0..45
0052.12
125.100
45613.2154123
*/
