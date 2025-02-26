/* run.config
   OPT:
*/
/*@
  requires 0 <= y;

  assigns \nothing;

  behavior lp:
    assumes ((y % 4 == 0) && (y % 100 !=0)) || (y % 400==0);
    ensures \result==1;
  behavior no_lp:
    assumes (y % 400!=0) && ((y % 4 != 0) || (y % 100 ==0));
    ensures \result==0;

  complete behaviors;
  disjoint behaviors;
*/
int leap(int y){
  return ((y % 4 == 0) && (y % 100 !=0)) || (y % 400==0) ;
}

/*@
  requires 1 <= m <= 12;
  requires 0 <= y;

  assigns \nothing;

  behavior m31:
    assumes m \in {1,3,5,7,8,10,12};
    ensures \result==31;
  behavior m30:
    assumes m \in {4,6,9,11};
    ensures \result==30;
  behavior feb_leap:
    assumes m == 2 && (((y % 4 == 0) && (y % 100 !=0)) || (y % 400==0));
    ensures \result==29;
  behavior feb_noleap:
    assumes m == 2 && ((y % 400!=0) && ((y % 4 != 0) || (y % 100 ==0)));
    ensures \result==28;

  complete behaviors;
  disjoint behaviors;
*/
int days_of(int m, int y){
  int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } ;
  int n = days[m-1] ;
  if(m == 2 && leap(y)){
    return 29;
  } else {
    return n;
  }
}
