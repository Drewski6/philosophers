/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:58:03 by dpentlan          #+#    #+#             */
/*   Updated: 2023/09/24 15:12:06 by dpentlan         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_args	args;
	t_list	*philos;

	philos = 0;
	if (arg_count(argc))
		return (1);
	ft_bzero((void *)&args, sizeof(t_args));
	if (arg_parse(argc, argv, &args))
		return (1);
	if (create_n_philos(&args, &philos))
		return (1);
	usleep(1000);
	printf("number of philos created: %d\n", ft_lstsize(philos));
	usleep(1000);
	destroy_all_philos(&philos);
	printf("number of philos remaining: %d\n", ft_lstsize(philos));
	return (0);
}
