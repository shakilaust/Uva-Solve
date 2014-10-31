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
const int MX = 200007;
const int INF = 1e8 + 7 ;
vector <int> adj[MX],rev[MX],order,res;
int comp[MX],n,m;
bool vis[MX];
vector < pii > Inp ;
int value(int x)
{
         if ( x < 0 ){
        x=-x;
        x--;
        return ((x)<<1)+1;
    }
    x--;
    return ((x)<<1);

}
void topo(int u)
{      vis[u]=1;
       int i;
       for(i=0;i<adj[u].size();i++)
       {
              int v=adj[u][i];
              if(!vis[v]) topo(v);
       }
       order.pb(u);
}
void scc(int u,int col)
{
       comp[u]=col;
       int i;
       for(i=0;i<rev[u].size();i++)
       {
              int v=rev[u][i];
              if(comp[v]==-1)
              {
                     scc(v,col);
              }
       }
}

      bool twosat()
{
    int i;
       /*printf("n:: %d\n",n);
       for(i=0;i<2*n;i++)
       printf("comp[%d]:: %d\n",i,comp[i]); */
       for(i=0;i<2*n;i+=2)
         if(comp[i]==comp[i+1]) return false;
       return true;
      /*int x , y , i , nx , ny ;
      for ( i = 0 ; i < m ; i++ )
      {
          x = value(Inp[i].ff);
          nx = value(-x);
          y = value((Inp[i].ss));
          ny = value(-ny);
         // if( comp[x] == comp[nx] ) continue;
         // if(comp[y] == comp[ny] ) continu;
          if( comp[x] > comp[nx] && comp[y] > comp[ny] ) return false;

      }
      return true; */
}

void ini()
{
    int i ;
    for ( i = 0 ; i <= 2*n  ; i++ )
    {
        adj[i].clear();
        rev[i].clear();
        vis[i] = 0 ;
        comp[i] = -1 ;
    }
}
void input()
{
    scanf("%d %d",&n,&m);
    ini();
    Inp.clear();
    rep(i,m)
    {
        int  x = II ;
        int  y = II ;
        x = value(x);
        y = value(y);
        adj[x^1].pb(y);
        adj[y^1].pb(x);
        rev[x].pb(y^1);
        rev[y].pb(x^1);
    }
}
int main() {
#ifdef LOCAL
    freopen ( "input.txt" , "r", stdin) ;
  //freopen ( "output.txt" , "w" , stdout );
#endif
   int cs , t , i;
   t = II ;
   for ( cs = 1 ; cs <= t ; cs++ )
   {
           input();
           order.clear();
          // ms(vis,0);
           for(i=0;i<2*n;i++) if(!vis[i]) topo(i);
           int cnt=0;
           reverse(order.begin(),order.end());
           for(i=0;i<order.size();i++)
           if(comp[order[i]]==-1)  scc(order[i],cnt++);
           if( twosat()) printf("Case %d: Yes\n",cs);
           else printf("Case %d: No\n",cs);

   }
}
