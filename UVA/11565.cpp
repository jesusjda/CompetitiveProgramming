/*@info_general
author: Jesus Domenech
date: 25/02/2020
id: 11565 - Simple Equations
url: https://onlinejudge.org/external/115/11565.pdf
categories: 
*******************************************/

/*@info_submission
status: AC
time: 0.00
best: 0.000
rank: 1073
tries: 1
*/

/*@info_solution

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

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll, ll> ll_ll;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

#define REP(i, a, b) for(int i = int(a); i < int(b); i++)


int main(){
  // A, B , C <= 10000
  // x + y + z = A
  // x * y * z = B -> sqrt(10000,3) = 21,5 -> x in [-22...22]
  // x^2 + y^2 + z^2 = C  -> x,y,z in [-100...100]  
  int N, A, B, C;
  scanf("%d", &N);
  while(N--){
    scanf("%d %d %d", &A, &B, &C);
    //cout << A << " " << B << " " << C << endl;
    bool solution = false;
    for (int x = -22; x <= 22 && !solution; x++){
      if (x*x <= C){
        for (int y = -100; y <= 100 && !solution; y++){
          if (y != x && x*x + y*y <= C){
            for (int z = -100; z <= 100 && !solution; z++){
              if (z != x && z != y && 
                  x+y+z == A && 
                  x*y*z == B &&
                  x*x + y*y + z*z == C){
                    printf("%d %d %d\n", x, y, z);
                    solution = true;
                  }
            }
          }
          //cout << "y: " << y << endl;
        }
      }
      //cout << x << endl;
    }
    //cout << "hello"<< endl;
    if (!solution)
      printf("No solution.\n");

  }
  return 0;
}
