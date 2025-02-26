
#include <limits.h>


/*@
  requires a==0 || \valid_read(a);
  requires b==0 || \valid_read(b);
  assigns  \nothing ;

  behavior nn:
    assumes a == 0 && b == 0; 
    ensures \result == INT_MIN;
  behavior nb: 
    assumes a == 0 && b != 0;
    ensures \result == *b;
  behavior an: 
    assumes a != 0 && b == 0;
    ensures \result == *a;
  behavior ab:
    assumes a != 0 && b != 0;
    assumes *a < *b;
    ensures \result == *b ;
  behavior ba:
    assumes a != 0 && b != 0;
    assumes *a >= *b;
    ensures \result == *a ;
    
  ensures  \result == *a || \result == *b || \result == INT_MIN ;

  complete behaviors;
  disjoint behaviors;
*/
int max_ptr(int* a, int* b){
  if(a){
    if(b){
      return (*a < *b) ? *b : *a ;
    }
    else{
      return *a;
    }
  } else if (b){
    return *b;
  } else {
    return INT_MIN;
  }
}

extern int h ;

int main(){
  h = 42 ;

  int a = 24 ;
  int b = 42 ;

  int x = max_ptr(&a, &b) ;

  //@ assert x == 42 ;
  //@ assert h == 42 ;
}
