//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 all my suceesses are dedicated to my parents
 The true test of a man's character is what he does when no one is watching.
 Don't let your dreams be dreams.


 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::

*/

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair

// Macro
#define eps 1e-9
#define pi acos(-1.0)
#define ff first
#define ss second
#define re return
#define QI queue<int>
#define SI stack<int>
#define SZ(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sq(a) ((a)*(a))
#define distance(a,b) (sq(a.x-b.x) + sq(a.y-b.y))
#define iseq(a,b) (fabs(a-b)<eps)
#define eq(a,b) iseq(a,b)
#define ms(a,b) memset((a),(b),sizeof(a))
#define G() getchar()
#define MAX3(a,b,c) max(a,max(b,c))
#define II ( { int a ; read(a) ; a; } )
#define LL ( { Long a ; read(a) ; a; } )
#define DD ({double a; scanf("%lf", &a); a;})

double const EPS=3e-8;
using namespace std;

#define FI freopen ("1.txt", "r", stdin)
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
#define __(args...) {dbg,args; cerr<<endl;}
struct debugger{template<typename T> debugger& operator , (const T& v){cerr<<v<<"\t"; return *this; }}dbg;
#define __1D(a,n) rep(i,n) { if(i) printf(" ") ; cout << a[i] ; }
#define __2D(a,r,c,f) forab(i,f,r-!f){forab(j,f,c-!f){if(j!=f)printf(" ");cout<<a[i][j];}cout<<endl;}

template<class A, class B> ostream &operator<<(ostream& o, const pair<A,B>& p){ return o<<"("<<p.ff<<", "<<p.ss<<")";} //Pair print
template<class T> ostream& operator<<(ostream& o, const vector<T>& v){ o<<"[";forstl(it,v)o<<*it<<", ";return o<<"]";} //Vector print
template<class T> ostream& operator<<(ostream& o, const set<T>& v){ o<<"[";forstl(it,v)o<<*it<<", ";return o<<"]";} //Set print

//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */


vector < int > adj[ 105] ;

int n , cnt , vis[ 105 ] , cs , RR[ 105 ] , rr , m  ;


void dfs( int x  )
{
    int sz = adj[x].size();
    vis[x] = cs ;
    cnt++;
    for( int i = 0 ; i < sz ; i++ )
    {
        int u = adj[x][i];
        if( vis[u] == cs ) continue ;
        dfs( u );
    }
}


void Find_RR( int x , int lv)
{

   queue < int > q , c ;
   q.push( x );
   c.push( 0 );
   RR[x] = rr ;
   while( !q.empty() )
   {
       int x = q.front();
       int p = c.front();
       q.pop();
       c.pop();
       int sz = adj[x].size();
       rep( i , sz )
       {
           int u = adj[x][i];
           if( RR[u] == rr ) continue ;
           RR[u] = rr ;
           cnt = max( cnt , p + 1 );
           q.push( u );
           c.push( p + 1 );
       }
   }
}


int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
   // FI ;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cs = 1 ;
    while( scanf("%d %d",&n,&m) == 2 )
    {
        if( n == 0 && m == 0 ) break ;
        map < string , int > Name ;
        cnt = 0 ;
        for( int i = 1 ; i <= n ; i++ ) adj[i].clear();
        for( int i = 1 ; i <= m ; i++ )
        {
            string a , b ;
            int x , y ;
            cin >> a >> b ;
            if( Name[a] == 0 ) Name[a] = ++cnt ;
            if( Name[b] == 0 ) Name[b] = ++cnt ;
            x = Name[a];
            y = Name[b];
            //printf(" x :: %d y :: %d\n" , x , y );
            adj[x].pb(y);
            adj[y].pb(x);
        }
        cnt = 0 ;
        dfs( 1 );
        if( cnt != n ) printf("Network %d: DISCONNECTED\n",cs++);
        else
        {
            cnt = 0 ;
            int ans = 0 ;
            for( int i = 1 ; i <= n ; i++ )
            {
                ++rr ;
                cnt = 0 ;
                Find_RR( i , 0 );

                ans = max( ans , cnt );
                //printf("i :: %d cnt :: %d ans :: %d rr :: %d\n" , i , cnt , ans , rr );
            }
            printf("Network %d: %d\n",cs++ , ans);
        }
        puts("");

    }
    return 0;
}
/*
4 4
Ashok Kiyoshi Ursala Chun Ursala Kiyoshi
Kiyoshi Chun
4 2
Ashok Chun Ursala Kiyoshi
6 5
Bubba Cooter Ashok Kiyoshi Ursala Chun
Ursala Kiyoshi Kiyoshi Chun
0 0
*/
