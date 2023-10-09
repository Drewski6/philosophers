/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 23:24:20 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/09 23:24:30 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	NAME
		ft_recall_philos
**	DESCRIPTION
		Free function for any open threads in order to cleanly exit.
**	RETURN
		Bool function returns 0 on Success and 1 on Failure.
*/

bool	ft_recall_philos(t_info *info)
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
