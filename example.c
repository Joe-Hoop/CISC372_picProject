#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
void *func(int rank)
{
    printf("Hello from thread %d\n", rank);
    return NULL;
}
int main(int argc, char **argv)
{
    int thread_count = 0;
    printf("Input How many threads:\n");
    scanf("%d", &thread_count);
    pthread_t *thread_handles;
    thread_handles = (pthread_t *)malloc(thread_count * sizeof(pthread_t));
    for (int i = 0; i < thread_count; i++)
    {
        pthread_create(&thread_handles[i], NULL, &func, i);
    }

    for (int i = 0; i < thread_count; i++)
    {
        pthread_join(thread_handles[i], NULL);
    }
    free(thread_handles);
    return 0;
}