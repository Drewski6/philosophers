/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:18:43 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/07 15:58:06 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

bool	create_philos(t_info *info)
{
	int		i;

	i = 0;
	info->philos = (t_philo *)malloc(info->num_philo * sizeof(t_philo));
	if (!info->philos)
		return (printf("Error: malloc\n"), 1);
	ft_bzero(info->philos, sizeof(t_philo) * info->num_philo);
	while (i < info->num_philo)
	{
		info->philos[i].id = i;
		info->philos[i].info = info;
		if (pthread_create(&info->philos[i].thread_id, NULL,
				pthread_entry_point, &info->philos[i]))
			return (printf("Error: Could not create all philosophers\n"), 1);
		i++;
	}
	return (0);
}

void	free_info(t_info *info)
{
	recall_philos(info);
	if (info->philos)
		free(info->philos);
	info->philos = NULL;
}

bool	philo_init(int argc, char **argv, t_info *info)
{
	if (arg_count(argc))
		return (1);
	if (arg_parse(argc, argv, info))
		return (1);
	if (pthread_mutex_init(&info->m_printf, NULL))
		return (1);
	info->start_time = get_time();
	if (create_philos(info))
		return (1);
	return (0);
}
