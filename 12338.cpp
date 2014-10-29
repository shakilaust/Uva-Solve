/*
   Team    ::  AUST_toothless
   Author  ::  Shakil Ahmed
*/

#include <bits/stdc++.h>

#define pb push_back
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ( { int a ; read(a) ; a; } )
#define LL ( { Long a ; read(a) ; a; } )
#define DD ({double a; scanf("%lf", &a); a;})
#define ff first
#define ss second
#define mp make_pair

#define pi 3.1415926535897932384626433832795
using namespace std;

typedef long long Long;
typedef long long int64;
typedef unsigned long long ull;

typedef pair<int,int>pii;
typedef pair<string,int>psi;
typedef pair<Long,Long>pll;
typedef pair<double,double>pdd;

typedef vector<int>    vi;
typedef vector<Long>   vl;
typedef vector<string> vs;
typedef vector<pii>  vpii;
typedef set<int> si;

#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)		forab (i, 0, (n) - 1)
#define For(i, n)		forab (i, 1, n)
#define rofba(i, a, b)	for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)		rofba (i, 0, (n) - 1)
#define rof(i, n)		rofba (i, 1, n)
#define forstl(i, s)	for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)


#define __( args... ) { dbg , args ; cerr << endl; }

struct debugger {
    template< typename T > debugger & operator , ( const T &v ) {
        cerr << v << "\t" ;
        return *this;
    }
}dbg;
// Pair Print
template< class A , class B > ostream &operator << ( ostream &o, const pair<A,B> &p ) {
    return o<<"(" << p.ff << ", " << p.ss << ")" ;
}
//Vector Print
template<class T> ostream& operator<<(ostream& o, const vector<T>& v) {
    o << "[";
    forstl(it,v) o << *it << ", " ;
    return o << "]";
}
//Set Print
template<class T> ostream& operator<<(ostream& o, const set<T>& v) {
    o << "[";
    forstl(it,v) o << *it << ", " ;
    return o << "]";
}
template<class T> inline void MAX( T &a , T b) { if (a < b ) a = b; }
template<class T> inline void MIN( T &a , T b) { if (a > b ) a = b; }

//Fast Reader
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

Long BigMod( Long  b , Long  p ,Long  m ) {
    Long r = 1 ;
    while( p ) {
        if( p & 1 ) r = ( r * b ) % m ;
        p >>= ( 1LL ) , b = ( b * b ) % m ;
    }
    return r ;
}
Long toInt(string s) {
    Long r = 0 ;
    istringstream sin(s);
    sin >> r ;
    return r ;
}
string toString(Long x) {
    stringstream s;
    s << x ;
    return s.str();
}
vs Split( string s ) {
    vs a ;
    istringstream ss(s) ;
    string b ;
    while(ss >> b ) a.pb( b ) ;
    return a;
}
string i2b( Long a ) {
    string s ;
    do { s += ( a & 1 ) + '0' ,  a >>= 1; } while( a );
    reverse(all(s));
    return s;
}

#define EPS 1e-10
const int MX = 1e5 + 7 ;
const int INF = 1e8 + 7 ;
const ull mul = 131 ; // prime number
vector < ull > Hash[MX] ;
ull cnt ;
char inp[MX];
int len[MX];
int main() {
#ifdef LOCAL
    freopen ( "input.txt" , "r", stdin) ;
  //freopen ( "output.txt" , "w" , stdout );
#endif
    int cs , t ;
    t = II ;
    For ( cs , t)
    {
        int n = II ;
        rep(i,n)
        {
            scanf("%s",&inp);
            cnt = 0 ;
            len[i+1] = strlen(inp);
            Hash[i+1].clear();
            for ( int j = 0 ; inp[j] ; j++ )
            {
                cnt = cnt*mul + inp[j] - 'a';

                Hash[i+1].pb(cnt);
            }
        }
        n = II ;
        printf("Case %d:\n",cs);
        rep(i,n)
        {
            int x = II ;
            int y = II ;
            int left = 0 , right = min(len[x],len[y])-1 , mid , ans = 0 ;
            while( left <= right )
            {
                mid = ( right + left ) / 2 ;
                if ( Hash[x][mid] == Hash[y][mid] )
                {
                    ans = mid ;
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1 ;
                }
            }
            if( Hash[x][ans] != Hash[y][ans] ) printf("%d\n",ans);
            else
            printf("%d\n",ans+1);
        }
    }

}
