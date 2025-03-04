/* run.config
   OPT:
*/


/*@
  requires \valid_read(a) && \valid_read(b);

  assigns \nothing ;

  ensures \result \in {*a,*b};
  ensures *a <= \result && *b <= \result;
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
