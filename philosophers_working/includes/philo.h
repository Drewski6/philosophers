/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:57:19 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/09 22:23:35 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*
**	INCLUDES
*/

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdint.h>
# include <stdbool.h>

/*
**	TYPEDEFS
*/

typedef long int		t_ms;

typedef struct s_info	t_info;

typedef enum e_ret
{
	SUCCESS,
	FAILURE,
}			t_ret;

typedef struct s_philo
{
	int					id;
	pthread_t			thread_id;
	t_ms				last_ate;
	pthread_mutex_t		m_fork;
	t_info				*info;
}						t_philo;

/*
**	num_philo		Total number of philosophers.
**	time_to_die		Time a philosopher can survive without eating.
**	time_to_eat		How long it takes for a philosopher to eat.
**	time_to_sleep	how long it takes for a philosopher to sleep.
**	num_tt_eat		(Optional): Minimum number of times each philosophers
**						should eat before simulation should stop.
*/

typedef struct s_info
{
	int					num_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					num_tt_eat;

	pthread_mutex_t		m_printf;
	t_philo				*philos;
	t_ms				start_time;
	bool				someone_died;
}						t_info;

/*
**	FUNCTION DEFINITIONS
*/

//	philo.c

//	time_utils.c
t_ms	ft_get_time(void);
void	ft_msleep(int time_in_ms);

//	arg_parse.c
bool	ft_arg_count(int argc);
bool	ft_arg_parse(int argc, char **argv, t_info *info);

//	int_utils.c
void	ft_bzero(void *str, size_t len);
bool	ft_atoi_backcheck(char *s_num, int num);
int		ft_atoi(const char *nptr);
bool	ft_isdigit(int c);

//	threads.c
bool	ft_philo_init(int argc, char **argv, t_info *info);
bool	ft_create_philos(t_info *info);
void	ft_free_info(t_info *info);
int		ft_recall_philos(t_info *info);
int		ft_create_one_philo(t_info *info);

//	monitor.c
void	ft_monitor(t_info *info);

//	philo_actions.c
void	ft_philo_eat(t_philo *philo);
void	ft_philo_sleep(t_philo *philo);
void	ft_philo_wait(t_philo *philo);
void	*ft_pthread_entry_point(void *arg);

//	debug_funcs.c		To remove at the end.
void	ft_print_info(t_info *info);

#endif
