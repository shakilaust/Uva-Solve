
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
const int MAXN = 100 ;
Long Road[MAXN][MAXN] , Inp[MAXN] , Ans[MAXN][MAXN] , Add , dis[MAXN] ;
const Long Inf =  (1 << 29 ) ;
int N , R , Q ;
bool vis[MAXN];
void pre()
{

    int i , j ;
    for ( i = 1 ; i <= N ; i++ )
    {
        for ( j = 1 ; j <= N ; j++ )
        {
            Ans[i][j] = Road[i][j] = Inf ;


        }

        Ans[i][j] = Road[i][i] = 0 ;

    }
}
bool Input()
{
    read(N) , read(R) , read(Q);
    if( !N && !R && !Q ) return 0 ;
    pre();
    int i , x , y  ;
    Long c ;
    for ( i = 1 ; i <= N ; i++ )
    {
        read(Inp[i]);
    }
    for ( i = 0 ; i < R ; i++ )
    {
        read(x) , read(y) , read(c) ;
        Road[x][y] = min(Road[x][y] , c ) ;
        Road[y][x] = min(Road[y][x] , c ) ;
    }
    return 1 ;
}

void solve()
{
    int i , j , k , x , y;
    for ( i = 1 ; i <= N ; i++ )
    {
        for ( x  =  1 ; x <= N ; x++ )
        {
            vis[x] = 0 ;
            dis[x] = Inf ;
            if ( Inp[i] < Inp[x] ) vis[x] = 1 ;// we won't take this route

        }
        dis[i] = 0 ;
        priority_queue < pair < Long , int > >  pq ;
        pq.push( mp( 0ll , i ) ) ;
        while( !pq.empty())
        {
            Long  y = (-1) * pq.top().ff ;
            x = pq.top().ss ;
            pq.pop();
            if( vis[x] ) continue ; // already found
          //  printf("i :: %d x :: %d y :: %lld\n" ,i ,  x , y );
            dis[x] = y ;
            vis[x] = 1 ;
            for ( j = 1 ; j <= N ; j++ )
            {
                if( vis[j] ) continue ;
                Long d  = dis[x] + Road[x][j] ;
                if ( dis[j] >  d )
                {

                    pq.push(mp( -d , j ) ) ;
                }
            }
        }

        for ( x = 1 ; x <= N ; x++ )
        {
            for ( y = 1 ; y <= N ; y++ )
            {
               // printf(" x :: %d y :: %d dis [x] :: %lld dis[y] :: %lld Inp[i] :: %lld , i :: %d\n",x , y , dis[x],dis[y],Inp[i], i);
               // printf("Ans[%d][%d]:: %lld dis[%d] + dis[%d] + Inp[%d] :: %lld\n",x,y,Ans[x][y],x,y,i,dis[x]+dis[y]+Inp[i]);
                if( Ans[x][y] > (dis[x] + dis[y] + Inp[i] ))
                Ans[x][y] = ( dis[x] + dis[y] + Inp[i] ) ;
               // printf(" Ans[%d][%d] ::: %lld\n" , x, y , Ans[x][y]);
            }
        }

    }

    For(i,Q)
    {

        read(x) , read(y) ;
        Long ans = Ans[x][y];
        if ( ans == Inf ) printf("-1\n");
        else printf("%lld\n",ans);
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int cs = 0 ;
    while(Input())
    {
        if( cs ) printf("\n");
        printf("Case #%d\n",++cs);
        solve();
    }
    return 0;
}
/*
7 8 5
2 3 5 15 4 4 6
1 2 20
1 4 20
1 5 50
2 3 10
3 4 10
3 5 10
4 5 15
6 7 10
1 5
1 6
5 1
3 1
6 7
4 4 2
2 1 8 3
1 2 7
1 3 5
2 4 8
3 4 6
1 4
2 3
0 0 0
 */
