/*A race condition occurs when a program depends on the
timing of one or more events to function correctly.
A race condition typically occurs when multiple threads
access a shared variable (or state) at the same time*/

#include <stdio.h>
#include <pthread.h>
#include "race_condition.h"

pthread_mutex_t mutex;
void	*deposit(void *amount);

int	main()
{
	int	before = read_balance();
	printf("Before: %d\n", before);

	pthread_t thread1;
	pthread_t thread2;
	pthread_mutex_init(&mutex, NULL);

	int deposit1 = 200;
	int deposit2 = 300;

	if (pthread_create(&thread1, NULL, deposit, (void *) &deposit1) != 0)
		return (1);
	if (pthread_create(&thread2, NULL, deposit, (void *) &deposit2) != 0)
		return (2);
	
	if (pthread_join(thread1, NULL) != 0)
		return (3);
	if (pthread_join(thread2, NULL) != 0)
		return (4);

	int	after = read_balance();
	printf("After: %d\n", after);

	pthread_mutex_destroy(&mutex); // Destroy Mutex

	return (0);
}

void	*deposit(void *amount)
{
	pthread_mutex_lock(&mutex); //Lock mutex before critical section

	int	account_balance = read_balance();
	account_balance += *((int *)amount);
	write_balance(account_balance);

	pthread_mutex_unlock(&mutex); //Unlock mutex after critical section

	return (NULL);
}