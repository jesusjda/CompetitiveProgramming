/*@info_general
  author: jesus
  date: 25/04/2017
  id: 104 - Móviles
  url: https://www.aceptaelreto.com/problem/statement.php?id=104
  categories: preorder, long long, adhoc
*******************************************/

/*@info_submission
  time: 0.024s
  best: 
  rank: 63
  tries: 1
*/

/*@info_solution
  Lectura en preorder, calcular
*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <cstdio>

#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <algorithm> //max...
#include <utility> //pair
#include <complex>

#include <climits> //int, ll...
#include <limits> //double...
#include <cmath> //abs, atan...
#include <cstring> //memset
#include <string>

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> ll_ll;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

ll movil(){
  ll p1,d1,p2,d2;
  cin >> p1 >> d1 >> p2 >> d2;
  if(p1==0 && d1 == 0 && p2 == 0 && d2 == 0)
    return 0;
  if(p1 == 0)
    p1 = movil();
  if(p2 == 0)
    p2 = movil();
  ll I = p1 * d1;
  ll D = p2 * d2;
  if (p1 < 0 || p2 < 0)
    return -1;
  if (I == D)
    return p1 + p2;
  return -1;
}



int main(){
  ll p = movil();
  while(p != 0){
    if(p < 0)
      cout << "NO" << endl;
    else
      cout << "SI" << endl;
    p = movil();
  }
  return 0;
}
