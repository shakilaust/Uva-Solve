 //BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>
#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <sstream>
#include <utility>
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define ff first
#define LL long long
#define ss second
#define rep(i,n) for(i = 0; i < n; i++)
#define REP(i,n) for(i=n;i>=0;i--)
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define ROF(i,a,b) for(int i = a; i >= b; i--)
#define re return
#define QI queue<int>
#define SI stack<int>
#define pii pair <int,int>
#define MAX
#define MOD
#define INF 1<<30
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))
 
double const EPS=3e-8;
using namespace std;
 
 
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)((LL)bigmod(p,e-1,M)*(LL)p)%M;
}
 
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
 
/* **************************************  My code start here ****************************************** */
const int NN = 1005;
 
int Man[NN];
int Woman[NN];
int mPref[NN][NN];
int wPref[NN][NN];
int P[NN];
int N;
void Stable_Marriage()
{
    int i , j , m , w ;
    for(i=1 ; i <= N ; i++)
    {
        int woman  = i ;
        while(woman>=0)
        {
           int man = wPref[woman][P[woman]++];
            while(Man[man]==-1 || mPref[man][Man[man]] < mPref[man][woman] )
            {
                Woman[woman] = man ;
                swap(woman,Man[man]);
            }
        }
    }
 
    for(i=1 ; i <= N ; i++ ) printf("%d\n",Woman[i]);
}
int main()
{
    int cs  , t ;
    cin >> t ;
    bool space = 0 ;
    rep(cs , t )
    {    if(space) cout<<endl;
         space = 1;
        int i , j , k;
        cin >> N ;
        for(i=1 ; i <= N ; i++)
        {
            for(j=0;j<N;j++)
            {
                cin >> wPref[i][j];
            }
        }
        for(i=1 ; i<= N ; i++)
        {
            for( j = 0 ; j <N ; j++ )
            {
                cin >> k;
                mPref[i][k] = N - j ;
            }
            Man[i] = -1 ;
            Woman[i] = 0 ;
            P[i] = 0 ;
        }
        Stable_Marriage();
 
    }
   return 0;
}
