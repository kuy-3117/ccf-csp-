#include<iostream>
#include<vector>
using namespace std;


int main()
{
	int n, m;
	cin >> n >> m;
	vector<int>A(m + 1);
	A[0] = 0;
	for (int i = 1;i < m+1;i++)
	{
		cin >> A[i];
	}

	vector<int> dp(n + 1, 0);
	for (int i = 0;i < n + 1;i++)
	{
		for (int j = 0;j <= min(i,m);j++)
		{
			dp[i] = max(dp[i], dp[i - j] + A[j]);
		}
	}

	cout << dp[n];
}