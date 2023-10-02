/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:18:43 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/02 14:55:58 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <asm-generic/errno.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void	*philo_thread_entry_point(void *arg)
{
	(void) arg;
	while (1)
	{
		printf("You created a new thread! samp_arg is: %d\n", *(int *)arg);
	}
	return (0);
}
