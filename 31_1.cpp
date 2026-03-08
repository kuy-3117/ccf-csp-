#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> op(n);
	vector<pair<int, int>> index(m);
	for (int i = 0;i < n;i++)
	{
		int dx, dy;
		cin >> dx >> dy;
		op[i] = { dx,dy };
	}

	for (int i = 0;i < m;i++)
	{
		int x, y;
		cin >> x >> y;
		for (auto& pair : op)
		{
			x += pair.first;
			y += pair.second;
		}

		index[i] = { x,y };
	}
	for (auto& pair : index)
	{
		cout << pair.first << ' ' << pair.second << endl;
	}
	
}