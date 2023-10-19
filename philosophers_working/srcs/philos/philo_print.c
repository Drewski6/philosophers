/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:45:44 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/19 12:45:59 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
