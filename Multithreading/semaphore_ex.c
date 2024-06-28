#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


sem_t sem1;
sem_t sem2;

void* thread1_func(void* arg) {
    while (1) {
        
        sem_wait(&sem1);  // Wait for semaphore 1 to be signaled
        printf("Thread 1 is running\n");
        sem_post(&sem2);  // Signal semaphore 2
    }
    return NULL;
}

void* thread2_func(void* arg) {
    while (1) {
        sleep(2);
        sem_wait(&sem2);  // Wait for semaphore 2 to be signaled
        printf("Thread 2 is running\n");
        sem_post(&sem1);  // Signal semaphore 1
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    printf("Semaphore Program");
    // Initialize semaphores
    sem_init(&sem1, 0, 1);  // Initial value is 1
    sem_init(&sem2, 0, 0);  // Initial value is 0

    // Create threads
    pthread_create(&thread1, NULL, thread1_func, NULL);
    pthread_create(&thread2, NULL, thread2_func, NULL);

    // Wait for threads to finish (this won't happen in this example as the threads run indefinitely)
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Destroy semaphores
    sem_destroy(&sem1);
    sem_destroy(&sem2);

    return 0;
}
