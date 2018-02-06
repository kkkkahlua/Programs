//4.cpp

#include <iostream>
#include <string>
using namespace std;
struct node {
	char val;
	bool flag = false;
	node* bro;
	node* son;
};
int tot = 0;
void add(node*& head, string s) {
	int len = s.length();
	node* temp = head, *fa = NULL;
	for (int i = 0; i < len; ++i) {
		s[i] = tolower(s[i]);
		if (head == NULL) {
			++tot;
			node* p = new node;
			p->val = s[i];
			p->son = NULL;
			p->bro = NULL;
			if (i == len-1) p->flag = true;
			if (fa) fa->son = p;
			head = p;
			if (tot == 1) temp = head;
			fa = head;
			head = head->son;
		}
		else {
			node* prev = NULL;
			while (head && head->val != s[i]) {
				prev = head;
				head = head->bro;
			}
			if (head) {
				if (i == len-1) head->flag = true;
				fa = head;
				head = head->son;
			}
			else {
				node* p = new node;
				p->val = s[i];
				p->son = NULL;
				p->bro = NULL;
				if (i == len-1) p->flag = true;
				prev->bro = p;
				fa = p;
				head = p->son;
			}
		}
	}
	head = temp;
}
void del(node* head, string s) {
	int len = s.length();
	for (int i = 0; i < len; ++i) {
		s[i] = tolower(s[i]);
		while (head && head->val != s[i]) head = head->bro;
//		if (!head) return false;
		if (i == len-1 && head->flag) head->flag = false;
		head = head->son;
	}
//	return false;
}
int main() {
	int n, k;
	while (cin >> n >> k) {
//		node* head = NULL;
		int i = 0;	
		bool flag = false, can = false;
		int tot = 0, ans;
		for (; i < n; ++i) {
			string s1, s2;
			cin >> s1 >> s2;
			if (s2 == "wnm") flag = true;
			if (s1[0] == 'i') {
//				add(head, s2);
				tot += s2.length();
			}
			else {
//				del(head, s2);
				tot -= s2.length();
			}
			if (!can && flag && tot % k == 0) {
				can = true;
				ans = i+1;
			}
		}
		if (!can) cout << "T_T\n";
		else cout << "^_^ " << ans << endl;
	}
	return 0;
}
