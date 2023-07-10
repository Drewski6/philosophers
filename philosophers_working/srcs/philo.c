/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:58:03 by dpentlan          #+#    #+#             */
/*   Updated: 2023/07/10 19:20:01 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*	
**	allowed functions:
**		memset, printf, malloc, free, write, usleep, gettimeofday,
**	
**		pthread_create, pthread_detach, pthread_join,
**	
**		pthread_mutex_init, pthread_mutex_destroy,
**		pthread_mutex_lock, pthread_mutex_unlock
*/

typedef struct s_info 
{
	int				j;
	pthread_mutex_t	lock;
}					t_info;

void	*print_info_no_lock(void *info)
{
	int		i;
	t_info	*l_info;

	l_info = (t_info *)info;
	l_info->j++;
	i = 1;
	printf("Staring new thread.\n");
	while (i <= 10)
	{
		printf("i: %d j: %d\n", i, l_info->j);
		i++;
	}
	return (0);
}

void	*print_info_lock(void *info)
{
	int		i;
	t_info	*l_info;

	l_info = (t_info *)info;
	pthread_mutex_lock(&(l_info->lock));
	l_info->j++;
	i = 1;
	printf("Staring new thread.\n");
	while (i <= 10)
	{
		printf("i: %d j: %d\n", i, l_info->j);
		i++;
	}
	pthread_mutex_unlock(&(l_info->lock));
	return (0);
}

int	main(int argc, char **argv)
{
	pthread_t	thread_1;
	pthread_t	thread_2;
	t_info		info;

	if (argc < 5 || argc > 6)
	{
		printf("Error: Incorrect number of arguments.\n");
		return (1);
	}
	if (argv) {}

	pthread_mutex_init(&(info.lock), NULL);
	info.j = 0;
	pthread_create(&thread_1, NULL, &print_info_no_lock, &info);
	pthread_create(&thread_2, NULL, &print_info_no_lock, &info);
	pthread_join(thread_1, NULL);
	pthread_join(thread_2, NULL);

	pthread_create(&thread_1, NULL, &print_info_lock, &info);
	pthread_create(&thread_2, NULL, &print_info_lock, &info);
	pthread_join(thread_1, NULL);
	pthread_join(thread_2, NULL);

	return (0);
}
