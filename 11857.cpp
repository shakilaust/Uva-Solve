//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 all my suceesses are dedicated to my parents
 The true test of a man's character is what he does when no one is watching.


 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */

#include <bits/stdc++.h>

#define II ( { int a ; read(a) ; a; } )
#define LL ( { Long a ; read(a) ; a; } )

using namespace std;



typedef long long Long;



//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */

const int NX = 1e6 + 10 ;

struct abc
{
    int x , y , c ;
};

abc edge[ NX ] ;

bool cmp ( abc A , abc B )
{
    return A.c < B.c ;
}
int parnt[ NX ] , n , m ;

int find_parnt( int x )
{
    if( x ==  parnt[ x] ) return x ;
    else parnt[ x ] = find_parnt( parnt[ x ] );
}


int solve()
{
    int cnt = 0 , mx = -1 ;
    for ( int i = 0 ; i < n ; i++ ) parnt[i] = i ;
    sort( edge , edge + m , cmp );
    for ( int i = 0 ; i < m && cnt < n -1 ; i++ )
    {
        int x = edge[i].x ;
        int y = edge[i].y ;
        x = find_parnt( x );
        y = find_parnt( y );

        if( x != y )
        {
            cnt++;
            parnt[ x ] = y ;
            if( cnt == n - 1 ) mx = edge[i].c ;
        }

    }


    return mx ;
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being

    while( 1 )
    {
        n = II , m = II ;
        if( n == 0 && m == 0 ) break ;
        for ( int i = 0 ; i < m ; i++ )
        {
            edge[i].x = II , edge[i].y = II , edge[i].c = II ;
        }
        int ans = solve();
        if( ans == -1 ) puts("IMPOSSIBLE");
        else printf("%d\n",ans);
    }

    return 0;
}
