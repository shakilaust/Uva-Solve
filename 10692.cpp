
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
template <class T> inline T bigmod(T p,T e,T M) // Calculate p ^ e % M
{
    if(e==0)return 1;
    if(e%2==0){LL t=bigmod(p,e/2,M);return (T)((t*t)%M);}
    return (T)((LL)bigmod(p,e-1,M)*(LL)p)%M;
}

template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

/* **************************************  My code start here ****************************************** */
const int maxn = 10005 ;

int mod , n , val[maxn];
int Euler_phi(int num)
{

    int i ;
    int phi = num ;
    for ( i = 2 ; i*i<= num ; i++)
    {
        if( num % i == 0 )
        {
            while( num % i == 0 ) num/=i ;
            phi -= phi/i ;
        }
    }
    if( num > 1 ) phi -= phi/num ;
    return phi;
}
// a ^ x % Mod  = a ^ ( x % phi(Mod) + Phi(Mod ) ) % Mod
int Dfs(int pos , int Mod)
{

    if ( pos == n-1 ) return val[n-1]%Mod ;
    int PhiMod = Euler_phi(Mod);

    int Add = Dfs(pos+1,PhiMod); // calculate x % phi(Mod)
    int ans = bigmod(val[pos] , PhiMod + Add , Mod );

    return ans ;

}
int main()
{
  // freopen("input.txt","r",stdin);
     //freopen("output.txt","w",stdout);
     string inp ;

     int cs = 1 ;
     while( cin >> inp )
     {
         if ( inp == "#" ) break;
         mod = 0 ;
         int i , sz = inp.size();
         for ( i = 0 ; i < sz ; i++ )
         {
             mod = ( mod * 10 ) + ( inp[i] - '0' );
         }
         cin >> n ;
         for ( i = 0 ; i < n ; i++ )
         {
             cin >> val[i];
         }
         printf("Case #%d: %d\n",cs++,Dfs(0,mod));
     }

   return 0;
}
