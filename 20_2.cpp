#include<iostream>
#include<vector>
using namespace std;

bool if_in(int x, int y, int xl, int yd, int xr, int yu)
{
	if (x >= xl and x <= xr and y <= yu and y >= yd) return true;
	return false;
}

int main()
{
	int n, k, t, xl, yd, xr, yu;
	cin >> n >> k >> t >> xl >> yd >> xr >> yu;
	vector<vector<pair<int, int>>> index(n);
	for (int i = 0;i < n;i++)
	{
		vector<pair<int, int>> temp;
		for (int j = 0;j < t;j++)
		{
			int x, y;
			cin >> x >> y;
			temp.push_back({ x,y });
		}

		index[i] = temp;
	}

	int res1 = 0;
	int res2 = 0;
	for (int i = 0;i < n;i++)
	{
		bool flag1 = false;
		bool flag2 = false;
		int count = 0;
		for (int j = 0;j < t;j++)
		{
			int x = index[i][j].first;
			int y = index[i][j].second;
			if (if_in(x, y, xl, yd, xr, yu))
			{
				flag1 = true;
				count++;
			}
			else
			{
				count = 0;
			}

			if (count == k)
			{
				flag2 = true;
				break;
			}
		}
		if (flag1) res1++;
		if (flag2) res2++;

	}

	cout << res1 << endl << res2;
}