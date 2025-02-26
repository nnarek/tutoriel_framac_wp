/* run.config
   OPT:
*/

#include <limits.h>

/*@
  requires 0 < first < 180;
  requires 0 < second < 180;
  requires 0 < 180 - first - second < 180;
  
  ensures first + second + \result == 180;
  ensures 0 < \result < 180; //actually not needed
*/
int last_angle(int first, int second){
  return 180 - first - second ;
}
