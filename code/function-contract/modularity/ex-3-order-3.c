/* run.config
   OPT:
*/
/*@
  requires \valid(a) && \valid(b);

  assigns *a,*b;

  behavior ab:
    assumes *a < *b;
    ensures *a == \old(*b) && *b == \old(*a);  
  behavior ba:
    assumes *b <= *a;
    ensures *a == \old(*a) && *b == \old(*b);  

  ensures {*a,*b} == \old({*a,*b});
  ensures *b <= *a;

  complete behaviors;
  disjoint behaviors;
*/
void max_ptr(int* a, int* b){
  if(*a < *b){
    int tmp = *b ;
    *b = *a ;
    *a = tmp ;
  }
}
/*@
  requires \valid(a) && \valid(b);

  assigns *a,*b;

  behavior ab:
    assumes *a < *b;
    ensures *a == \old(*a) && *b == \old(*b);  
  behavior ba:
    assumes *b <= *a;
    ensures *a == \old(*b) && *b == \old(*a);  
  
  ensures {*a,*b} == \old({*a,*b});
  ensures *a <= *b;

  complete behaviors;
  disjoint behaviors;
*/
void min_ptr(int* a, int* b){
  max_ptr(b,a);
}

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
void order_3_inc_max(int* a, int* b, int* c){
  max_ptr(c,b);
  max_ptr(b,a);
  max_ptr(c,b);
}


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
void order_3_inc_min(int* a, int* b, int* c){
  min_ptr(b,c);
  min_ptr(a,b);
  min_ptr(b,c);
}

/*@
  requires \valid(a) && \valid(b) && \valid(c) ;
  requires \separated(a, b, c);

  assigns *a, *b, *c ;


  behavior ab:
    assumes *b == *a > *c || *c == *b > *a || *c == *a > *b;
    ensures *b == *a && *c != *b;
  behavior cb:
    assumes *b == *a < *c || *c == *b < *a || *c == *a < *b;
    ensures *c == *b  && *b != *a;
  behavior eq_or_neq:
    assumes *c == *b && *b == *a || *c != *b && *b != *a && *c != *a ;

  ensures *c <= *b <= *a ;
  ensures { *a, *b, *c } == \old({ *a, *b, *c }) ;

  complete behaviors;
  disjoint behaviors;
*/
void order_3_dec_max(int* a, int* b, int* c){
  max_ptr(b,c);
  max_ptr(a,b);
  max_ptr(b,c);
}

/*@
  requires \valid(a) && \valid(b) && \valid(c) ;
  requires \separated(a, b, c);

  assigns *a, *b, *c ;


  behavior ab:
    assumes *b == *a > *c || *c == *b > *a || *c == *a > *b;
    ensures *b == *a && *c != *b;
  behavior cb:
    assumes *b == *a < *c || *c == *b < *a || *c == *a < *b;
    ensures *c == *b  && *b != *a;
  behavior eq_or_neq:
    assumes *c == *b && *b == *a || *c != *b && *b != *a && *c != *a ;

  ensures *c <= *b <= *a ;
  ensures { *a, *b, *c } == \old({ *a, *b, *c }) ;

  complete behaviors;
  disjoint behaviors;
*/
void order_3_dec_min(int* a, int* b, int* c){
  min_ptr(b,a);
  min_ptr(c,b);
  min_ptr(b,a);
}
