
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
#define memo(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))

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
const int MX = 50 ;
const int Inf = ( 1 << 29 );
int deg[MX] , adj[MX][MX] , prev[MX] , cap[MX][MX] , q[MX*MX*MX] , inp[MX][MX] , n , m;
void CLR()
{
    memo(inp,0);
    memo(cap, 0);
}
void addEdge(int x , int y , int c )
{
    cap[x][y] = c;
    //adj[x][deg[x]++] = y ;
}
int dinic(int scr , int sink )
{
    int flow = 0 ;
    while(1)
    {
        int i , qpush = 0 , qpop = 0 , x;
        for ( i = 0 ; i <= sink ; i++ ) prev[i] = -1 ;
        prev[ q[qpush++] = scr ] = -2 ; // special park ;
        while( qpush > qpop && prev[sink] == -1 )
        {
            x = q[qpop++];
            for ( i = 0 ; i <= sink ; i++ )
            {
                int y = i ;
              //  printf(" prev[y]::%d x :: %d cap[%d][%d] :: %d\n",prev[y] , x , x, y , cap[x][y] );
                if ( prev[y] == -1 && cap[x][y] > 0 )
                {
                    prev[y] = x ;
                    q[qpush++] = y;
                }
            }
        }
     //   printf(" prev :: %d \n" , prev[sink]);
        if( prev[sink] == -1 ) break;
        for ( x = 0 ; x <= sink ; x++ )
        {
            if( prev[ x ] != -1 && cap[x][sink ] > 0 )
            {
                int add = cap[x][sink];

                for ( int z = x , v = prev[x ] ; v >= 0 ; v = prev[v])
                {
                    add = min( add , cap[v][z]);
                    z = v ;
                }
                if(!add ) continue;
                cap[x][sink] -= add ;
                cap[sink][x] += add ;
                for ( int z = x , v = prev[x] ; v >= 0 ; v = prev[v]  )
                {
                    cap[v][z] -= add;
                    cap[z][v] += add;
                    z = v ;
                }
                flow += add ;
            }
        }

    }
    return flow;
}
void input()
{
    CLR();
    cin >> n >> m ;
    int i , sz , j  , x ;
    for ( i = 1 ; i <= n ; i++ )
    {
        cin >> sz ;
        for ( j = 0 ; j < sz ; j++ )
        {
            cin >> x ;
            inp[i][x]++;
        }
    }
}
int main()
{
   // ios_base::sync_with_stdio(0); cin.tie(0);
    int cs , t , i , j ;
    cin  >> t ;
    for ( cs = 1 ; cs <= t ; cs++ )
    {
        input();
        int sink = n + m + 1 ;
        int scr = 0 ;
        addEdge(scr,1,Inf);
        for ( i = 1 ; i <= m ; i++ )
        {
            addEdge(1 , i+n , inp[1][i]); // or za ase sob use hobe
            addEdge(i+n , sink , 1 );
        }
        for ( i = 2 ; i <= n ; i++ )
        {
            for ( j = 1 ;j <= m ; j++ )
            {
                if(inp[i][j] > 1 ) addEdge(i, j+n , inp[i][j]-1) ; // nije ekta rekhe dibe
                if(inp[i][j] == 0 ) // chocolate possible hole nibe
                 addEdge(j+n , i ,1);
            }
        }
        printf("Case #%d: %d\n",cs,dinic(scr, sink));

    }

    return 0;
}
/*

*/
