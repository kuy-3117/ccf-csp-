#include<iostream>
#include<vector>
#include<cmath >
using namespace std;

int main()
{
	int n, N;
	cin >> n >> N;
	vector<int> A(n + 1, 0);
	for (int i = 1;i < n + 1;i++)
	{
		cin >> A[i];
	}
	int r = N / (n + 1);
	

	long long error = 0;
	for (int i = 0;i < N;i++)
	{
		int g = i / r;
		int f = 0;
		for (int j = n;j >= 0;j--)
		{
			if (i >= A[j])
			{
				f = j;
				break;
			}
		}

		error += abs(g - f);
	}
	cout << error;
}