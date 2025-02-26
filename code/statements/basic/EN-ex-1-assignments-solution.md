```c
/*@
  requires -10 <= x <= 0 ;
  requires 0 <= y <= 5 ;
  ensures -10 <= \result <= 10 ;
*/
int function(int x, int y){
  int res ;
  y += 10 ;
  x -= 5 ;
  res = x + y ;
  return res ;
}
```


we need to find weakest preconditions so that postcondition holds at the of function
from last line we can conclude that 
    -10 <= x+y <= 10
jumping one line above we can conclude that 
    -10 <= x-5+y <= 10
when x is a new variale and at differs from x of next line
jumping one line above we will get final weakest precondition for given program and given postcondition
    -10 <= x-5+y+10 <= 10
which is same as
    -15 <= x+y <= 5
