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

const int NX = 4 ;

struct Matrix
{
    Long mat[ NX ][ NX ] ;
};
Long n , M ;

Matrix Multiplication( Matrix A , Matrix B)
{
    Matrix ans ;
    int i , j , k ;
    for ( i = 0 ; i < 3 ; i++ )
    {
        for ( j = 0 ; j < 3 ; j++ )
        {
            ans.mat[i][j] = 0 ;
            for ( k = 0 ; k < 3 ; k++ )
            {
               // ans.mat[i][j] = ( ans.mat[i][j] + (( A.mat[i][k])%M * (B.mat[k][j])%M)%M)%M ;
                ans.mat[i][j] = ((ans.mat[i][j]%M)+(((A.mat[i][k]%M)*(B.mat[k][j]%M))%M))%M;;
            }
        }

    }
     return ans ;
}

    Matrix MatExpo( Matrix base , Long power)
    {
        if( power == 1 ) return base ;
        Matrix ans = MatExpo( base , power/2 );
        ans = Multiplication( ans , ans );
        if( power & 1 ) ans = Multiplication( ans , base );
        return ans ;
    }

Matrix Base ;
void SetBase()
{
    rep( i , 3 ) Base.mat[0][i] = 1 ;
    rep( i , 2 ) rep ( j , 3 ) Base.mat[i+1][j] = 0 ;
    Base.mat[1][0] = Base.mat[2][2] = 1 ;

}
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
    SetBase() ;
    Long n ;
    int cs = 1 ;
    while( scanf("%lld %lld" , &n , &M) && ( n + M ) )
    {
        Long ans = 0 ;
        if( n == 0 ) ans = 1 ;
        else if( n == 1 ) ans = 1 ;
        else
        {
            Matrix res= MatExpo( Base , n - 1 );
            rep( i , 3 )
            {
                ans = ( ans + res.mat[0][i])%M;
            }
        }
        printf("Case %d: %lld %lld %lld\n",cs++,n,M,ans);
    }
    return 0;
}

/*
2
3 2
1 2 2 5
2 3 3 6
2
1 3
1 3
4 2
1 2 5 2
2 3 6 3
1
1 4

*/
