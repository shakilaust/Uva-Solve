/*
   Team    ::  AUST_toothless
   Author  ::  Shakil Ahmed
*/

#include <bits/stdc++.h>

#define pb push_back
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ( { int a ; read(a) ; a; } )

using namespace std;


#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)

template< class T > inline bool read( T &x ) {
    int c = getchar() ;
    int sgn = 1;
    while( ~c && c < '0' || c > '9' ) {
        if( c == '-' )sgn = -1 ;
        c = getchar() ;
    }
    for( x = 0 ; ~c && '0' <= c && c <= '9' ; c = getchar() ) x = x * 10 + c - '0' ;
    x *= sgn ;
    return ~c ;
}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction


#define EPS 1e-10
const int MX =  1e4 + 7 ;
const int INF = 1e8 + 7 ;

vector < int >  par[MX] ;
set < int > grp ;
int Marking[MX] , adj[MX][MX] ,  Right[MX] , Left[MX] ,  deg[MX] ,  n , L   ;
bool vis[MX];


void pre()
{
    par[1].pb(1);
    int i , j , tmp , now ;
    for ( i = 2 ; i <= 10000 ; i++ )
    {
        now = i ;
        for ( j = 13 ; j > -1 ; j-- )
        {
            int tmp = 1 << j ;
            if ( tmp <= now )
            {
                now -= tmp ;
                par[i].pb(tmp);
            }
        }
    }

}
bool bmp(int x )
{
    int sz = deg[x];
    int i , u ;
    for ( i = 0 ; i < sz ; i++ )
    {
        u = adj[x][i];
        if( vis[u] ) continue ;
        vis[u] = 1 ;
        if( Right[u] == -1 || bmp(Right[u]))
        {
            Right[u] = x ;
            Left[x] = u ;
            return true ;
        }
    }
    return false ;
}

int main() {
#ifdef LOCAL
    freopen ( "input.txt" , "r", stdin) ;
  //freopen ( "output.txt" , "w" , stdout );
#endif
   pre();
   int cs , t ;
   t = II ;
   for ( cs = 1 ; cs <= t ; cs++ )
   {
       int Id = 0 , i , j , sz , x , y;
       vector < int > cur ;
       n = II ;
       L = II ;
       grp.clear();
       rep(i,n)
       {
           j = II ;
           cur.pb(j);

          if(Marking[j]==0 ) Marking[j] = ++Id ;
       }

       for ( i = 0  ; i < Id ; i++ )
       {

           x  = cur[i];

           sz = par[x].size();
           for ( j =  sz - 1 ; j > -1 ; j-- )
           {
                 y = x + par[x][j] ;

               if ( y > L ) break ;
               if ( Marking[y] == 0 ) { Marking[y] = ++Id ; cur.pb(y) ; }
               adj[Marking[x]][deg[Marking[x]]++] = Marking[y];
           }
       }

       for ( i = 0 ; i <=  Id ; i++ )
       {
           Right[i] = -1 ;
           Left[i] = -1 ;
       }

       int Ans = 0 ;
       while( true )
       {
           ms(vis,0);
           bool matchfound = false ;
           for ( i = 1 ; i <= Id ; i++ )
           {
               if( Left[i] != -1 ) continue ;
               if( bmp(i) )
               {
                   matchfound = 1 ;
                   Ans++;
               }
           }
           if( matchfound == false ) break ;
       }


       printf("Case %d: %d\n",cs,Id - Ans);
       if( cs != t ) for ( i = 0 ; i < Id ; i++ ) { Marking[cur[i]] = 0 ; deg[i+1] = 0 ; }
   }
}
