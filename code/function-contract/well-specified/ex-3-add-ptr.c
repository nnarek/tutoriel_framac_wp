/* run.config
   OPT:
*/

#include <limits.h>

/*@
  requires \valid(p) && \valid(q);
  requires INT_MIN <= *p + *q <= INT_MAX;

  assigns \nothing;

  ensures \result == *p + *q;
  ensures \valid(p) && \valid(q);
*/
int add(int *p, int *q){
  return *p + *q ;
}

int main(){
  int a = 24 ;
  int b = 42 ;

  int x ;

  x = add(&a, &b) ;
  //@ assert x == a + b ;
  //@ assert x == 66 ;

  x = add(&a, &a) ;
  //@ assert x == a + a ;
  //@ assert x == 48 ;
}
