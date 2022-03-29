#include "selecao.h"
//=============================================================================
void selecao(uint64_t *array, uint64_t n){
    for (uint64_t i = 0; i < (n - 1); i++) {
      uint64_t menor = i;
      for (uint64_t j = (i + 1); j < n; j++){
         if (array[menor] > array[j]){
            menor = j;
         }
      }
      swap2(&array[menor], &array[i]);
   }
}
//=============================================================================