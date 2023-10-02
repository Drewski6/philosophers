/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:58:03 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/02 15:34:02 by dpentlan         ###   ########.fr       */
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
	t_info	info;

	ft_bzero((void *)&info, sizeof(t_info));
	philo_init(argc, argv, &info);
	free_info(&info);
	return (0);
}
