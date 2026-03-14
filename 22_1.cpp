#include<iostream>
#include<vector>
using namespace std;


int main()
{
	int n, m, L;
	cin >> n >> m >> L;
	vector<vector<int>> A(n, vector<int>(m));
	vector<int> h(L, 0);
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			cin >> A[i][j];
			h[A[i][j]]++;
		}
	}
	for (auto i : h)
	{
		cout << i << " ";
	}
	

}