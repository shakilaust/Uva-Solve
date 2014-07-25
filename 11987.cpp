

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
#include <string>
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
//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

/* **************************************  My code start here ****************************************** */
typedef long long ll ;
const int maxn = (int) 1e5 + 10 ;
int par[maxn] , p[maxn];
ll sum[maxn] , num[maxn] ;
int find_parnt(int x)
{
    if( x == par[x] ) return x ;
    else return par[x] = find_parnt(par[x]);
}
void pre(int n)
{
    int i ;
    for ( i = 1 ; i <= n ; i++ )
    {
        par[i] = i ;
        p[i] = i ;
        sum[i] = i ;
        num[i] = 1 ;

    }
}
int main()
{
  // freopen("input.txt","r",stdin);
     //freopen("output.txt","w",stdout);
     int n , m , cmd , x , y , i , a , b;
     while(scanf("%d %d",&n,&m)==2)
     {
         pre(n);
         while(m--)
         {
             scanf("%d",&cmd);
             if(cmd==1)
             {
                 scanf("%d %d",&x,&y);
                 a = find_parnt(p[x]);
                 b = find_parnt(p[y]);
                 if(a == b ) continue;
                 par[a] = b ;
                 sum[b] += sum[a];
                 num[b] += num[a];
             }
             else if(cmd == 2)
             {
                 scanf("%d %d",&x,&y);
                 a = find_parnt(p[x]);
                 b = find_parnt(p[y]);
                 if(a == b ) continue;
                 sum[a] -= x ;
                 num[a]--;
                 sum[b] += x ;
                 num[b]++;
                 p[x] = b ;
             }
             else
             {
                 scanf("%d",&x);
                 a = find_parnt(p[x]);
                 printf("%lld %lld\n",num[a],sum[a]);
             }
         }
     }
   return 0;
}
