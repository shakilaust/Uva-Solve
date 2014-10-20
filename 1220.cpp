
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
const int MX = 205  ;
vector < int > adj[MX] ;
int n , dp[MX][2] , notUniq[MX][2] , vis[MX][2] ;
void  Pre()
{
    rep(i,n+3)
    {
        adj[i].clear();
        vis[i][0] = vis[i][1] = notUniq[i][0] = notUniq[i][1] = 0 ;

    }
}
int DP(int pos , int bosacchi )
{

    int &ret = dp[pos][bosacchi];
    if ( vis[pos][bosacchi] ) return ret ;
    vis[pos][bosacchi] = 1 ;
    int sz = adj[pos].size();
    if(!sz)
    {
        notUniq[pos][bosacchi] = 0 ;
        return ret = dp[pos][bosacchi] = bosacchi;

    }
    ret = bosacchi ;
   // notUniq[pos][bosacchi] = 0 ;
    if( bosacchi )
    {
        rep(i,sz)
        {
            int v = adj[pos][i];
            ret += DP(v,0);
            if(!notUniq[pos][bosacchi] ) notUniq[pos][bosacchi] = notUniq[v][0];
        }
    }
    else
    {
        rep(i,sz)
        {
            int v = adj[pos][i];
            int t1 = DP(v,0);
            int t2 = DP(v,1);
            if( t1 == t2 )
            {
                ret += t1 ;
                notUniq[pos][bosacchi] = 1 ;
            }
            else if(t1 > t2 )
            {
                ret += t1 ;
            if(!notUniq[pos][bosacchi] ) notUniq[pos][bosacchi] = notUniq[v][0];
            }
            else
            {
                ret += t2 ;
                if(!notUniq[pos][bosacchi] ) notUniq[pos][bosacchi] = notUniq[v][1];
            }
        }
    }
    return ret ;
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    while(scanf("%d",&n) && n )
    {
        Pre();
        map < string , int > Idx ;
        string a , b ;
        int id = 1 ;
        cin >> a ;
        Idx[a] = id++;
        rep(i,n-1)
        {
            cin >> a >> b ;
            if( Idx.find(a) == Idx.end() ) Idx[a] = id++;
            if(Idx.find(b) == Idx.end() ) Idx[b] = id++;
            adj[Idx[b]].pb(Idx[a]);
        }
        bool nuq = 0 ;
        int t1 = DP(1,0);
        int t2 = DP(1,1);
        if( t1 == t2 )
        {
            nuq =  1 ;

        }
        else if ( t1 > t2 )
        {
            nuq = notUniq[1][0];
        }
        else
        {
            swap(t1,t2);
            nuq = notUniq[1][1];
        }
        printf("%d %s\n",t1,nuq?"No":"Yes");
    }
    return 0;
}
