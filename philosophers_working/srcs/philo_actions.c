/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:39:59 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/07 15:57:44 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void	philo_eat(t_info *info)
{
	(void) info;
	//pthread_mutex_lock()
	return ;
}

void	philo_sleep(t_info *info)
{
	(void) info;
	return ;
}

void	philo_wait(t_info *info)
{
	(void) info;
	return ;
}

void	*pthread_entry_point(void *arg)
{
	t_info	*info;

	info = arg;
	// pthread_mutex_lock(&info->m_printf);
	// printf("You created a new thread! samp_arg is: %p\n", info);
	// pthread_mutex_unlock(&info->m_printf);
	philo_eat(info);
	philo_sleep(info);
	philo_wait(info);
	return (0);
}
