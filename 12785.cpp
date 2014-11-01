
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
const int MX = 1e5 + 7 ;
char txt[MX] , pat[MX] , inp[MX];
int T[MX] , s , e , txtlen ;
void pre()
{
   int k=0 , q;
   T[1]=0;
   int len = strlen(pat);
   for(q=2;q<=len;q++)
   {  while (k>0 && pat[k]!=pat[q-1]) k=T[k];
         if(pat[k]==pat[q-1]) k++;
         T[q]=k;
   }
}
bool ok( )
{
       pre();
       int x = strlen(pat);
       int r = 0 , i ;
       for ( i = s ; i < txtlen ; i++ )
       {
           while( r > 0 && txt[i] != pat[r] )
           {
               r = T[r] ;
           }
           if( txt[i] == pat[r] ) r++;
           if( r == x )
           {
               s = i + 1 ;
               return 1 ;
           }

       }
       return 0 ;
}
int n ;
int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being
   while(read(n) == 1)
   {
       scanf("%s",txt);
       txtlen = strlen(txt);

       while( n-- )
       {
           s = 0 ;
           scanf("%s",inp);
           int len = strlen(inp);
           int i , x = 0 , chk = 1 ;
           for ( i = 0 ; i < len && chk ; i++ )
           {
               if( inp[i] == '*' )
               {
                   if( x )
                   {
                       pat[x] = '\0';
                       chk = ok();
                       x = 0 ;
                      // printf(" now :: %c chk :: %d\n",inp[i],chk);
                   }
               }
               else
               {
                   pat[x++] = inp[i];
               }
           }
           if( x )
           {
               pat[x] = '\0';
               chk = ok();
           }
           printf("%s\n",chk?"yes":"no");
       }
   }
    return 0;
}
