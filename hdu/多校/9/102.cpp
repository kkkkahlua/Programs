#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define N 1010
//N为点数
#define M 6005
//M为边数
int n, m;

struct Edge{
    int from, to, nex;
    bool sign;//是否为桥
}edge[M<<1];
int head[N], edgenum;
void add(int u, int v){
    Edge E={u, v, head[u], false};
    edge[edgenum] = E;
    head[u] = edgenum++;
}

int DFN[N], Low[N], Stack[N], top, Time;
int taj;//连通分支标号，从1开始
int Belong[N];//Belong[i] 表示i点属于的连通分支
bool Instack[N];
vector<int> bcc[N]; //标号从1开始

void tarjan(int u ,int fa){
    DFN[u] = Low[u] = ++ Time ;
    Stack[top ++ ] = u ;
    Instack[u] = 1 ;

    for (int i = head[u] ; ~i ; i = edge[i].nex ){
        int v = edge[i].to ;
        if(DFN[v] == -1)
        {
            tarjan(v , u) ;
            Low[u] = min(Low[u] ,Low[v]) ;
            if(DFN[u] < Low[v])
            {
                edge[i].sign = 1;//为割桥
            }
        }
        else if(Instack[v]) Low[u] = min(Low[u] ,DFN[v]) ;
    }
    if(Low[u] == DFN[u]){
        int now;
        taj ++ ; bcc[taj].clear();
        do{
            now = Stack[-- top] ;
            Instack[now] = 0 ;
            Belong [now] = taj ;
            bcc[taj].push_back(now);
        }while(now != u) ;
    }
}

void tarjan_init(int all){
    memset(DFN, -1, sizeof(DFN));
    memset(Instack, 0, sizeof(Instack));
    top = Time = taj = 0;
    for(int i=1;i<=all;i++)if(DFN[i]==-1 )tarjan(i, i); //点标从0开始
}
vector<int>G[N];
int du[N];
void suodian(){
    memset(du, 0, sizeof(du));
    for(int i = 1; i <= taj; i++)G[i].clear();
    for(int i = 0; i < edgenum; i++){
        int u = Belong[edge[i].from], v = Belong[edge[i].to];
        if(u!=v)G[u].push_back(v), du[v]++;
    }
}
bool topsort(){
    queue<int>q;
    for(int i = 1; i <= taj; i++)if(du[i] == 0){q.push(i);du[i]=-1;break;}
    while(!q.empty()){
        int u = q.front(); q.pop(); du[u] = -1;
        for(int i = 0; i < G[u].size(); i++){
            int v = G[u][i]; if(du[v] == -1)continue;
            du[v] = -1;
            q.push(v);
            break;
        }
    }
    for(int i = 1; i <= taj; i++)if(du[i]!=-1)return false;
    return true;
}
int main(){
    int u, v, i, j, T;scanf("%d",&T);
    while(T--){
        scanf("%d %d", &n, &m);
        memset(head, -1, sizeof(head)); edgenum = 0;
        while(m--)
            scanf("%d %d",&u,&v), add(u,v);

        tarjan_init(n);
        suodian();

        topsort() ? puts("Yes") : puts("No");
    }
    return 0;
}
