#include<iostream>
#include<vector>

using namespace std;


void print(vector<vector<int>> vec, int n)
{
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
		{
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	int n, L, S;
	cin >> n >> L >> S;
	vector<vector<int>> A(L+1, vector<int>(L+1, 0));
	vector<pair<int, int>> Tree;
	for (int i = 0;i < n;i++)
	{
		int x, y;
		cin >> x >> y;
		Tree.push_back({ x,y });
		A[x][y] = 1;
	}
	vector<vector<int>> B(S + 1);
	for (int i = S;i >=0;i--)
	{
		for (int j = 0;j < S + 1;j++)
		{
			int num;
			cin >> num;
			B[i].push_back(num);
		}
	}

	int count = 0;
	for (int i = 0;i < n;i++)
	{
		int x = Tree[i].first;
		int y = Tree[i].second;
		bool flag = true;
		for (int j = 0;j < S + 1;j++)
		{
			for (int k = 0;k < S + 1;k++)
			{
				if (x + j > L or y + k > L)
				{
					flag = false;
					break;
				}

				if (A[x + j][y + k] != B[j][k])
				{
					flag = false;
					break;
				}
			}
			if (!flag) break;

		}

		if (flag) count++;
	}
	
	cout << count;
	return 0;
}