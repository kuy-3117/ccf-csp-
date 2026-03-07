#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int k;
	cin >> k;
	vector<double> vec;
	for (int i = 0;i < k;i++)
	{
		int p, q, n;
		cin >> p >> q >> n;
		vec.push_back(((n - p) * 1.0) / q);
	}

	vector<pair<double, double>> res;
	for (auto num : vec)
	{
		int i = (int)((num + 0.1) * 10);
		int j = (int)(((num + 0.1) * 10 - i+0.1) * 10);
		res.push_back({ i,j });
	}

	for (auto pair : res)
	{
		cout << pair.first << " " << pair.second << endl;
	}

}