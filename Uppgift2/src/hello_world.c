#include <pthread.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

#define N_PTHREADS (10)
#define UPDATE_COUNT 2000
int count;

void *print_hello(void *p)
{
	int i, tmp;
    intptr_t thread_n;
	thread_n = (intptr_t)p;
	//printf("Hello! I'm thread #%ti\n", thread_n);
    for (i = 0; i < UPDATE_COUNT; i++){
        tmp = count;
        count = tmp + 1;
    }
	return NULL;
}

int main()
{
	pthread_t thread_ids[N_PTHREADS];
    void **retval;
	int ret;
	intptr_t i;
	for (i = 0; i < N_PTHREADS; i++) {
		//printf("Creating thread #%ti\n", i);

		ret = pthread_create(&thread_ids[i], NULL, print_hello, (void *)i);
		if (ret != 0) {
			printf("ERROR: pthread_create() returned %i\n", ret);
			return -1;
		}
	}

    for(i = 0; i < N_PTHREADS; i++){
        pthread_join(thread_ids[i], retval);
    }
    printf("Numer of threads: %d\n", N_PTHREADS);
    printf("UPDATE_COUNT: %d\n", UPDATE_COUNT);
    printf("Expected value of count: %d\nActual value of count; %d\n", UPDATE_COUNT*N_PTHREADS, count);
}
