/*
 Author: Fasiul Kabir
  prob: uva 10305 - Ordering Tasks
  type: precedence topo sort
*/
 
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
 
int nV, nC;
vector <int> edge[110];
int seen[110], indegree[110];
queue <int> Q;
 
void topo(){
        int i, u, v, flag = 0;
        for(i=1; i<=nV; i++){
                if( !indegree[i] ){
                        Q.push(i);
                        seen[i] = 1;
                }
        }
        while( !Q.empty() ){
                u = Q.front();Q.pop();
                for(i=0; i<edge[u].size(); i++){
                        v = edge[u][i];
                        indegree[v]--;
                        if( !indegree[v] && !seen[v] ){
                                Q.push(v);
                                seen[v] = 1;
                        }
                }
                if(!flag){
                        printf("%d", u);
                        flag = 1;
                }else
                        printf(" %d", u);
        }
        printf("\n");
}
 
void init(int n){
        for(int i=0; i<=n; i++){
                indegree[i] = 0;
                seen[i] = 0;
                edge[i].clear();
        }
}
 
int main(){
        int i, u, v;
        while(scanf("%d%d", &nV, &nC)&&(nV||nC)) {
        init(nV);
 
        for(i=0; i<nC; i++){
            scanf("%d%d", &u, &v);
            edge[u].push_back(v);
            indegree[v]++;
        }
        topo();
        }
 
        return 0;
}
 
