/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:57:19 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/02 15:31:54 by dpentlan         ###   ########.fr       */
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
# include <stdbool.h>

typedef struct s_philo
{
	pthread_t	thread_id;
}			t_philo;

typedef struct s_info
{
	int		num_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_tt_eat;
	t_philo	*philos;
}			t_info;

//	philo.c

//	time_utils.c

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

//	debug_funcs.c		To remove at the end.
void	print_info(t_info *info);

#endif
