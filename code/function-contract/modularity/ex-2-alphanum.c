/* run.config
   OPT:
*/

/*@

  assigns \nothing;

  behavior low:
    assumes 'a' <= c <= 'z';
    ensures \result == 1;

  behavior no_low:
    assumes c < 'a' || 'z' < c;
    ensures \result == 0;

  complete behaviors;
  disjoint behaviors;
*/
int is_lower_alpha(char c){
  return 'a' <= c && c <= 'z';
}

/*@

  assigns \nothing;

  behavior up:
    assumes 'A' <= c <= 'Z';
    ensures \result == 1;

  behavior no_up:
    assumes c < 'A' || 'Z' < c;
    ensures \result == 0;

  complete behaviors;
  disjoint behaviors;
*/
int is_upper_alpha(char c){
  return 'A' <= c && c <= 'Z';
}

/*@

  assigns \nothing;

  behavior dig:
    assumes '0' <= c <= '9';
    ensures \result == 1;

  behavior no_dig:
    assumes c < '0' || '9' < c;
    ensures \result == 0;

  complete behaviors;
  disjoint behaviors;
*/
int is_digit(char c){
  return '0' <= c && c <= '9';
}

/*@

  assigns \nothing;

  behavior t:
    assumes 'a' <= c <= 'z' || 'A' <= c <= 'Z' || '0' <= c <= '9';
    ensures \result == 1;

  behavior f:
    assumes !('a' <= c <= 'z' || 'A' <= c <= 'Z' || '0' <= c <= '9');
    ensures \result == 0;

  complete behaviors;
  disjoint behaviors;
*/
int is_alpha_num(char c){
  return
    is_lower_alpha(c) ||
    is_upper_alpha(c) ||
    is_digit(c) ;
}


enum Kind { 
  LOWER, 
  UPPER, 
  DIGIT, 
  OTHER 
};

/*@

  assigns \nothing;

  behavior low:
    assumes 'a' <= c <= 'z';
    ensures \result == LOWER;

  behavior up:
    assumes 'A' <= c <= 'Z' ;
    ensures \result == UPPER;

  behavior dig:
    assumes '0' <= c <= '9' ;
    ensures \result == DIGIT;

  behavior oth:
    assumes !('a' <= c <= 'z' || 'A' <= c <= 'Z' || '0' <= c <= '9');
    ensures \result == OTHER;

  complete behaviors;
  disjoint behaviors;
*/
enum Kind character_kind(char c){
  if(is_lower_alpha(c)){
    return LOWER;
  } else if (is_upper_alpha(c)){
    return UPPER;
  } else if(is_digit(c)){
    return DIGIT;
  } else {
    return OTHER;
  }
}
