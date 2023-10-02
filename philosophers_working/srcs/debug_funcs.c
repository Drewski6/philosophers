/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:50:17 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/02 14:54:30 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_args(t_args *args)
{
	printf("num_philo: %d\n", args->num_philo);
	printf("time_to_die: %d\n", args->time_to_die);
	printf("time_to_eat: %d\n", args->time_to_eat);
	printf("time_to_sleep: %d\n", args->time_to_sleep);
	printf("num_tt_eat: %d\n", args->num_tt_eat);
}
