
 //BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */
#include <stdio.h>
#include <stdlib.h>
#define For(i,n) for( __typeof(n)i = 1 ; i <= n ; i++)
typedef long long int64;
//Fast Reader


//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

/* **************************************  My code start here ****************************************** */
inline int nextInt(){
    int x = 0;
    register int c = getc(stdin);
    int sign = 0;
    for( ; ((c < 48 || c > 57) && c != '-'); c = getc(stdin));
    if(c == '-'){
        sign = 1;
        c = getc(stdin);
    }
    for( ; c > 47 && c < 58; c = getc(stdin)) x = (x<<1) + (x<<3) + c - 48;
    if (sign) x = -x;
    return x;
}
const int inf = 1e9+7 ;
const int MX = 5e5+7 ;

struct node {
    int key, rnk, cnt;
    node *le, *ri;
    node (int key = 0, int rnk = rand ()) : key (key), rnk (rnk), cnt (1), le (0), ri (0) {}
};

class treap {
    typedef node* pNode;
    pNode root;

    int count (pNode cur) { return cur ? cur -> cnt : 0; }
    void updateCnt (pNode cur) { if (cur) cur -> cnt = 1 + count (cur -> le) + count (cur -> ri); }

    void split (pNode cur, pNode &le, pNode &ri, int key) {
        if (!cur) { le = ri = 0; return; }
        if (key < cur -> key ) split (cur -> le, le, cur -> le, key), ri = cur;
        else split (cur -> ri, cur -> ri, ri, key), le = cur;
        updateCnt (cur);
    }

    void merge (pNode &cur, pNode le, pNode ri) {
        if (!le || !ri) cur = le ? le : ri;
        else if (le -> rnk > ri -> rnk) merge (le -> ri, le -> ri, ri), cur = le;
        else merge (ri -> le, le, ri -> le), cur = ri;
        updateCnt (cur);
    }

    void insert (pNode &cur, pNode it) {
        if (!cur) cur = it;
        else if (it -> rnk > cur -> rnk) split (cur, it -> le, it -> ri, it -> key), cur = it;
        else insert ((it -> key < cur -> key) ? cur -> le : cur -> ri, it);
        updateCnt (cur);
    }

    void erase (pNode &cur, int key, int rnk) {
        if (!cur) return;
        if (cur -> key == key) {
         if (rnk == -1) rnk = cur -> rnk;
         if (rnk == cur -> rnk) merge (cur, cur -> le, cur -> ri);
         else erase (cur -> ri, key, rnk);
        } else erase ((key < cur -> key) ? cur -> le : cur -> ri, key, rnk);
        updateCnt (cur);
    }

    int countLess (pNode cur, int key) {
        if (!cur) return 0;
        if (key <= cur -> key) return countLess (cur -> le, key);
        return 1 + count (cur -> le) + countLess (cur -> ri, key);
    }

    int countLessEqual (pNode cur, int key) {
        if (!cur) return 0;
        if (key < cur -> key) return countLessEqual (cur -> le, key);
        return 1 + count (cur -> le) + countLess (cur -> ri, key);
    }

    int countEqual (pNode cur, int key) {
     if (!cur) return 0;
     if (key == cur -> key) return 1 + countEqual (cur -> ri, key);
     return countEqual (key < cur -> key ? cur -> le : cur -> ri, key);
    }

    pNode kThElement (pNode cur, const int kTh) {
        if (!cur or kTh >= count (cur)) return 0;
        if (kTh == count (cur -> le)) return cur;
        return kTh < count (cur -> le) ? kThElement (cur -> le, kTh) : kThElement (cur -> ri, kTh - (count (cur -> le) + 1));
    }

    void clear (pNode cur) {
        if (cur -> le) free (cur -> le);
        if (cur -> ri) free (cur -> ri);
        free (cur);
    }

    public:
        treap () { root = 0; }
        int size () { return count (root); }
        void clear () { clear (root); root = 0; }
        bool find (int key) { return countEqual (root, key) ? true : false; }
        void insert (int key, int rnk = rand ()) { insert (root, new node (key, rnk)); }
        void insert_unique (int key, int rnk = rand ()) { if (!countEqual (root, key)) insert (root, new node (key, rnk)); }
        void erase (int key, int rnk = -1) { erase (root, key, rnk); }
        int countLess(int key){ return countLess(root,key); }
        int operator [] (const int idx) { pNode cur = kThElement (root, idx); return cur ? cur -> key : -inf; }
};

treap tree[MX];
int n , maxV ;
void Add(int idx, int val)
{
    while( idx <= maxV )
    {
        tree[idx].insert(val);
        idx += ( idx & -idx);
    }
}
int remov(int idx,int val)
{
    while(idx <= maxV)
    {
        tree[idx].erase(val);
        idx += ( idx & -idx);
    }
}
int SUM(int idx, int val)
{
    int ans = 0 ;
    while(idx)
    {
        ans += tree[idx].countLess(val);
        idx -= (idx & -idx);
    }
    return ans ;
}
int inp[MX];
int main()
{
    int m , u , l , r , v , p;
    bool cln = 0 ;
    while( scanf("%d %d %d",&maxV,&m,&u)!=EOF)
    {
        if( cln )
        {
             For(i,maxV) tree[i].clear();
        }
        cln = 1 ;
        For(i,maxV)
        {
            inp[i] = nextInt();
            Add(i,inp[i]);
        }
        while(m--)
        {
            l = nextInt(), r = nextInt()  , v = nextInt() , p = nextInt();
            int64 ans = SUM(r,v) - SUM(l-1,v);
            remov(p,inp[p]);
            int64 x = ( u * ans ) / ( r - l + 1 );
            inp[p] = x ;
            Add(p,inp[p]);
        }
        For(i,maxV) printf("%d\n",inp[i]);

    }

}
