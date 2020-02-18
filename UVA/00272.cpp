/*@info_general
author: Jesus Domenech
date: 2020
id: 272 - Tex Quotes
url: https://onlinejudge.org/external/2/272.pdf
categories: adhoc, text
*******************************************/

/*@info_submission
time: 0.000
best: 0.000
rank: 
tries: 1 
*/

/*@info_solution
 Read char by char and replace " by `` and by ''
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
typedef pair <int,int> ii;
typedef pair <ll, ll> ll_ll;
typedef vector <int> vi;
typedef map <int, int> mii;
typedef vector <ii> vii;
typedef vector <ll> vll;
typedef vector <vi> vvi;

#define REP(i, a, b) for(int i = int(a); i < int(b); i++)


int main(){
    bool open = true;
    char c;
    while(scanf("%c", &c) != EOF) {
        if (c == '"') {
            cout << (open ? "``" : "\'\'");
            open = !open;
        }
        else
            cout << c;
    }
  return 0;
}