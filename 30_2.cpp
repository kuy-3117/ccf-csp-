#include<iostream>
#include<vector>
using namespace std;


vector<vector<long long>> Build(int n,int d)
{
	vector<vector<long long>> vec(n, vector<long long>(d));
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < d;j++)
		{
			cin >> vec[i][j];
		}
	}

	return vec;
}

//向量乘法有点小问题啊
vector<vector<long long>> A_B(vector<vector<long long>> Q, vector<vector<long long>> Kt)
{
	int n = Q.size();
	int m = Q[0].size();
	int d = Kt[0].size();
	vector<vector<long long>> res(n, vector<long long>(d,0));
	
	

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < d;j++)
		{
			for (int k = 0;k < m;k++)
			{
				res[i][j] += Q[i][k] * Kt[k][j];
			}
		}
	}
	return res;
}

int main()
{
	int n, d;
	cin >> n >> d;
	vector<vector<long long>> Q = Build(n, d);
	vector<vector<long long>> K = Build(n, d);
	vector<vector<long long>> V = Build(n, d);
	vector<int> W(n);
	for (int i = 0;i < n;i++)
	{
		cin >> W[i];
	}

	vector<vector<long long>> Kt(d, vector<long long>(n));

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < d;j++)
		{
			Kt[j][i] = K[i][j];
		}
	}
	vector<vector<long long>> Q_Kt = A_B(Q, Kt);

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < d;j++)
		{
			Q_Kt[i][j] *= W[i];
		}
	}
	vector<vector<long long>> res = A_B(Q_Kt, V);

	for (auto i : res)
	{
		for (auto j : i)
		{
			cout << j << " ";
		}
		cout << endl;
	}

}