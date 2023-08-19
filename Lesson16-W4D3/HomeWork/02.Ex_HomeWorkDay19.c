#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>

#define THREAD_NUM 16
#define MAX_SLEEP 5

sem_t semaphore;

void *routine(void *arg) {
    int id = *(int *)arg;
    
    printf("Thread %d is waiting in the queue.\n", id);
    
    sem_wait(&semaphore);
    
    printf("Thread %d entered the system.\n", id);
    
    int sleep_time = rand() % MAX_SLEEP + 1;
    sleep(sleep_time);
    
    sem_post(&semaphore);
    
    printf("Thread %d exited the system after %d seconds.\n", id, sleep_time);
    
    free(arg);
    
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[THREAD_NUM];
    int thread_ids[THREAD_NUM];
    
    sem_init(&semaphore, 0, 32); // Initialize semaphore with initial value 32
    
    for (int i = 0; i < THREAD_NUM; i++) {
        thread_ids[i] = i;
        
        pthread_create(&threads[i], NULL, routine, &thread_ids[i]);
    }
    
    for (int i = 0; i < THREAD_NUM; i++) {
        pthread_join(threads[i], NULL);
    }
    
    sem_destroy(&semaphore); // Destroy the semaphore
    
    return 0;
}
