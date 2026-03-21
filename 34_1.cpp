#include<iostream>
#include<vector>
using namespace std;


int main()
{
	int n, m, p, q;
	cin >> n >> m >> p >> q;
	vector<int> A;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			int num;
			cin >> num;
			A.push_back(num);
		}
	}
	
	vector<vector<int>>res(p, vector<int>(q));

	for (int i = 0;i < A.size();i++)
	{
		res[i/q][i%q] = A[i];
	}

	for (auto i : res)
	{
		for (auto j : i)
		{
			cout << j << " ";
		}
		cout << endl;
	}
}