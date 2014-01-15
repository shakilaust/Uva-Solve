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

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n  , m ;
char grid[25][25];
bool visit[25][25];
char ch ;
bool check(int x , int y)
{
    if( x<0 || x>=n || y<0 || y >= m || grid[x][y]!=ch ) return 0 ;
    return 1;
}
int dfs(int x , int y)
{   if(visit[x][y]) return 0 ;
    visit[x][y] = 1;

    int i , nx , ny ;
    int ret = 1;
    rep(i,4)
    {
        int nx = (dx[i] + x) ;
        int ny = ((dy[i] + y)+m)%m;
        if(check(nx,ny)) ret += dfs(nx,ny);
    }
    return ret;
}
int main()
{
    while(scanf("%d %d",&n,&m)==2)
    {
        int x , y , i , mx = 0 , j ;
        rep(i,n) scanf("%s",grid[i]);
        read(x),read(y);
        ch = grid[x][y];
        memo(visit,0);
        int ret = dfs(x,y);
        rep(i,n) rep(j,m) if(grid[i][j]==ch) mx = max(mx , dfs(i,j));
        printf("%d\n",mx);


    }

   return 0 ;

}
