/* run.config
   OPT:
*/
/*@
  requires 1 <= month <= 12;

  ensures month \in {1,3,5,7,8,10,12} ==> \result==31;
  ensures month \in {4,6,9,11} ==> \result==30;
  ensures month == 2 ==> \result==28;
*/
int day_of(int month){
  int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } ;
  return days[month-1] ;
}
