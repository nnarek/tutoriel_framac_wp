/* run.config
   OPT:
*/
#include <limits.h>

/*@  
  requires \valid(q) && \valid(r) && \separated(q, r);
  requires 0 <= x <= UINT_MAX;
  requires 0 < y <= UINT_MAX;

  assigns *q,*r;

  //ensures *q == x/y + x%y; //TODO why this does not work? is x/y returns rational number?
  //ensures *r == x%y;
  ensures x == (*q)*y + *r;
  ensures 0 <= *r < y;
  ensures 0 <= *q <= UINT_MAX;
  ensures 0 <= *r <= UINT_MAX;
  ensures \valid(q) && \valid(r) && \separated(q, r);
*/
void div_rem(unsigned x, unsigned y, unsigned* q, unsigned* r){
  *q = x / y ;
  *r = x % y ;
}
