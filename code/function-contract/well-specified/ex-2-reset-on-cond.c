/* run.config
   OPT:
*/

/*@
  requires \valid(a) && \valid_read(b) && \separated(a,b);

  assigns *a;

  ensures *b ==> *a == 0; //I already mentioned than only *a can be changed in this function, so it is safe to use *b instead of \old(*b)
  ensures !(*b) ==> *a == \old(*a);
  ensures \valid(a) && \valid_read(b) && \separated(a,b);
*/
void reset_1st_if_2nd_is_true(int* a, int const* b){
  if(*b) *a = 0 ;
}

int main(){
  int a = 5 ;
  int x = 0 ;

  reset_1st_if_2nd_is_true(&a, &x);
  //@ assert a == 5 ;
  //@ assert x == 0 ;

  int const b = 1 ;

  reset_1st_if_2nd_is_true(&a, &b);
  //@ assert a == 0 ;
  //@ assert b == 1 ;
}
