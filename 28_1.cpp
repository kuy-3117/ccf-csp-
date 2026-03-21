#include<iostream>
#include<vector>

using namespace std;



int main()
{
	int  n;
	double i;
	cin >> n >> i;
	vector<double> bill(n+1);
	for (int j = 0;j <= n;j++)
	{
		int num;
		cin >> num;
		double res = num * pow(1 + i, -j);
		bill.push_back(res);
	}

	double res = 0;
	for (auto j : bill)
	{
		res += j;
	}
	cout << res;
}