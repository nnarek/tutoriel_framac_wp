/* run.config
   OPT:
*/

enum note { N500, N200, N100, N50, N20, N10, N5, N2, N1 };
int const values[] = { 500, 200, 100, 50, 20, 10, 5, 2, 1 };

/*@
  requires 0 <= n < 9;
  requires 0 <= *rest;
  requires \valid(rest);
  requires \valid_read(values + (0 .. 8));
  requires \separated(rest, values + (0 .. 8));//suggested by frama-c as warning

  assigns *rest;

  ensures \result * values[n] <= \old(*rest);
  ensures \old(*rest) < (\result + 1) * values[n];
  
  ensures \old(*rest) == \result * values[n] + *rest;
*/
int remove_max_notes(enum note n, int* rest){
  int old_rest = *rest;
  *rest = *rest % values[n];
  return (old_rest - *rest) / values[n];
}

/*@
  requires 0 <= amount;
  requires 0 <= received;
  requires \valid(change+(0 .. 8));

  assigns change[0 .. 8];

  behavior invalid:
    assumes received < amount;
    ensures \result == -1;
  
  behavior valid:
    assumes received >= amount;
    ensures \result == 0;
    //ensures \at(rest,Post) == 0;
    ensures change[N500]*values[N500] +
            change[N200]*values[N200] + 
            change[N100]*values[N100] + 
            change[N50]*values[N50] + 
            change[N20]*values[N20] + 
            change[N10]*values[N10] + 
            change[N5]*values[N5] + 
            change[N2]*values[N2] +
            change[N1]*values[N1] == received - amount; 
    ensures 0 <= change[N1]*values[N1] < values[N2] &&
            0 <= change[N2]*values[N2] < values[N5] &&
            0 <= change[N5]*values[N5] < values[N10] &&
            0 <= change[N10]*values[N10] < values[N20] &&
            0 <= change[N20]*values[N20] < values[N50] &&
            0 <= change[N50]*values[N50] < values[N100] &&
            0 <= change[N100]*values[N100] < values[N200] &&
            0 <= change[N200]*values[N200] < values[N500] &&
            0 <= change[N500]*values[N500] <= received - amount;
  
  complete behaviors;
  disjoint behaviors;
*/
int make_change(int amount, int received, int change[9]){
  if(received < amount){
    return -1;
  }
  int rest = received - amount;

  change[N500] = remove_max_notes(N500, &rest);
  change[N200] = remove_max_notes(N200, &rest);
  change[N100] = remove_max_notes(N100, &rest);
  change[N50] = remove_max_notes(N50, &rest);
  change[N20] = remove_max_notes(N20, &rest);
  change[N10] = remove_max_notes(N10, &rest);
  change[N5] = remove_max_notes(N5, &rest);
  change[N2] = remove_max_notes(N2, &rest);
  change[N1] = rest;
  return 0;
}
