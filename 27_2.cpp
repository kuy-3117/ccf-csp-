#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
	int n, x;
	cin >> n >> x;
	vector<int> price(n);
	int sum = 0;
	for (int i = 0;i < n;i++)
	{
		cin >> price[i];
		sum += price[i];
	}
	int target = sum - x;
	vector<bool> dp(target+1, false);
	dp[0] = true;
	for (int i = 0;i < n;i++)
	{
		for (int j = target;j >= price[i];j--)
		{
			if (dp[j - price[i]]) dp[j] = true;
		}
	}

	int max_price = 0;
	for (int i = target;i >=0;i--)
	{
		if (dp[i])
		{
			max_price= i;
			break;
		}
	}

	int res = sum - max_price;
	cout << res;
}