/* run.config
   DONTRUN:
*/

/* Generated by Frama-C */
#include <stddef.h>
int *search(int *array, size_t length, int element)
{
  int *__retres;
  {
    size_t i = (unsigned int)0;
    while (i < length) {
      /*@ assert rte: mem_access: \valid_read(array + i); */
      if (*(array + i) == element) {
        __retres = array + i;
        goto return_label;
      }
      i += (size_t)1;
    }
  }
  __retres = (int *)0;
  return_label: return __retres;
}
