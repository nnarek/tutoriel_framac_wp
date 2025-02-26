/* run.config
   OPT:
*/

#include <limits.h>

/*@
  requires a<b ==> (INT_MIN <= b-a <= INT_MAX);
  requires b<a ==> (INT_MIN <= a-b <= INT_MAX);
  ensures a<b ==> \result == b-a;
  ensures b<a ==> \result == a-b;
*/
int distance(int a, int b){
  if(a < b) return b - a ;
  else return a - b ;
}
