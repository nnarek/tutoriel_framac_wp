/*@
  requires \valid(a) && \valid(b) && \valid(c) ;
  requires \separated(a, b, c);

  assigns *a, *b, *c ;

  behavior ab:
    assumes *a == *b < *c || *a == *c < *b || *b == *c < *a;
    ensures *a == *b  && *b != *c;
  behavior bc:
    assumes *a == *b > *c || *a == *c > *b || *b == *c > *a;
    ensures *b == *c && *a != *b;
  behavior eq_or_neq:
    assumes *a == *b && *b == *c || *a != *b && *b != *c && *a != *c ;

  ensures *a <= *b <= *c ;
  ensures { *a, *b, *c } == \old({ *a, *b, *c }) ;

  complete behaviors;
  disjoint behaviors;
*/
void order_3(int* a, int* b, int* c){
  if(*a > *b){ int tmp = *b ; *b = *a ; *a = tmp ; }
  if(*a > *c){ int tmp = *c ; *c = *a ; *a = tmp ; }
  if(*b > *c){ int tmp = *b ; *b = *c ; *c = tmp ; }
}
