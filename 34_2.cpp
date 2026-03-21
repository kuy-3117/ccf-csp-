#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> ReStruct(const vector<vector<int>>& M,int n, int m, int p, int q)
{
	vector<int> A;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			A.push_back(M[i][j]);
		}
	}
	vector<vector<int>>res(p, vector<int>(q));

	for (int i = 0;i < A.size();i++)
	{
		res[i / q][i % q] = A[i];
	}
	return res;
}


int main()
{
	int n, m, t;
	cin >> n >> m >> t;
	vector<vector<int>> M;
	for (int i = 0;i < n;i++)
	{
		vector<int> temp;
		for (int j = 0;j < m;j++)
		{
			int k;
			cin >> k;
			temp.push_back(k);
		}
		M.push_back(temp);
	}
	vector<vector<int>> Operation(t, vector<int>(3));
	for (int i = 0;i < t;i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		Operation[i] = { a,b,c };
	}

	for (auto& pair : Operation)
	{
		if (pair[0] == 1)
		{
			M = ReStruct(M, n, m, pair[1],pair[2]);
			n = pair[1];
			m = pair[2];
		}
		else if (pair[0] == 2)
		{
			vector<vector<int>> T(m, vector<int>(n));
			for (int i = 0;i < n;i++)
			{
				for (int j = 0;j < m;j++)
				{
					T[j][i] = M[i][j];
				}
			}
			swap(n, m);
			M = T;
		}
		else if (pair[0] == 3)
		{
			cout << M[pair[1]][pair[2]]<<endl;
		}


	}
}