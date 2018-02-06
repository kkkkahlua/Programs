//1014.cpp

#include <iostream> 
#include <iomanip>
int gcd(int a,int b);
int main()
{
	using namespace std;
	int step,mod;
	while (cin >> step >> mod)
	{
		cout << setw(10) << step << setw(10) << mod;
		cout << "    ";
		if (gcd(step,mod)==1)
			cout << "Good Choice\n";
		else
			cout << "Bad Choice\n";
		cout << endl;
	}
	return 0;
}
int gcd(int a,int b)
{
	int temp;
	if (a<b)
	{
		temp = a;
		a = temp;
		temp = b;
	}
	while (b)
	{
		temp = a;
		a = b;
		b = temp%b;
	}
	return a;
}
