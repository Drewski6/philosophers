/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:20:15 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/10 14:50:04 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

/*
**	NAME
		ft_monitor
**	DESCRIPTION
		Used by the main thread to monitor the status of the philos' alive status
**	RETURN
		Void only returns in case where num_tt_eat is defined by user.
*/

void	ft_monitor(t_info *info)
{
	//int		i;

	(void) info;
	ft_msleep(1000);
	// while (1)
	// {
	// 	i = 0;
	// 	while (i < info->num_philo)
	// 	{
	// 		if (ft_get_time() - info->philos[i].last_ate >= info->time_to_die)
	// 			return ;	// maybe also print that someone died.
	// 		i++;
	// 	}
	// }
	return ;
}
