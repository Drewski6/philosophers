/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:18:43 by dpentlan          #+#    #+#             */
/*   Updated: 2023/09/24 15:09:59 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void	*philo_thread_entry_point(void *arg)
{
	(void) arg;
	printf("You created a new thread! samp_arg is: %d\n", *(int *)arg);
	return (0);
}

int	create_one_philo(t_list **philos)
{
	t_philo		*one_philo;
	t_list		*new_link;
	int			ret;
	int			samp_arg;

	samp_arg = 42;
	one_philo = (t_philo *)malloc(sizeof(t_philo) * 1);
	if (!one_philo)
		return (-1);
	new_link = ft_lstnew(&one_philo);
	if (!new_link)
		return (-1);
	ft_lstadd_back(philos, new_link);
	ret = pthread_create(&((t_philo *)new_link->content)->thread_id,
			NULL, philo_thread_entry_point, &samp_arg);
	if (ret)
		return (ret);
	return (0);
}

int	create_n_philos(t_args *args, t_list **philos)
{
	int	i;

	i = 0;
	while (i < args->num_philo)
	{
		create_one_philo(philos);
		i++;
	}
	return (0);
}

void	destroy_one_philo(void *content)
{
	free((t_philo *)content);
}

int	destroy_all_philos(t_list **philos)
{
	int		ret;
	t_philo	*current;

	while (ft_lstsize(*philos) > 0)
	{
		current = (t_philo *)ft_lstlast(*philos);
		ret = pthread_join(current->thread_id, NULL);
		if (ret)
			return (-1);
		ft_lstdelone(*philos, destroy_one_philo);
	}
	return (0);
}
