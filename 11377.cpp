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

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */
const int MX = 2005 ;
int adj[MX][MX] , deg[MX] , cst[MX] , n , m , k , q[MX][2] ;
bool vis[MX];
void ini()
{
    rep( i , n + 2 )
    {
        deg[i] = 0 ;
        cst[i] = 0 ;
    }
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
   int cs , t = II ;
   for ( cs = 1 ; cs <= t ; cs++ )
   {
       n = II , m = II , k = II ;
       ini();
       rep(i , k )
       {
           int x = II ;
           cst[x] = 1 ;
       }
       rep( i , m )
       {
           int x  = II , y = II ;
           adj[x][deg[x]++] = y ;
           adj[y][deg[y]++] = x ;
       }
       printf("Case %d:\n",cs);
       int Q = II ;
       while( Q-- ) {
       deque < pii > dq ;
       int x = II , y = II ;
       if( x == y  )
       {
           puts("0");
           continue ;
       }
       rep( i , n + 1 ) vis[i] = 0 ;
       int l = 0 , h = 0 ;
       vis[x] = 1 ;
       dq.push_back(mp(x,!cst[x]));
       int ans = -1 ;
       pii now ;
       while( !dq.empty())
       {
          now = dq.front();
          x = now.ff ;
          int c = now.ss ;
          dq.pop_front();

         //  printf(" l :: %d c :: %d x :: %d\n",l,c,x);
           if( x == y )
           {
               ans = c ;
               break ;
           }
           int sz = deg[x];
           rep( i , sz )
           {
               int u = adj[x][i];
               if( vis[u] ) continue ;
               //printf(" u :: %d cst :: %d\n",u,c + !cst[u]);
               vis[u] = 1 ;
               int add = !cst[u];
               if( add )
               {
                   dq.push_back(mp(u,add+c));
               }
               else dq.push_front(mp(u,c));

           }
       }

       printf("%d\n",ans);

       }
    puts("");
   }
    return 0;
}
