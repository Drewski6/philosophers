/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:50:17 by dpentlan          #+#    #+#             */
/*   Updated: 2023/10/09 22:23:45 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_info(t_info *info)
{
	printf("num_philo: %d\n", info->num_philo);
	printf("time_to_die: %d\n", info->time_to_die);
	printf("time_to_eat: %d\n", info->time_to_eat);
	printf("time_to_sleep: %d\n", info->time_to_sleep);
	printf("num_tt_eat: %d\n", info->num_tt_eat);
}
