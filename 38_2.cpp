#include<iostream>
#include<vector>
using namespace std;

//还是得用递归
void Move(vector<vector<bool>>& table,int k, int n, int x, int y)
{
	if (k < 0) return;
	table[x][y] = true;
	if (x - 1 >= 0 and y - 2 >= 0)
	{
		Move(table, k - 1, n, x - 1, y - 2);
	}
	if (x - 2 >= 0 and y - 1 >= 0)
	{
		Move(table, k - 1, n, x - 2, y - 1);
	}
	if (x - 1 >= 0 and y + 2 <n)
	{
		Move(table, k - 1, n, x - 1, y + 2);

	}
	if (x - 2 >= 0 and y + 1 <n)
	{
		Move(table, k - 1, n, x - 2, y +1);

	}
	if (x + 1 <n and y - 2 >= 0)
	{
		Move(table, k - 1, n, x +1, y -2);

	}
	if (x + 2 <n and y - 1 >= 0)
	{
		Move(table, k - 1, n, x + 2, y - 1);

	}
	if (x + 1 < n and y +2<n)
	{
		Move(table, k - 1, n, x +1, y + 2);

	}
	if (x + 2 < n and y + 1 < n)
	{
		Move(table, k - 1, n, x + 2, y + 1);

	}

}




int main()
{
	int n, k;
	cin >> n >> k;
	int x, y;
	cin >> x >> y;
	vector<vector<bool>> table(n, vector<bool>(n, false));
	Move(table, k, n, x - 1, y - 1);
	int res = 0;
	for (auto i : table)
	{
		for (auto j : i)
		{
			if (j) res++;
		}
	}

	cout << res;
	return 0;
	
}