#include <cstdio>
#define maxn 100010
struct node {
    int k, a, id;
    node* lson, *rson, *fa;
    node(int kk = 0, int aa = 0, int ii = 0) : k(kk), a(aa), id(ii), lson(NULL), rson(NULL), fa(NULL) {}
};
int ans[maxn][3], n;
void traversal(node* root) {
    if (!root) return;
    int id = root->id;
    ans[id][0] = root->fa ? root->fa->id : 0;
    ans[id][1] = root->lson ? root->lson->id : 0;
    ans[id][2] = root->rson ? root->rson->id : 0;
//    printf("%d %d %d %d\n", id, ans[id][0], ans[id][1], ans[id][2]);
    traversal(root->lson);
    traversal(root->rson);
}
void work() {
    int k, a;
    scanf("%d%d", &k, &a);
    node* root = new node(k, a, 1);
    for (int i = 2; i <= n; ++i) {
        scanf("%d%d", &k, &a);
//        node nd(k, a, i);
        node* nd = new node(k, a, i);
        node* temp = root, *src = NULL;
        while (temp && a > temp->a) {
            src = temp;
            if (k < temp->k) temp = temp->lson;
            else temp = temp->rson;
        }
//        if (temp) printf("temp : %d\n", temp->id);
//        else printf("src : %d\n", src->id);
        if (!temp) {
            nd->fa = src;
            if (k < src->k) src->lson = nd;
            else src->rson = nd;
        }
        else {
            temp->fa = nd;
            if (k < temp->k) nd->rson = temp;
            else nd->lson = temp;
            if (!src) root = nd;
            else {
                nd->fa = src;
                if (k < src->k) src->lson = nd;
                else src->rson = nd;
            }
        }
    }
    traversal(root);
    printf("YES\n");
    for (int i = 1; i <= n; ++i) printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
}
int main() {
    freopen("2201.in", "r", stdin);
    while (scanf("%d", &n) != EOF) work();
    return 0;
}
