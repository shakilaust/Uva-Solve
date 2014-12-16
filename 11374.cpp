//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define ff first
#define ss second
#define re return
#define QI queue<int>
#define SI stack<int>
#define SZ(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define ms(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))
#define II ( { int a ; read(a) ; a; } )
#define LL ( { Long a ; read(a) ; a; } )
#define DD ({double a; scanf("%lf", &a); a;})

double const EPS=3e-8;
using namespace std;

#define FI freopen ("input.txt", "r", stdin)
#define FO freopen ("output.txt", "w", stdout)

typedef long long Long;
typedef long long int64;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef set<int> si;
typedef vector<Long>vl;
typedef pair<int,int>pii;
typedef pair<string,int>psi;
typedef pair<Long,Long>pll;
typedef pair<double,double>pdd;
typedef vector<pii> vpii;

// For loop

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }

//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */
const int MX = 505 ;
const int INF = 1<<29 ;
int dis[2][MX] , par[2][MX] , deg[MX] , adj[MX][MX*MX+10] , cost[MX][MX] , vis[MX];
int n ,s , t , m , k ;
void ini()
{
    rep(i,n+2)
    {
        deg[i] = 0 ;
        par[0][i] = par[1][i] = -1 ;
        dis[0][i] = dis[1][i] = INF ;
        rep(j,n+2) cost[i][j] = INF ;
        cost[i][i] = 0 ;
    }
}
void input()
{
    m = II;
    rep(i,m)
    {
        int x = II ;
        int y = II ;
        int c = II ;
        cost[x][y] = cost[y][x] = min(cost[x][y],c);
        adj[x][deg[x]++] = y ;
        adj[y][deg[y]++] = x ;

    }

}
void dijkstra( int s , int idx , int e)
{
   // printf("start\n");
    priority_queue < pii > pq ;
    pq.push(mp(0,s));
    ms(vis,0);
    dis[idx][s] = 0 ;
    while(!pq.empty())
    {
        pii pr = pq.top();
        pq.pop();
        int c = -1 * pr.ff ;
        int u = pr.ss ;
      //  printf("u :: %d  c:: %d\n",u,c);
        if( u == e ) break ;

        //vis[u] = 1 ;
        rep(i,deg[u])
        {
            int nx = adj[u][i];
           // if( vis[nx] ) continue ;
            int nc = cost[u][nx];
            if( dis[idx][nx] > nc + c )
            {
                dis[idx][nx] = nc + c ;
                par[idx][nx] = u ;
                pq.push(mp(-(nc+c),nx));
            }
        }
    }
   // printf("end\n");
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
   bool sp = 0 ;
   while( scanf("%d %d %d",&n,&s,&t)==3)
   {
       if(sp) puts("");
       sp = 1 ;
       ini();
       input();
       dijkstra(s,0,t);
       dijkstra(t,1,s);
       k = II ;
       int ans = dis[0][t];
       int x , y , z  , tag1 = -1 , tag2 = -1 ;
       rep(i,k)
       {
           x = II , y = II , z = II ;
          // printf("x::%d y :: %d dis[0][x]:: %d dis[1][y]::%d z :: %d\n",x , y , dis[0][x],dis[1][y],z);
           if( dis[0][x] < INF && dis[1][y] < INF && dis[0][x] + dis[1][y] + z < ans )
           {
               tag1 = x ;
               tag2 = y ;
               ans = dis[0][x] + dis[1][y] + z ;
           }
           if( dis[0][y] < INF && dis[1][x] < INF && dis[0][y] + dis[1][x] + z < ans )
           {
               tag1 = y ;
               tag2 = x ;
               ans = dis[0][y] + dis[1][x] + z ;
           }

       }
       vector < int > pres ;
       if( tag1 == -1 ) // first one is good
       {
          // stack < int > st ;
           //printf("here tag1 \n");
           int cur = t ;
           while( par[0][cur] != -1 )
           {
               pres.pb(cur);
               cur = par[0][cur];
               //if( par[0][cur] == -1 ) break ;
           }
           pres.pb(cur);
       }
       else
       {
           int cur = tag2 ;
         //  printf(" tag2 :: %d par[1][tag2]::%d\n",tag2,par[1][tag2]);
           while( par[1][cur] != -1 )
           {
               pres.pb(cur);
               cur = par[1][cur];
              // printf("cur :: %d\n",cur);
               // break ;

           }
           pres.pb(cur);
           reverse(pres.begin(),pres.end());
           cur = tag1 ;
           while(par[0][cur] != -1 )
           {
               pres.pb(cur);
               cur = par[0][cur];
             //  printf("cur :: %d\n",cur);
              // if( par[0][cur] == -1 ) break ;

           }

           pres.pb(cur);
       }
       reverse(pres.begin(),pres.end());
       int sz = pres.size();
       for ( int i = 0 ; i < sz ; i++ )
       {
           if(i) printf(" ");
           printf("%d",pres[i]);
       }
       puts("");
       if( tag1 == -1 )
       {
           printf("Ticket Not Used\n");
       }
       else printf("%d\n",tag1);
       printf("%d\n",ans);
   }

    return 0;
}
/*
2
17
9 3 5 2 6 6 3 0 8 6 0 4 4 8 7 2 1
1 2 3 3 3 1 2 1 1 3 1 3 3 2 1 3 1
12
4 6 9 0 2 7 3 0 9 6 8 1
2 3 1 1 1 3 2 1 3 3 2 3
*/
