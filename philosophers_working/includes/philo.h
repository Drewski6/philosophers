/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:57:19 by dpentlan          #+#    #+#             */
/*   Updated: 2023/09/24 14:56:37 by dpentlan         ###   ########.fr       */
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

typedef struct s_args
{
	int	num_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_tt_eat;
}			t_args;

typedef struct s_philo
{
	pthread_t	thread_id;
}			t_philo;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

//	philo.c

//	time_utils.c

//	arg_parse.c
int		arg_count(int argc);
int		arg_parse(int argc, char **argv, t_args *args);

//	int_utils.c
void	ft_bzero(void *str, size_t len);
bool	ft_atoi_backcheck(char *s_num, int num);
int		ft_atoi(const char *nptr);

//	threads.c
int		create_one_philo(t_list **philos);
int		create_n_philos(t_args *args, t_list **philos);
int		destroy_all_philos(t_list **philos);

//	lists.c
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));

//	debug_funcs.c		To remove at the end.
int		print_args(t_args *args);

#endif
