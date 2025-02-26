/* run.config
   OPT:
*/


/*@
  requires \valid(a) && \valid(b);

  assigns *a,*b;

  ensures {*a,*b} == {\old(*a),\old(*b)};
  ensures *b <= *a; 

  ensures *b <= \old(*a) && *b <= \old(*b); // redundant spec
  ensures \old(*a) <= *a && \old(*b) <= *a; // redundant spec
*/
void max_ptr(int* a, int* b){
  if(*a < *b) {
    // Alt-Ergo not able to verify this implementation
    // *a = *a ^ *b;
    // *b = *a ^ *b;
    // *a = *a ^ *b;
    
    int temp = *a;
    *a = *b;
    *b = temp;
  } 
}

extern int h ;

int main(){
  h = 42 ;

  int a = 24 ;
  int b = 42 ;

  max_ptr(&a, &b) ;

  //@ assert a == 42 ;
  //@ assert b == 24 ;
  //@ assert h == 42 ;
}
