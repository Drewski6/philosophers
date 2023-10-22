/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:45:44 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/22 23:26:01 by dpentlan         ###   ########.fr       */
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

void	ft_m_printf(t_info *info, const char *s, t_ms time_stamp, int id)
{
	pthread_mutex_lock(&info->m_info_data);
	if (!info->someone_died)
	{
		pthread_mutex_lock(&info->m_printf);
		printf(s, time_stamp, id + 1);
		pthread_mutex_unlock(&info->m_printf);
	}
	pthread_mutex_unlock(&info->m_info_data);
}
