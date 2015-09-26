
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

#define FI freopen ("3.txt", "r", stdin)
#define FO freopen ("1.txt", "w", stdout)

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

#define forab(i, a, b)  for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)       forab (i, 0, (n) - 1)
#define For(i, n)       forab (i, 1, n)
#define rofba(i, a, b)  for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)       rofba (i, 0, (n) - 1)
#define rof(i, n)       rofba (i, 1, n)
#define forstl(i, s)    for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }

//Fast Reader
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */
const int NX = 105 ;
int dp[ NX ][ NX ] , cs , vis[ NX ][ NX ] , path[ NX ][ NX ];
const int INF = 1 << 29 ;
char inp[ NX ];
bool match( char x , char y )
{
    if( x == '(' && y == ')' ) return true ;
    else if( x == '[' && y == ']' ) return true ;
    else return false ;
}

void Print( int x , int y )
{
    if( x > y ) return ;
    if( x == y )
    {
        if( inp[x ] == '(' || inp[x] == ')' ) printf("()");
        else printf("[]");
        return ;
    }
    int val = path[x][y];
    if( val == -1 )
    {
        printf("%c",inp[x]);
        Print( x + 1 , y - 1 );
        printf("%c",inp[y]);
    }
    else
    {
        Print( x , val );
        Print( val + 1 , y );
    }
}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
  // FI;
  // FO;
  int testcase ;
    char foo[128];
    scanf("%d", &testcase);
    while (getchar() != '\n');
    while (getchar() != '\n');
    while (testcase--)
    {

               gets(inp);
        gets(foo);
            ms( dp , 0 );
            ms( path , -1 );
            int sz = strlen( inp );
            int i , j ;
            for ( i = 0 ; i < sz ; i++ )
            {
                for ( j = 0 ; j + i < sz ; j++ )
                {
                    if( i == 0 )
                    {
                        dp[j][j] = 1 ;
                        continue ;
                    }
                  //  dp[i][j] = INF ;
                    int l = j , r = i + j ;
                    dp[l][r] = INF ;
                    if( match( inp[l] , inp[r] ) )
                    {
                        dp[l][r] = dp[l+1][r-1];
                        path[l][r] = -1 ;
                    }
                    int k ;
                    for ( k = l ; k < r ; k++ )
                    {
                        if( dp[l][k] + dp[k+1][r] < dp[l][r] )
                        {
                            path[l][r] = k ;
                            dp[l][r] = dp[l][k] + dp[k+1][r];
                        }
                    }
                }
            }
            Print( 0 , sz - 1 );
            printf("\n");
            if( testcase ) puts("");
    }
    return 0;
}
