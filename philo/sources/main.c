/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:41:37 by avieira           #+#    #+#             */
/*   Updated: 2021/10/26 18:58:12 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	invalid_input(int n, char **args)
{
	int			i;
	int			j;

	if (n == 4 || n == 5)
	{
		i = 0;
		while (++i <= n)
		{
			j = -1;
			while (args[i][++j])
			{
				if (args[i][j] < '0' || args[i][j] > '9')
				{
					printf("Bad argument(s)\n");
					return (1);
				}
			}
		}
		return (0);
	}
	printf("Wrong number of arguments\n");
	return (1);
}

int	fill_input(char **args, t_dinner *dinner)
{
	dinner->nb_philos = ft_atoi(args[1]);
	dinner->time_to_die = ft_atoi(args[2]);
	dinner->time_to_eat = ft_atoi(args[3]);
	dinner->time_to_sleep = ft_atoi(args[4]);
	if (args[5])
		dinner->nb_mandatory_eats = ft_atoi(args[5]);
	else
		dinner->nb_mandatory_eats = -2;
	if (dinner->nb_philos == -1 || dinner->time_to_die == -1
		|| dinner->time_to_eat == -1 || dinner->time_to_sleep == -1
		|| dinner->nb_mandatory_eats == -1)
	{
		printf("Int overflow arguments\n");
		return (1);
	}
	else if (dinner->nb_philos == 0)
	{
		printf("At least 1 philosopher needed\n");
		return (1);
	}
	else if (dinner->nb_mandatory_eats == 0)
		return (1);
	return (0);
}

int	main(int ac, char **args)
{
	t_dinner	dinner;

	if (invalid_input(ac - 1, args))
		return (0);
	if (fill_input(args, &dinner))
		return (0);
	if (!create_dinner(&dinner))
	{
		launch_dinner(&dinner);
		destroy_dinner(&dinner);
	}
	else
		printf("Philosophers allocation failed\n");
}
