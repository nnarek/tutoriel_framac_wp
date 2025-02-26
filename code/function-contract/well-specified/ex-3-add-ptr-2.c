/* run.config
   OPT:
*/

#include <limits.h>

/*@
  requires \valid(p) && \valid(q) && \valid(r);
  requires \separated(p,r) && \separated(q,r);
  requires INT_MIN <= *p + *q <= INT_MAX;

  assigns *r;

  ensures *r == *p + *q;
  ensures INT_MIN <= *r <= INT_MAX;
  ensures \valid(p) && \valid(q) && \valid(r);
*/
void add(int *p, int *q,int *r){
  *r = *p + *q ;
}

int main(){
  int a = 24 ;
  int b = 42 ;

  int x ;

  add(&a, &b, &x) ;
  //@ assert x == a + b ;
  //@ assert x == 66 ;

  add(&a, &a, &x) ;
  //@ assert x == a + a ;
  //@ assert x == 48 ;
}
