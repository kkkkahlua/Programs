#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;

struct Node
{
    Node *ch[2];
    int r,v,s;
    Node(int v):v(v)
    {
        r=rand();
        s=1;
        ch[0]=ch[1]=NULL;
    }
    void maintain()
    {
        s=1;
        if(ch[0]) s+=ch[0]->s;
        if(ch[1]) s+=ch[1]->s;
    }
    int cmp(int x)
    {
        if(x==v)return -1;
        return x<v?0:1;
    }
}*root;
void rotate(Node* &o,int d)
{
    Node *k=o->ch[d^1];
    o->ch[d^1]=k->ch[d];
    k->ch[d]=o;
    o->maintain();
    k->maintain();
    o=k;
}
void insert(Node* &o,int v)//可插入重复值
{
    if(o==NULL) o=new Node(v);
    else
    {
        int d=v < o->v? 0:1;
        insert(o->ch[d],v);
        if(o->ch[d]->r > o->r)
            rotate(o,d^1);
    }
    o->maintain();
}
void remove(Node* &o,int v)
{
    int d=o->cmp(v);
    if(d==-1)
    {
        Node *u=o;
        if(o->ch[0] && o->ch[1])
        {
            int d2= o->ch[0]->r < o->ch[1]->r ?0:1;
            rotate(o,d2);
            remove(o->ch[d2],v);
        }
        else
        {
            if(o->ch[0]==NULL) o=o->ch[1];
            else o=o->ch[0];
            delete u;
        }
    }
    else remove(o->ch[d],v);
    if(o) o->maintain();
}
int kth(Node *o,int k)//返回第k大的值,不是第k小
{
    if(o==NULL || k<=0 || k> o->s) return 1;
    int s = (o->ch[1]==NULL)?0:o->ch[1]->s;
    if(k==s+1) return o->v;
    else if(k<=s) return kth(o->ch[1],k);
    else return kth(o->ch[0],k-s-1);
}

const int maxn=200000+1000;
int n,m;
int F[maxn],size[maxn];
int findset(int i)
{
    if(F[i]==-1) return i;
    return F[i]=findset(F[i]);
}
void bind(int i,int j)
{
    int fa=findset(i);
    int fb=findset(j);
    if(fa!=fb)
    {
        if(size[fa]!=1)remove(root,size[fa]);
        if(size[fb]!=1)remove(root,size[fb]);
        insert(root,size[fa]+size[fb]);
        F[fa]=fb;
        size[fb] += size[fa];
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("29852.out", "w", stdout);

    root=NULL;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        F[i]=-1;
        size[i]=1;
    }
    while(m--)
    {
        int op,i,j,k;
        scanf("%d",&op);
        if(op==0)
        {
            scanf("%d%d",&i,&j);
            bind(i,j);
        }
        else if(op==1)
        {
            scanf("%d",&k);
            printf("%d\n",kth(root,k));
        }
    }
    return 0;
}
