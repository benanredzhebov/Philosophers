/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beredzhe <beredzhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:26:48 by beredzhe          #+#    #+#             */
/*   Updated: 2024/04/28 13:54:58 by beredzhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h> // mutex: init destroy lock unlock, threads: create join
# include <sys/time.h> // gettimeofday#endif

# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define G_BLUE "\e[0;38;5;24m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define RED "\033[0;31m"
# define PINK "\e[0;38;5;199m"
# define RESET "\033[0m"

# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define DIED "died"

typedef struct s_data
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_meals; //n_eat
	int				philo_died;
	long long		time;
	pthread_t		monitor;
	pthread_mutex_t	*my_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	shared;
	pthread_mutex_t	tm;
}					t_data;

typedef struct s_philo
{
	int				id;
	long long		time_to_die;
	long long		last_meal_time;
	int				n_eaten;
	int				left_fork;
	int				right_fork;
	t_data			*data;
	pthread_t		th;
}					t_philo;

int			ft_isdigit(int n);
int			philo_eat(t_philo *phi);
int			simulation(t_philo *phi);
int			th_create(t_philo *phi);
int			ft_atoi(const char *str);
int			ft_iscorrect(char **str);
int			checks(int argc, char **argv);
int			init_data(t_data *data, char **argv, int argc);
int			state_print(t_philo *phi, int id, char *color, char *status);
int			philo_sleep(t_philo *phi);
int			philo_think(t_philo *phi);
int			is_dead(t_philo *phi, int *i);
void		*routine(void *arg);
void		init_philo(t_philo *phi, t_data *data);
void		time_sim(long long time);
void		drop_forks(t_philo *phi, int flag);
void		*routine2(void *args);
long long	time_diff(long long time);
long long	get_time(void);
void		one_philo(t_data *data, t_philo *phi);
void		free_all(t_data *data, t_philo *phi);
void		routine2_helper1(t_philo *phi);
void		routine2_helper2(t_philo *phi);
void		routine_helper1(t_philo *phi);
void		routine_helper2(t_philo *phi);

#endif