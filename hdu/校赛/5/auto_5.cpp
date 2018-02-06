#include <iostream>
#include <ctime>
#include <cstdio>
using namespace std;
int main() {
	freopen("5.in", "w", stdout);
	cout << 30 << endl;
	srand(time(NULL));
	for (int i = 0; i < 30; ++i){
	int x = rand() % 5000 + 1;
	int y = rand() % 5000 + 1;
	int z = rand() % 5000 + 1;
	int n = rand() % 500000 + 1;
	cout << x << " " << y << " " << z << " " << n << endl;
}
	fclose(stdin);
	return 0;
}
