
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
int N , M , x , y ;
char grid[105][105];
bool visit[105][105];
int dx[] = {1,1,1,0,0,-1,-1,-1};
int dy[]={1,-1,0,1,-1,1,-1,0};
bool Valid(int x , int y)
{

    if( x >=N || x <0 || y >= M || y < 0 || visit[x][y] || grid[x][y]=='Z') return 0;
    return 1 ;
}
struct Graph
{
    int x , y , cost ;
    Graph() {}
    Graph(int _x,int _y , int _c)
    {
        x = _x ;
        y = _y;
        cost = _c;
    }
};
void input()
{
    int i , j , k ;
    memo(visit,0);
    read(N) , read(M);
    int DX[] = {1,1,-1,-1,2,2,-2,-2};
    int DY[]={2,-2,2,-2,1,-1,1,-1};
    rep(i,N)  scanf("%s",grid[i]) ;
    rep(i,N)
    {

        rep(j,M)
        {
            if(grid[i][j]=='A') x = i , y = j ;
            if(grid[i][j]=='Z')
            {
                rep(k,8)
                {
                    int nx = DX[k] + i ;
                    int ny = DY[k] + j ;
                    if(Valid(nx,ny))
                    { if(grid[nx][ny]=='A' || grid[nx][ny]=='B') continue;
                      visit[nx][ny] = 1;
                      //printf("grid[nx][ny]::%c\n",grid[nx][ny]);
                    }
                }
            }
        }
    }
  /*  rep(i,N)
    {   rep(j,M) printf("%d",visit[i][j]);
        printf("\n");
    } */

}
int bfs(int x , int y)
{
    queue <Graph> q;
    q.push(Graph(x,y,0));
    visit[x][y] = 1;
    while(!q.empty())
    {
        Graph prev = q.front();
        q.pop();
        if(grid[prev.x][prev.y]=='B') return prev.cost;
        int i ;
        rep(i,8)
        {
            int nx = dx[i] + prev.x;
            int ny = dy[i] + prev.y ;

            if(Valid(nx,ny))
            {
                visit[nx][ny] = 1;
                q.push(Graph(nx,ny,prev.cost+1));
            }
        }
    }
    return -1;
}
int main()
{ int cs , t ;
   read(t);
   rep(cs , t )
   {   input();
       int ans = bfs(x,y);
       if(ans==-1) puts("King Peter, you can't go now!");
       else printf("Minimal possible length of a trip is %d\n",ans);
   }
   return 0;
}
/*
1
3 3
ZZ.
...
AB.
*/
