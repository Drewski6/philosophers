/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:57:19 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/29 21:48:27 by dpentlan         ###   ########.fr       */
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
** MACROS
*/
# define START_DELAY 100

//# define USE_COLORS

# ifndef USE_COLORS
#  define BLUE ""
#  define YELLOW ""
#  define GREEN ""
#  define RED ""
#  define CLEAR ""
# endif

# ifdef USE_COLORS
#  define BLUE "\e[34m"
#  define YELLOW "\e[33m"
#  define GREEN "\e[32m"
#  define RED "\e[31m"
#  define CLEAR "\e[0m"
# endif

/*
**	TYPEDEFS
*/

typedef long int		t_ms;

typedef struct s_info	t_info;

typedef enum e_ret
{
	SUCCESS,
	FAILURE,
}	t_ret;

/*
** l_fork and r_fork are addresses to m_forks in t_info
*/

typedef struct s_philo
{
	int					id;
	int					num_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					num_tt_eat;
	int					p_num_meals;
	pthread_t			thread_id;
	t_ms				last_ate;
	t_info				*info;
	pthread_mutex_t		m_data;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
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
	int					num_philos_waiting;
	pthread_mutex_t		m_printf;
	pthread_mutex_t		m_info_data;
	pthread_mutex_t		m_ready;
	pthread_mutex_t		*m_forks;
	t_philo				*philos;
	t_ms				start_time;
	bool				someone_died;
}						t_info;

/*
**	FUNCTION DEFINITIONS
*/

/*
**		//	main_thread	//
*/

//	destroy_threads.c
//	static bool	ft_recall_philos(t_info *info);
//	static void	ft_destroy_mutexes(t_info *info);
void	ft_free_info(t_info *info);

//	init_threads.c
//	static bool	ft_alloc_philos_and_forks(t_info *info);
//	static bool	ft_init_mutexes(t_info *info);
//	static void	ft_assign_forks(t_info *info);
//	static bool	ft_create_philos(t_info *info);
bool	ft_philo_init(int argc, char **argv, t_info *info);

//	monitor.c
//	static void	ft_philo_died(t_philo *philo);
//	static bool	ft_check_all_philos_have_eaten(t_philo *philo);
//	static bool	ft_monitor_die_check(t_info *info, int i);
bool	ft_monitor(t_info *info);

//	philo.c
//	int		main(int argc, char **argv);

//	time_utils.c
t_ms	ft_get_time(void);
bool	ft_msleep(t_info *info, int time_in_ms);

/*
**		//	parsing	//
*/

//	arg_parse.c
//	static bool	ft_str_all_digit(char *arg);
//	static bool	ft_edgecases(int *arg_int_value, int i);
//	static bool	ft_verify_arg(char *arg, int *arg_int_value);
bool	ft_arg_parse(int argc, char **argv, t_info *info);

//	ft_utils.c
void	ft_bzero(void *str, size_t len);
bool	ft_atoi_backcheck(char *s_num, int num);
//	static int	ft_int_build(char *str);
int		ft_atoi(const char *nptr);
bool	ft_isdigit(int c);

/*
**		//	philos	//
*/

//	philo_actions.c
//	static void	ft_philo_sleep(t_philo *philo);
void	ft_philo_wait(t_philo *philo);
bool	ft_check_if_philo_dead(t_info *info);
//	static bool	ft_philo_check_num_meals(t_philo *philo);
void	*ft_pthread_entry_point(void *arg);

//	philo_eating.c
//	static void	ft_save_last_eat(t_philo *philo);
//	static void	ft_grab_forks_even(t_philo *philo);
//	static void	ft_grab_forks_odd(t_philo *philo);
void	ft_philo_eat(t_philo *philo);
void	ft_philo_odd_sync(t_philo *philo, int flag);

//	philo_print.c
void	ft_m_printf(t_philo *philo, const char *s, t_ms time_stamp);

#endif
