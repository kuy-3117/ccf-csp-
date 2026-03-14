#include<iostream>
#include<vector>
using namespace std;

double Neighbor(const vector<vector<int>>& A, int x, int y, int r)
{
	int n = A.size();
	int res = 0;
	int count = 0;
	
	for (int i=x-r;i<=x+r;i++)
	{
		for (int j = y - r;j <= y + r;j++)
		{
			if (i < 0 or i >= n or j < 0 or j >= n)
			{
				continue;
			}
			else
			{
				res += A[i][j];
				count++;
			}
		}	
	}

	return (double)res / count;
}

int main()
{
	int n, L, r, t;
	cin >> n >> L >> r >> t;
	vector<vector<int>> A(n, vector<int>(n));
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			cin >> A[i][j];
		}
	}

	int res = 0;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			double a = Neighbor(A, i, j, r);

			if (a <= t) res++;
		}
	}
	cout << res;
	
}