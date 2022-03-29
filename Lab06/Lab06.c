#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
#include <stdint.h>
#include "bolha.h"
#include "insercao.h"
#include "selecao.h"
#include "selecao.h"

int main()
{
    clock_t start_time, end_time;
    double cpu_time_used, memory_used;
    size_t peakSize;
    struct rusage r_usage;
    srand(time(0));
    uint64_t *V;
    printf("V\tC\tT\tA\tN\tT\tM\n");
    for (uint64_t n = 2000; n <= 128000; n *= 2)
    {
        V = malloc(n * sizeof(uint64_t));

        // MELHOR CASO / JA ORDENADO
        //crescente2(V, n); printf("B\t");
        // PIOR CASO / DECRESCENTE
        //decrescente2(V, n); printf("W\t");
        // CASO MEDIO / PERMUTADO
        aleatorio2(V, n); printf("M\t");

        // BOLHA
        /*
        start_time = clock();
        bolha(V, n);
        end_time = clock();
        cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        getrusage(RUSAGE_SELF, &r_usage);
        printf("B\t%ld\t%0.2f\t%ld\n", n, cpu_time_used, r_usage.ru_maxrss);
        */
        // INSERCAO
        /*
        start_time = clock();
        insercao(V, n);
        end_time = clock();
        cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        getrusage(RUSAGE_SELF, &r_usage);
        printf("I\t%ld\t%0.2f\t%ld\n", n, cpu_time_used, r_usage.ru_maxrss);
        */
        // SELECAO
        
        start_time = clock();
        selecao(V, n);
        end_time = clock();
        cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        getrusage(RUSAGE_SELF, &r_usage);
        printf("S\t%ld\t%0.2f\t%ld\n", n, cpu_time_used, r_usage.ru_maxrss);
        
        
        free(V);
    }
}