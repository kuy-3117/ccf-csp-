#include<iostream>
#include<vector>
using namespace std;


int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> res(m, vector<int>(n,0));

	for (int i = 0;i < n;i++)
	{
		int k;
		cin >> k;
		for (int j = 0;j < k;j++)
		{
			int word;
			cin >> word;
			res[word - 1][i]++;
		}
	}

	for (auto i : res)
	{
		int sum1 = 0, sum2 = 0;
		for (auto j : i)
		{
			if (j > 0)
			{
				sum1++;
				sum2 += j;
			}
		}
		cout << sum1 << " " << sum2<<endl;
	}
}