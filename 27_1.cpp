#include<iostream>
#include<vector>

using namespace std;


int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> A(n+1);
	for (int i = 1;i < n+1;i++)
	{
		int a;
		cin >> a;
		A[i] = a;
	}

	vector<long long> C(n+1,1);
	for (int i = 1;i < n+1;i++)
	{
		for (int j = 1;j <= i;j++)
		{
			C[i] *= A[j];
		}
	}
	vector<int> B(n+1,0);
	for (int i = 1;i < n+1;i++)
	{
		B[i] = (m % C[i] - m%C[i-1]) / C[i - 1];
	}
	for (int i = 1;i < n + 1;i++)
	{
		cout << B[i] << " ";
	}


}