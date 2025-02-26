/* run.config

   OPT:
*/

/*@
  requires \valid(a) && \valid(b) && \valid(c);
  requires \separated(a, b, c);

  assigns *a,*b,*c;

  //following two assertions does not make full specification because if old values is 4,5,5 then new values can be 4,4,5
  
  ensures {*a,*b,*c} == \old({*a,*b,*c});
  ensures *a <= *b <= *c;  

  ensures *a==\old(*a) ==> {*b,*c} == \old({*b,*c}); 
  ensures *a==\old(*b) ==> {*b,*c} == \old({*a,*c}); 
  ensures *a==\old(*c) ==> {*b,*c} == \old({*a,*b}); 

  //using quantifiers or inductive predicates we can more easily describe condition when two arrays are permutation of each other
*/
void order_3(int* a, int* b, int* c){
  if(*b < *a) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
  if(*c < *b) {
    int temp = *b;
    *b = *c;
    *c = temp;
  }
  if(*b < *a) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
}


void test(){
  int a1 = 5, b1 = 3, c1 = 4 ;
  order_3(&a1, &b1, &c1) ;
  //@ assert a1 == 3 && b1 == 4 && c1 == 5 ;

  int a2 = 2, b2 = 2, c2 = 2 ;
  order_3(&a2, &b2, &c2) ;
  //@ assert a2 == 2 && b2 == 2 && c2 == 2 ;

  int a3 = 4, b3 = 3, c3 = 4 ;
  order_3(&a3, &b3, &c3) ;
  //@ assert a3 == 3 && b3 == 4 && c3 == 4 ;

  int a4 = 4, b4 = 5, c4 = 4 ;
  order_3(&a4, &b4, &c4) ;
  //@ assert a4 == 4 && b4 == 4 && c4 == 5 ;
}
