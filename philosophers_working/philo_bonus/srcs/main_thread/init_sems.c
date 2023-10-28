/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sems.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:18:43 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/28 15:15:46 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**	NAME
		ft_alloc_philos_and_forks
**	DESCRIPTION
		Effectively: calloc for array of philo structs of size num_philo
		and calloc for array of mutexes of size num_philo
**	RETURN
		Bool function returns 1 if malloc error, or 0 on Success.
*/

static bool	ft_alloc_philos_and_forks(t_info *info)
{
	info->philos = (t_philo *)malloc(info->num_philo * sizeof(t_philo));
	if (!info->philos)
		return (printf("Error: malloc\n"), 1);
	ft_bzero(info->philos, sizeof(t_philo) * info->num_philo);
	info->s_forks = (sem_t *)malloc(
			info->num_philo * sizeof(pthread_mutex_t));
	if (!info->s_forks)
		return (printf("Error: malloc\n"), 1);
	ft_bzero(info->s_forks, sizeof(pthread_mutex_t) * info->num_philo);
	info->pids = (int *)malloc(
			info->num_philo * sizeof(pid_t));
	if (!info->pids)
		return (printf("Error: malloc\n"), 1);
	ft_bzero(info->pids, sizeof(pid_t) * info->num_philo);
	return (0);
}

/*
**	NAME
		ft_init_mutexes
**	DESCRIPTION
		Initializes all mutexes that will be used.
**	RETURN
		Returns 0 on Success and 1 on Failure.
*/

static bool	ft_init_mutexes(t_info *info)
{
	int	i;
		// replace with fork and have child go to ft_pthread_entry_point

	if (sem_init(&info->s_ready, 1, 1))
		return (1);
	if (sem_init(&info->s_info_data, 1, 1))
		return (1);
	if (sem_init(&info->s_printf, 1, 1))
		return (1);
	i = 0;
	while (i < info->num_philo)
		if (sem_init(&info->philos[i++].s_data, 1, 1))
			return (1);
	i = 0;
	while (i < info->num_philo)
		if (sem_init(&info->s_forks[i++], 1, 1))
			return (1);
	return (0);
}

/*
	NAME
		ft_assign_forks
	DESCRIPTION
		Loops over the philos and assigns them an already initialized m_forks
		mutex from info->m_forks.
	RETURN
		Void functions returns nothing.
*/

static void	ft_assign_forks(t_info *info)
{
	int		i;

	i = 0;
	while (i < info->num_philo)
	{
		info->philos[i].r_fork = &info->s_forks[i];
		if (i == 0)
			info->philos[i].l_fork = &info->s_forks[info->num_philo - 1];
		else
			info->philos[i].l_fork = &info->s_forks[i - 1];
		i++;
	}
}

/*
**	NAME
		ft_create_philos
**	DESCRIPTION
		Loop that creates philosophers.
**	RETURN
		Returns 0 on Success and 1 on Failure.
*/

static bool	ft_create_philos(t_info *info)
{
	int		i;

	i = 0;
	sem_wait(&info->s_ready);
	while (i < info->num_philo)
	{
		info->philos[i].id = i;
		info->philos[i].info = info;
		info->philos[i].last_ate = info->start_time;
		info->philos[i].num_philo = info->num_philo;
		info->philos[i].time_to_die = info->time_to_die;
		info->philos[i].time_to_eat = info->time_to_eat;
		info->philos[i].time_to_sleep = info->time_to_sleep;
		if (info->num_tt_eat)
			info->philos[i].num_tt_eat = info->num_tt_eat;
		info->philos[i].p_num_meals = -1;
		// if (pthread_create(&info->philos[i].thread_id, NULL,
		// 		ft_pthread_entry_point, &info->philos[i]))
		// replace with fork and have child go to ft_pthread_entry_point
		info->pids[i] = fork();
		if (info->pids[i] == -1)
			return (printf("Error: Could not create all philosophers\n"), 1);
		else if (info->pids[i] == 0)
		{
			ft_pthread_entry_point(info);
			exit(SUCCESS);
			// theres gonna be a massive leak here lol.
		}
		i++;
	}
	return (0);
}

/*
**	NAME
		ft_philo_init
**	DESCRIPTION
		Calls basic setup functions: Arg parsing, initializing mutexes, 
			and calls function to create all philos.
**	RETURN
		Returns 0 on Success or 1 on Failure. Also prints error message if any
		errors are encountered either in this function or a called function.
*/

bool	ft_philo_init(int argc, char **argv, t_info *info)
{
	if (argc < 5 || argc > 6)
		return (printf("Error: Incorrect number of arguments.\n"), 1);
	info->philos = NULL;
	info->s_forks = NULL;
	if (ft_arg_parse(argc, argv, info))
		return (1);
	if (ft_alloc_philos_and_forks(info))
		return (ft_free_info(info), 1);
	if (ft_init_mutexes(info))
	{
		printf("Error: pthread_mutex_init: failed to initialize mutex.");
		return (ft_free_info(info), 1);
	}
	info->start_time = ft_get_time() + START_DELAY;
	ft_assign_forks(info);
	if (ft_create_philos(info))
		return (ft_free_info(info), 1);
	return (0);
}
