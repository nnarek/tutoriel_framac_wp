/* run.config
   OPT:
*/

enum Kind { VOWEL, CONSONANT };

/*@
  requires 'a' <= c <= 'z';

  assigns \nothing;

  behavior vowel:
    assumes c \in {'a','e','i','o','u','y'};
    ensures \result == VOWEL;

  behavior cons:
    assumes !(c \in {'a','e','i','o','u','y'});
    ensures \result == CONSONANT;

  complete behaviors;
  disjoint behaviors;
*/
enum Kind kind_of_letter(char c){
  switch(c) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'y':
      return VOWEL;
    default:
      return CONSONANT;
  }
}

/*@

  assigns \nothing;

  behavior q1:
    assumes 0 < x && 0 <= y;
    ensures \result == 1;

  behavior q4:
    assumes 0 < x && y < 0;
    ensures \result == 4;

  behavior q2:
    assumes x <= 0 && 0 < y;
    ensures \result == 2;

  behavior q3:
    assumes x <= 0 && y <= 0;
    ensures \result == 3;

  complete behaviors;
  disjoint behaviors;
*/
int quadrant(int x, int y){
  if(0 < x){
    if(0 <= y){
      return 1;
    } else {//y<0
      return 4;
    }
  } else {//x<=0
    if(0 < y){
      return 2;
    } else {//y<=0
      return 3;
    }
  }
}
