/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:18:43 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/02 15:36:02 by dpentlan         ###   ########.fr       */
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

bool	create_philos(t_info *info)
{
	(void) info;
	info->philos = (t_philo *)malloc(info->num_philo * sizeof(t_philo));
	if (!info->philos)
		return (printf("Error: malloc\n"), 1);
	ft_bzero(info->philos, sizeof(t_philo) * info->num_philo);
	return (0);
}

void	free_info(t_info *info)
{
	(void) info;
	if (info->philos)
		free(info->philos);
	info->philos = NULL;
}

void	ft_t_print(const char *str, t_info *info)
{
	(void) info;
	printf("%s\n", str);
}

bool	philo_init(int argc, char **argv, t_info *info)
{
	if (arg_count(argc))
		return (1);
	if (arg_parse(argc, argv, info))
		return (1);
	if (create_philos(info))
		return (1);
	return (0);
}
