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
 //Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

/* **************************************  My code start here ****************************************** */
const int N = 800 ;
LL n , m ,x[N] , y[N] ,par[N];

LL Dis(int i , int j)
{
    return (x[i]-x[j])*(x[i]-x[j]) + ( y[i]-y[j])*(y[i]-y[j]);
}
int find_parent(int x)
{
    if(par[x]==x) return x ;
    return find_parent(par[x]);
}
int main()
{
  while(read(n)==1)
  {
      int i , a , b , j ;
      vector < pair < LL , pii > > inp;
      //memo(par,0);
      rep(i,n)
      {
          a ;
          read(a);
          x[i] = a;

          read(a);
          y[i] = a ;

          par[i+1] = i+1;
      }
      read(m);
      rep(i,m)
      {
          read(a);
          read(b);

          int u = find_parent(a);
          int v = find_parent(b);
          if(u!=v) par[u] = v ;

      }
      for(i=0;i<n;i++) for(j=i+1;j<n;j++)
      {
          inp.pb(mp(Dis(i,j),mp(i+1,j+1)));
      }
      sort(inp.begin(),inp.end());

      double ans = 0 ;
      int sz = inp.size() ;
      rep(i,sz)
      {
          int X = inp[i].second.first;
          int Y = inp[i].second.second;
        //  printf("X ::%d Y:%d\n",X,Y);
          int u = find_parent(X);
          int v = find_parent(Y);
          if( u != v )
          {
              ans += sqrt(inp[i].first);
              par[u] = v ;
          }
      }
      printf("%.2lf\n",ans+1e-10);
  }
   return 0;
}
