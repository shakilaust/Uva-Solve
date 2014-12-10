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
const int MX = 1005 ;
const int INF = 1<<29 ;
int par[MX] , n , m  , cs = 1;
int adj[30][30] , deg[30] , d[30][30] ,tot[30];
struct abc
{
    int x , y , dis ;
}inp[MX];
char Name[30][MX];
bool cmp( abc A , abc B)
{
    return A.dis < B.dis ;
}
int findpar(int x)
{
    if( par[x] == x ) return x ;
    else return par[x] = findpar(par[x]);
}
void kruskal()
{


    For( k , n )
    {
        For( i , n )
        {
            For ( j , n ) d[i][j] = min(d[i][j] , d[i][k] + d[k][j] );
        }
    }
    For( i , n )
    {
        For ( j , n ) tot[i] += d[i][j];
    }
    int Ans = -1 , id ;
    for ( int i = 1 ; i <= n ; i++ )
    {
        if( Ans == -1 || Ans  >  tot[i] )
        {
            Ans = tot[i] ;
            id =  i ;
        }
    }
    printf("Case #%d : %s\n",cs++,Name[id]);
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
   while(scanf("%d %d",&n,&m)==2)
   {
       if( n == 0 && m == 0 ) break ;
       For(i,n) scanf("%s",Name[i]);
        For( i , n )
    {
        tot[i] = 0 ;
        par[i] = i ;
        For( j , n ) d[i][j] = INF ;
        d[i][i] = 0 ;
    }
       rep(i,m)
       {
           int x = II ;
           int y = II ;
           int dis = II ;
           d[y][x] = d[x][y] = min( d[x][y] , dis);

       }
       kruskal();
   }

}
