/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avieira <avieira@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:05:56 by avieira           #+#    #+#             */
/*   Updated: 2021/10/21 01:34:50 by avieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	usleep_ms(int ms, t_philo *philo, struct timeval *start)
{
	int sleep_count;
	struct timeval tmp;

	if (start == NULL)
	{
		start = &tmp;
		gettimeofday(start, NULL);
	}
	sleep_count = ms_since(*start);
	while (sleep_count < ms && !*philo->dinning)
	{
		usleep(100);
		sleep_count = ms_since(*start);
	}
}

unsigned int	ms_since(struct timeval start)
{
	struct timeval delta;
	struct timeval present;

	gettimeofday(&present, NULL);
	delta.tv_sec = present.tv_sec - start.tv_sec;
	delta.tv_usec = present.tv_usec - start.tv_usec;
	return ((delta.tv_sec * 1000) + (delta.tv_usec / 1000));
}
