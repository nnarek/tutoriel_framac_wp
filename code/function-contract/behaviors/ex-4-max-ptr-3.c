/*@
  requires \valid_read(a) && \valid_read(b);
  assigns  \nothing ;

  behavior ab:
    assumes *a < *b;
    ensures \result == *b ;
  behavior ba:
    assumes *a > *b;
    ensures \result == *a ;

  // will make behaviors complete again
  // behavior eq:
  //   assumes *a == *b;
  //   ensures \result == *a ;
    
  ensures  \result == *a || \result == *b ;

  //complete behaviors;
  disjoint behaviors;
*/
int max_ptr(int* a, int* b){
  return (*a < *b) ? *b : *a ;
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
