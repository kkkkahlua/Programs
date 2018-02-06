//1415.cpp

#include <iostream>
#define max 10000
struct queue
{
	int a,b,ori,no;
};
void print(queue q[],int tot);
int main()
{
	using namespace std;
	int ca,cb,n,front,rear;
	queue q[max];
	while (cin >> ca >> cb >> n)
	{
		front = rear = 0;
		q[0].a = q[0].b = q[0].no = 0;q[0].ori = -1;
		while (1)
		{
			if (q[front].a<ca && q[front].b<cb)
			{
				q[++rear].a = ca;
				q[rear].b = q[front].b;
				q[rear].ori = front;
				q[rear].no = 1;
				if (q[rear].b == n)
				{
					print(q,rear);
					break;
				}
				q[++rear].a = q[front].a;
				q[rear].b = cb;
				q[rear].ori = front;
				q[rear].no = 2;
				if (q[rear].b == n)
				{
					print(q,rear);
					break;
				}							
			}
			if (q[front].a!=0 && q[front].b!=cb)
			{
				if (cb-q[front].b>q[front].a)
				{
					q[++rear].b = q[front].b+q[front].a;
					q[rear].a = 0;
				}
				else
				{
					q[++rear].b = cb;
					q[rear].a = q[front].a-(cb-q[front].b);
				}
				q[rear].ori = front;
				q[rear].no = 3;
				if (q[rear].b == n)
				{
					print(q,rear);
					break;
				}
			}
			if (q[front].b!=0 && q[front].a!=ca)
			{
				if (ca-q[front].a>q[front].b)
				{
					q[++rear].a = q[front].a+q[front].b;
					q[rear].b = 0;
				}
				else
				{
					q[++rear].a = ca;
					q[rear].b = q[front].b-(ca-q[front].a);
				}
				q[rear].ori = front;
				q[rear].no = 4;
				if (q[rear].b == n)
				{
					print(q,rear);
					break;
				}
			}
			if (q[front].a!=0 && q[front].b!=0)
			{
				q[++rear].a = 0;
				q[rear].b = q[front].b;
				q[rear].ori = front;
				q[rear].no = 5;
				if (q[rear].b == n)
				{
					print(q,rear);
					break;
				}			
				q[++rear].a = q[front].a;
				q[rear].b = 0;
				q[rear].ori = front;
				q[rear].no = 6;
				if (q[rear].b == n)
				{
					print(q,rear);
					break;
				}
			}
			++front;
		}
	}
}
void print(queue q[],int tot)
{
	using namespace std;
	int ans[max];
	int p = tot,num=0;
	while (q[p].ori!=-1)
	{
		ans[num++] = p;
		p = q[p].ori;
	}
	for (int i=num-1;i>=0;--i)
	{
		switch (q[ans[i]].no)
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
