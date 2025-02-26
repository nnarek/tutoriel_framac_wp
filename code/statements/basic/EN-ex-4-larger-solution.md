```c
/*@ 
  requires -5 <= y <= 5 ; 
  requires -5 <= x <= 5 ; 
  ensures  -15 <= \result <= 25 ;
*/
int function(int x, int y){
  int res ;

  if(x < 0){
    x = 0 ;
  }
  
  if(y < 0){
    x += 5 ;
  } else {
    x -= 5 ;
  }
  
  res = x - y ;

  return res ;
}
```


```-15 ≤ res ≤ 25.

-15 ≤ x-y ≤ 25.

(y<0 ==> wp(x+=5,-15 ≤ x-y ≤ 25)) && (y≥0 ==> wp(x-=5,-15 ≤ x-y ≤ 25)) = (y<0 ==> -20 ≤ x-y ≤ 20) && (y≥0 ==> -10 ≤ x-y ≤ 30).

[x<0 ==> (y<0 ==> -20 ≤ 0-y ≤ 20) && (y≥0 ==> -10 ≤ 0-y ≤ 30)] && [x≥0 ==> (y<0 ==> -20 ≤ x-y ≤ 20) && (y≥0 ==> -10 ≤ x-y ≤ 30)] =

[x<0 ==> (y<0 ==> 0 < -y ≤ 20) && (y≥0 ==> -10 ≤ -y ≤ 0)] && [x≥0 ==> (y<0 ==> 0 < x-y ≤ 20) && (y≥0 ==> -10 ≤ x-y ≤ 30)] =  

[x<0 ==> (y<0 ==> -20 < y ≤ 0) && (y≥0 ==> 0 ≤ y ≤ 10)] && [x≥0 ==> (y<0 ==> 0 < x-y ≤ 20) && (y≥0 ==> -10 ≤ x-y ≤ 30)] = 

x<0 ==> y<0 ==> -20 < y ≤ 0

x<0 ==> y≥0  ==> 0 ≤ y ≤ 10

x≥0 ==> y<0 ==> 0 < x-y ≤ 20

x≥0 ==> y≥0 ==> -10 ≤ x-y ≤ 30
```

we need to prove that precondition of program satisfies to all this 4 conditions

in first case spec requires that -5 <= y < 0 and -5 <= x < 0 which is satisfiable

in second case spec requires that 0 <= y < 5 and -5 <= x < 0 which is satisfiable

in third case spec requires that -5 <= y < 0 and 0 <= x < 5 which is satisfiable

in forth case spec requires that -5 <= y < 0 and -5 <= x < 0 which is satisfiable
