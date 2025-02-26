/* run.config
   OPT:
*/

#include <limits.h>

enum Sides { SCALENE, ISOSCELE, EQUILATERAL };
enum Angles { RIGHT, ACUTE, OBTUSE };


/*@
  requires 0 <= a;
  requires 0 <= b;
  requires 0 <= c;

  assigns \nothing;

  behavior eq:
    assumes {a,b,c} == {a};
    ensures \result == EQUILATERAL;
  behavior is:
    //assumes {a,b,c} != {a} && {a,b,c} \in { {a,b}, {a,c}, {b,c} }; // have no set of sets yet
    assumes {a,b,c} != {a} && (a==b || a==c || b==c);
    ensures \result == ISOSCELE;
  behavior sc:
    assumes a != b && a != c && b != c;
    ensures \result == SCALENE;

  complete behaviors;
  disjoint behaviors;
*/
enum Sides sides_kind(int a, int b, int c){
  if (a == b){
    if(a == c){
      return EQUILATERAL;
    } else {
      return ISOSCELE;
    }
  } else {
    if(a == c || b == c){
      return ISOSCELE;
    } else {
      return SCALENE;
    }
  }
}

//after solving I notice that we can compare a*a-c*c==b*b to have weaker precondition
/*@
  requires 0 < a < b + c;
  requires 0 < b <= a;
  requires 0 < c <= a;
  requires 0 < a*a <= INT_MAX;
  requires INT_MIN <= b*b + c*c <= INT_MAX;

  assigns \nothing;

  behavior rg:
    assumes a*a == b*b + c*c;
    ensures \result == RIGHT;
  behavior ob:
    assumes a*a > b*b + c*c;
    ensures \result == OBTUSE;
  behavior ac:
    assumes a*a < b*b + c*c;
    ensures \result == ACUTE;

  complete behaviors;
  disjoint behaviors;
*/
enum Angles angles_kind(int a, int b, int c){
  if(a*a == b*b + c*c){
    return RIGHT;
  } else if(a*a > b*b + c*c){
    return OBTUSE;
  } else {
    return ACUTE;
  }
}
