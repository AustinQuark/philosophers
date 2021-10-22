/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 04:14:00 by avieira           #+#    #+#             */
/*   Updated: 2021/10/22 13:19:22 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	print_msg(t_philo *philo, char *state, pthread_mutex_t *lock)
{
	pthread_mutex_lock(lock);
	printf("%d %d%s", ms_since(philo->birth), philo->id, state);
	/*
	ft_putnbr_fd(ms_since(philo->birth), 1);
	write(1, " ", 1);
	ft_putnbr_fd(philo->id, 1);
	write(1, state, ft_strlen(state));*/
	pthread_mutex_unlock(lock);
}