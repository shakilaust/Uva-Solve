
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
//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

/* **************************************  My code start here ****************************************** */
const int MAXN = 50005;
int n , m ;
struct abc
{
    int x , y , cost ;
}inp[MAXN];
int par[MAXN];
int find_parent(int x)
{
    if(par[x]==x) return x;
    return par[x] = find_parent(par[x]);
}
void Make_Union(int x , int y)
{
    par[find_parent(x)] = find_parent(y);
}
bool isUnion(int x , int y)
{
    return find_parent(x)==find_parent(y);
}
bool cmp(abc A , abc B)
{
    return A.cost < B.cost ;
}
void MST()
{
    int i , mst = 0 ;
    sort(inp,inp+m,cmp);
    rep(i,m)
    {
        if(!isUnion(inp[i].x,inp[i].y))
        {
            Make_Union(inp[i].x,inp[i].y);
            mst += inp[i].cost;
        }
    }
    printf("%d\n",mst);
}
 main()
{
    int cs , t ;
    read(t);
    for ( cs =  1 ; cs <= t ; cs++ )
    {
        if( cs > 1 ) puts("");
        read(n);
        read(m);
        int i ,c , idx = 0;
        for ( i = 1 ; i <= n ; i++ ) par[i] = i ;
        map < string , int > M ;
        rep(i,m)
        {
            string a , b ;
            cin >> a >> b ;
            read(c);
            if(M[a]==0) M[a] = ++idx ;
            if(M[b]==0) M[b] = ++idx ;
            inp[i].x = M[a];
            inp[i].y = M[b];
            inp[i].cost = c ;
        }
        MST();
    }

   return 0;
}
