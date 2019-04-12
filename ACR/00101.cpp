/*@info_general
  author: jesus
  date: 05/04/2017
  id: 101 - Cuadrados diabólicos y esotéricos
  url: https://www.aceptaelreto.com/problem/statement.php?id=101
  categories: matrix, adhoc
*******************************************/

/*@info_submission
  time: 0.268s
  best: 
  rank: 24
  tries: 1
*/

/*@info_solution
  Comprobar las dos definiciones.
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




int main(){
  int N;
  cin >> N;
  while (N != 0){
    int a;
    long int cm=0, cm2=0, esq=0, cen=0,lad=0;
    long int fila[1024], columna[1024], diagonal[2];
    bool diabolico = true, esoterico = true, impar=(N%2==1);
    bool num[1024*1024];
    diagonal[0]=0;
    diagonal[1]=0;
    for(int i = 0; i < N; i++){
      fila[i] = 0;
      columna[i] = 0;
      for(int j = 0; j < N; j++){
	num[i+N*j] = false;
      }
    }
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
	cin >> a;
	fila[i] += a;
	columna[j] += a;
	if(a < 1 || a > N*N || num[a-1]) esoterico = false;
	if(a <= N*N && a > 0) num[a-1] = true;
	if(i == j) diagonal[0] += a;
	if(i == N - j - 1) diagonal[1] += a;
	if((i == 0 || i == N - 1) && ( j == 0 || j == N - 1)) esq += a;
	if((j == 0 || j == N - 1) && (i == N/2 || i == (N-1)/2)) lad += a;
	if((i == 0 || i == N - 1) && (j == N/2 || j == (N-1)/2)) lad += a;
	if((j == N/2 || j == (N-1)/2) && (i == N/2 || i == (N-1)/2)) cen+= a;

	if(i == N-1 && columna[j] != cm ) diabolico = false;
      }
      if(i == 0) { cm = fila[0]; cm2 = 4 * cm / N; }
      else if (cm != fila[i]) diabolico = false;
    }
    if(diagonal[0] != cm || diagonal[1] != cm ) diabolico = false;
    if(impar) cen *= 4;

    if(diabolico){
      if( esq != cm2 || cen != cm2 || (impar && lad != cm2) || (!impar && lad != 2* cm2) )
	esoterico = false;
    }

    //cout << "cm="<<cm<<"; cm2="<<cm2<<"; esq="<<esq<<"; cen="<<cen<<"; lad="<<lad<<endl;
    if(!diabolico)
      cout << "NO\n";
    else if (!esoterico)
      cout << "DIABOLICO\n";
    else
      cout << "ESOTERICO\n";
    
    cin >> N;
  }
  return 0;
}
