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


const int mod = 1000007 ;

int R , C , K ;

int dp[ 22 ][ 22 ][ 402 ][ ( 1 << 4 ) + 5 ] , vis[ 22 ][ 22 ][404][ ( 1 << 4 ) + 5 ] , cs ;

int DP( int row , int col , int lft , int mask )
{
     if( row == R )
     {
         if( lft == 0 && mask == ( ( 1 << 4 ) - 1 ) ) return 1 ;
         else return 0 ;
     }
     int &v = vis[ row ][ col ][ lft ][ mask ];
     int &ret = dp[ row ][ col ][ lft ][ mask ];
     if( v == cs ) return ret ;
     v = cs ;
     ret = 0 ;
     ret = DP( ( col + 1 == C ? row + 1 : row ), ( col + 1 )%C , lft , mask )%mod;
     if( lft )
     {
         int tmpmask = mask ;
         if( row == 0 ) tmpmask |= ( 1 << 0 );
         if( row == R - 1 ) tmpmask |= ( 1 << 2 );
         if( col == C - 1 ) tmpmask |= ( 1 << 1 );
         if( col == 0 ) tmpmask |= ( 1 << 3 );
         int tmp = DP( ( col + 1 == C ? row + 1 : row ), ( col + 1 )%C , lft - 1, tmpmask )%mod;
         ret = ( ret + tmp )%mod ;
     }
     return ret ;
}

int main()
{
   // I will always use scanf and printf
   // May be i won't be a good programmer but i will be a good human being

     int t = II ;
     for ( cs = 1 ; cs <= t ; cs++ )
     {
         R = II , C = II , K = II ;
         int ans ;
         if( K > ( R * C ) ) ans = 0 ;
         else if( K == ( R * C ) ) ans = 1 ;
         else ans = DP( 0 , 0 , K , 0 )%mod ;
         printf("Case %d: %d\n",cs,ans);
     }



    return 0;
}
