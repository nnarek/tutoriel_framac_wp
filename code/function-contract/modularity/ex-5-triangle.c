/* run.config
   OPT:
*/

#include <limits.h>

enum Sides { SCALENE, ISOSCELE, EQUILATERAL };
enum Angles { RIGHT, ACUTE, OBTUSE };

struct TriangleInfo {
  enum Sides sides;
  enum Angles angles;
};


/*@
  requires 0 < a < b + c;
  requires 0 < b <= a;
  requires 0 < c <= a;
  
  assigns \nothing;

  behavior eq:
    assumes {a,b,c} == {a};
    ensures \result == EQUILATERAL;
  behavior is:
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


/*@
  requires 0 < a < b + c;
  requires 0 < b <= a;
  requires 0 < c <= a;
  requires 0 < b*b <= INT_MAX;
  requires INT_MIN <= a*a - c*c <= INT_MAX;
  requires INT_MIN <= a+c <= INT_MAX;
  requires INT_MIN <= a-c <= INT_MAX;

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
  if((a-c)*(a+c) == b*b){
    return RIGHT;
  } else if((a-c)*(a+c) > b*b){
    return OBTUSE;
  } else {
    return ACUTE;
  }
}

/*@
  requires 0 < b*b <= INT_MAX;
  requires INT_MIN <= a*a - c*c <= INT_MAX;
  requires INT_MIN <= a+c <= INT_MAX;
  requires INT_MIN <= a-c <= INT_MAX;
  requires \valid(info);

  assigns *info;

  behavior ok:
    assumes 0 < a < b + c && 0 < b <= a && 0 < c <= a;
    ensures \result == 0;
  behavior bad:
    assumes !(0 < a < b + c && 0 < b <= a && 0 < c <= a);
    ensures \result == -1;

  behavior rg:
    assumes 0 < a < b + c && 0 < b <= a && 0 < c <= a;
    assumes a*a == b*b + c*c;
    ensures info->angles == RIGHT;
  behavior ob:
    assumes 0 < a < b + c && 0 < b <= a && 0 < c <= a;
    assumes a*a > b*b + c*c;
    ensures info->angles == OBTUSE;
  behavior ac:
    assumes 0 < a < b + c && 0 < b <= a && 0 < c <= a;
    assumes a*a < b*b + c*c;
    ensures info->angles == ACUTE;

  behavior eq:
    assumes 0 < a < b + c && 0 < b <= a && 0 < c <= a;
    assumes {a,b,c} == {a};
    ensures info->sides == EQUILATERAL;
  behavior is:
    assumes 0 < a < b + c && 0 < b <= a && 0 < c <= a;
    assumes {a,b,c} != {a} && (a==b || a==c || b==c);
    ensures info->sides == ISOSCELE;
  behavior sc:
    assumes 0 < a < b + c && 0 < b <= a && 0 < c <= a;
    assumes a != b && a != c && b != c;
    ensures info->sides == SCALENE;

  disjoint behaviors ok,bad;
  complete behaviors ok,bad;

  disjoint behaviors rg,ob,ac,bad;
  complete behaviors rg,ob,ac,bad;

  disjoint behaviors eq,is,sc,bad;
  complete behaviors eq,is,sc,bad;
*/
int classify(int a, int b, int c, struct TriangleInfo* info){
  if(0 < a && a - c < b && 0 < b && b <= a && 0 < c && c <= a){
    info->sides = sides_kind(a,b,c);
    info->angles = angles_kind(a,b,c); 
    return 0;
  }
  return -1;
}
