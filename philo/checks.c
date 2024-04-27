/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:22:14 by berenzhe          #+#    #+#             */
/*   Updated: 2024/04/19 09:27:57 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int n)
{
	if (n >= '0' && n <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long	nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	if (!str)
		return (nbr);
	while (*str && ((*str == ' ') || (*str >= 9 && *str <= 13)))
		str++;
	if (*str == '-')
		sign = -1;
	if ((*str == '-') || (*str == '+'))
		str++;
	while ((*str >= '0') && (*str <= '9'))
	{
		nbr = (nbr * 10) + (*str - '0');
		str++;
	}
	if (nbr > 2147483647)
		return (0);
	return (nbr * sign);
}

int	ft_iscorrect(char **str)
{
	int		i;
	int		j;
	char	c;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			c = str[i][j];
			if ((c >= '0' && c <= '9') || c == '+')
			{
				if (c == '+' && (!ft_isdigit(str[i][j + 1]) \
					|| ft_isdigit(str[i][j - 1])))
					return (0);
				j++;
			}
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	checks(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (printf("Error: arguments must be five or six\n"), 0);
	if (!ft_iscorrect(argv))
		return (printf("Error: some arguments are not unsigned integers\n"), 0);
	return (1);
}
