/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:57:19 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/09 10:10:07 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdint.h>

typedef int8_t bool;

typedef long int t_ms;

typedef struct s_info t_info;

// each t_philo contains a m_fork meaning there are as many forks as philos.
// however, not all philos will reach for their own fork first.

typedef struct s_philo
{
	int				id;
	pthread_t		thread_id;
	t_ms			last_ate;
	pthread_mutex_t	m_fork;
	t_info			*info;
}			t_philo;

typedef struct s_info
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_tt_eat;
	pthread_mutex_t	m_printf;
	t_philo	*philos;
	t_ms			start_time;
	bool			someone_died;
}			t_info;

//	philo.c

//	time_utils.c
t_ms	get_time(void);
void	msleep(int time_in_ms);

//	arg_parse.c
bool	arg_count(int argc);
bool	arg_parse(int argc, char **argv, t_info *info);

//	int_utils.c
void	ft_bzero(void *str, size_t len);
bool	ft_atoi_backcheck(char *s_num, int num);
int		ft_atoi(const char *nptr);
bool	ft_isdigit(int c);

//	threads.c
bool	philo_init(int argc, char **argv, t_info *info);
bool	create_philos(t_info *info);
void	free_info(t_info *info);
int		recall_philos(t_info *info);
int		create_one_philo(t_info *info);

//	monitor.c
void	ft_monitor(t_info *info);

//	philo_actions.c
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_wait(t_philo *philo);
void	*pthread_entry_point(void *arg);

//	debug_funcs.c		To remove at the end.
void	print_info(t_info *info);

#endif
