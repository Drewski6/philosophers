/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:45:44 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/28 15:56:32 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	NAME
		ft_m_printf
**	DESCRIPTION
		Prints the time stamp, philo id, and message only if someone_died is 0.
**	RETURN
		Void function does not return a value.
*/

void	ft_m_printf(t_philo *philo, const char *s, t_ms time_stamp)
{
	sem_wait(philo->info->s_info_data);
	if (!philo->info->someone_died)
	{
		sem_wait(philo->info->s_printf);
		if (philo->id % 2)
			printf(s, YELLOW, time_stamp, GREEN, philo->id + 1, CLEAR);
		else
			printf(s, YELLOW, time_stamp, RED, philo->id + 1, CLEAR);
		sem_post(philo->info->s_printf);
	}
	sem_post(philo->info->s_info_data);
}
