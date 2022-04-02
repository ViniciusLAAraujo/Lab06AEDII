#include "insercao.h"
//=============================================================================
void insercao(uint64_t *array, uint64_t n){
    for (uint64_t i = 1; i < n; i++) {
      uint64_t tmp = array[i];
      uint64_t j = i-1;

      while ((j >= 0) && (array[j] > tmp)) {
         array[j + 1] = array[j];
         if(j == 0) break;
         j--;
         
      }
      array[j+1] = tmp;
   }
}
//=============================================================================
