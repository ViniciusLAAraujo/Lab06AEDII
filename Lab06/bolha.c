#include "geracao.h"
#include "bolha.h"
#include <stdio.h>
//=============================================================================
void bolha(uint64_t *array, uint64_t n){
    uint64_t i, j;
    for (i = (n - 1); i > 0; i--) {
      for (j = 0; j < i; j++) {
         if (array[j] > array[j + 1]) {
            swap2(&array[j], &array[j + 1]);
         }
      }
   }
}
//=============================================================================