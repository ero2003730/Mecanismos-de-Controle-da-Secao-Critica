#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>

#define forever 100000000 // 10^8
#define num_clients 4

volatile int request = 0, respond = 0;
volatile int sum = 0;

void client_function(int i)
{
    int aux = 0;

    while (aux < forever)
    {
        // Pre-protocol
        while (respond != i)
        {
            request = i;
        }

        // Critical section
        int local = sum;
        sleep(rand() % 2);
        sum = local + 1;

        printf("Final sum: %d\n", sum);

        // Post-protocol
        respond = 0;

        aux++;
    }
}

void server_function()
{
    int aux = 0;

    while (aux < forever * num_clients)
    {
        // Await a request
        while (request == 0)
            continue;

        // Grant access to the critical section
        respond = request;

        // Wait for the critical section to be vacated
        while (respond != 0)
            continue;

        request = 0;
        aux++;
    }
}

int main()
{
#pragma omp parallel num_threads(num_clients + 1)
    {
        int tid = omp_get_thread_num();

        if (tid == 0)
        {
            server_function();
        }
        else
        {
            client_function(tid);
        }
    }

    return 0;
}
