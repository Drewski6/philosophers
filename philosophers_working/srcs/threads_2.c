/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:40:56 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/07 15:18:31 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	recall_philos(t_info *info)
{
	int			i;
	int			ret;
	pthread_t	*current;

	i = 0;
	ret = 0;
	while (i < info->num_philo)
	{
		current = &(info->philos[i].thread_id);
		ret = pthread_join(*current, NULL);
		if (ret == 3)
			return (printf("thread with ID %ld DNE\n", *current), 1);
		i++;
	}
	return (0);
}

int	create_one_philo(t_info *info)
{
	(void) info;
	
	return (0);
}
