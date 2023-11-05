#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <pthread.h>

typedef struct {
    int *values;
    int size;
    int target;
    int thread_id;
    int num_threads;
    pthread_barrier_t *barrier;
    int *result_index; // Utiliser un pointeur pour stocker le résultat
} ThreadData;

void *grover_parallel_iteration(void *arg) {
    ThreadData *data = (ThreadData *)arg;

    // Rechercher la valeur cible dans la partie du tableau assignée à ce thread
    for (int i = data->thread_id; i < data->size; i += data->num_threads) {
        if (data->values[i] == data->target) {
            // Stocker l'index dans le résultat et terminer le thread
            *(data->result_index) = i;
            pthread_barrier_wait(data->barrier);
            pthread_exit(NULL);
        }
    }

    // Synchroniser les threads
    pthread_barrier_wait(data->barrier);

    pthread_exit(NULL);
}

int grover_parallel_algorithm(int size, int target, int num_threads, int *values) {
    pthread_t *threads = (pthread_t *)malloc(num_threads * sizeof(pthread_t));
    pthread_barrier_t barrier;
    pthread_barrier_init(&barrier, NULL, num_threads);

    int result_index = -1; // Variable pour stocker l'index de la première occurrence de la valeur cible
    // Pointeur vers la variable résultat
    int *result_pointer = &result_index;

    ThreadData *thread_data = (ThreadData *)malloc(num_threads * sizeof(ThreadData));
    for (int i = 0; i < num_threads; i++) {
        thread_data[i].values = values;
        thread_data[i].size = size;
        thread_data[i].target = target;
        thread_data[i].thread_id = i;
        thread_data[i].num_threads = num_threads;
        thread_data[i].barrier = &barrier;
        thread_data[i].result_index = result_pointer; // Passer le pointeur
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, grover_parallel_iteration, (void *)&thread_data[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    free(threads);
    free(thread_data);
    pthread_barrier_destroy(&barrier);

    return result_index;
}