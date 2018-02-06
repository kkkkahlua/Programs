//1012.cpp

#include <iostream>
#include <iomanip>
int main()
{
	using namespace std;
	cout << "n e\n- -----------\n0 1\n1 2\n2 2.5\n";
	cout << fixed << setprecision(9);
	double sum=0;
	int factor=1;
	sum = 1;
	for (int i=1;i<=9;++i)
	{
		factor *= i;
		sum += 1/(double)factor;
		if (i>=3)cout << i << " " << sum << endl;
	}
	return 0;
}
