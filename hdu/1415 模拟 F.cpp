//1415.cpp

#include <iostream> 
#define max 10000
int action(int va,int vb,int no,int n);
void print(int no,int tot);
int ans[max][2];
int main()
{
	using namespace std;
	int ca,cb,n,step1,step2;
	while (cin >> ca >> cb >> n)
	{
		step1 = action(ca,cb,0,n);
		step2 = action(cb,ca,1,n);
		if (step1<step2)
			print(0,step1);
		else
			print(1,step2);
	}
}
int action(int va,int vb,int no,int n)
{
	int tot=0,a=0,b=0;
	while (1)
	{
		if (a==0)
		{
			switch (no)
			{
				case 0:ans[tot++][no] = 1;break;
				case 1:ans[tot++][no] = 2;break;
			}
			a = va;
		}
		if (a>vb-b)
		{
			a -= (vb-b);
			b = vb;
		}
		else
		{
			b += a;
			a = 0;
		}
		switch (no)
		{
			case 0:ans[tot++][no] = 3;break;
			case 1:ans[tot++][no] = 4;break;
		}		
		if (b==n)
			break;
		if (b==vb)
		{
			switch (no)
			{
				case 0:ans[tot++][no] = 6;break;
				case 1:ans[tot++][no] = 5;break;
			}
			b = 0;
		}	
	}
	return tot;
}
void print(int no,int tot)
{
	using std::cout;
	for (int i=0;i<tot;++i)
	{
		switch (ans[i][no])
		{
			case 1:cout << "fiil A\n";break;
			case 2:cout << "fill B\n";break;
			case 3:cout << "pour A B\n";break;
			case 4:cout << "pour B A\n";break;
			case 5:cout << "empty A\n";break;
			case 6:cout << "empty B\n";break;
		}	
	}
	cout << "success\n";
}
