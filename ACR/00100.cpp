/*@info_general
  author: jesus
  date: 04/04/2017
  id: 100 - Constante de Kaprekar
  url: https://www.aceptaelreto.com/problem/statement.php?id=100
  categories: simulation, 
*******************************************/

/*@info_submission
  time: 0.444s
  best: 
  rank: 508
  tries: 1
*/

/*@info_solution
  Simular el proceso y contar el número de pasos.
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

void int2Arr(int n,int num[]){
  for(int i=0; i < 4;i++){
    num[i] = n % 10;
    n = n / 10;
  }
}

int main(){
  int T;
  cin >> T;

  int num[4];
  while(T--){
    int x;
    cin >> x;
    int2Arr(x,num);

    if(x==6174){
      cout << '0' << endl;         
    }else if(num[0]==num[1] && num[1] == num[2] && num[2] == num[3]){
      cout << '8' << endl;    
    }else{
      int counter = 0;
      do{

	sort(num,num+4);
	//cout << num[0] << num[3] << endl;
	int asc = num[0] * 1000 + num[1] * 100 + num[2] * 10 + num[3];

	int des = num[3] * 1000 + num[2] * 100 + num[1] * 10 + num[0];

	x=des-asc;
	counter++;
 
	int2Arr(x,num);
      }while(x!=6174);

      cout<<counter<<endl;
    }
  }

  return 0;
}
