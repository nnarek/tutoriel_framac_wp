/*@ requires n >= 0 ;
    decreases n ;
*/
void ends(int n){
  if(n > 0) ends(n-1);
}

/*@ requires n >= -10 ;
    decreases n ; */
void go_negative(int n){
  if(n >= 0) go_negative(n-10); // if n is 0, this call is rec(-10), it is fine
}

/*@ requires n >= 0 ;
    decreases n ;
*/
void ends_2(int n){
  if(n > 0) ends_2(n-1); // Ok: 0 <= n && n-1 < n
  if(n > 0) ends_2(n-1); // Ok: 0 <= n && n-1 < n, no need to be less than call on l.5
}

/*@ requires \valid(p) && *p >= 0 ;
    decreases *p ;
*/
void ends_ptr(int *p){
  if(*p > 0){
    (*p)-- ;
    ends_ptr(p); // Ok: 0 <= \at(*p, Pre) && *p < \at(*p, Pre)
  }
}

//@ decreases v ;
void single(unsigned v){
  if(v > 0) single(v-1); // OK: 0 <= v && v-1 < v
}

//@ decreases k-1 ;
void mutual_2(unsigned k);

//@ decreases n ;
void mutual_1(unsigned n){
  if(n > 1) mutual_2(n-1); // OK: 0 <= n && (n-1)-1 < n
}

void mutual_2(unsigned k){
  if(k > 1) mutual_1(k-2); // OK: 0 <= k-1 && (k-2) < k-1
  single(k+1) ; // no verification needed, single is not in the cluster
}

void fail_mutual_1(unsigned k);

//@ decreases k ;
void fail_mutual_2(unsigned k){
  if(k > 0) fail_mutual_1(k-1);
}
/* Warning:
  [wp] file.c:5: Warning:
    Missing decreases clause on recursive function fail_mutual_1, call must be unreachable
*/

void fail_mutual_1(unsigned k){
  if(k > 0) fail_mutual_2(k-1);
}
