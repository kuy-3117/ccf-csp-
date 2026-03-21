#include<iostream>
#include<vector>
using namespace std;

int f(int x, int b, int c)
{
	return x * x + b * x + c;
}

int main()
{
	int b, c, l, r;
	cin >> b >> c >> l >> r;
	int res=0;
	if (l % 2 == 0)
	{
		for (int i = l;i <= r;i += 2)
		{
			res += f(i, b, c);
		}
	}
	else
	{
		for (int i = l + 1;i <= r;i += 2)
		{
			res += f(i, b, c);
		}
	}

	cout << res * 2;
	return 0;
}