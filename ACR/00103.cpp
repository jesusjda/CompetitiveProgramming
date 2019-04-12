/*@info_general
  author: jesus
  date: 25/04/2017
  id: 103 - Problemas de Herencia
  url: https://www.aceptaelreto.com/problem/statement.php?id=103
  categories: doubles, adhoc
*******************************************/

/*@info_submission
  time: 0.088s
  best: 
  rank: 11
  tries: 1
*/

/*@info_solution
  Comprobar a mano, cuidado con epsilon
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



int grado;
double coefs[21];


double f(double x){
  double X = 1;
  double F = 0;
  for(int i = 0; i < grado+1; i++){
    F += X*coefs[i];
    X = X*x;
  }
  if(F <0) return 0;
  if(F> 1) return 1;
  return F;
}


int main(){
  int N;
  double eps = 0.001;
  cin >> grado;
  while(grado != 20){
    for(int i = grado; i >=0; i--){
      cin >> coefs[i];
    }
    cin >> N;
    double cain = 0;
    for(int i = 0; i < N; i++){
      cain += f(i /(1.0*N));
    }
    cain = cain /(1.0*N);
    //    cout << cain << " " << cain-0.5 << endl;
    if(cain - 0.5 >= eps)
      cout << "CAIN" << endl;
    else if (0.5 - cain >= eps)
      cout << "ABEL" << endl;
    else
      cout << "JUSTO" << endl;

    cin >> grado;
  }

  return 0;
}
