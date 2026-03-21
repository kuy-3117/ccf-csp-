#include<iostream>
#include<vector>

using namespace std;


int main()
{
	int n, a, b;
	cin >> n >> a >> b;

	vector<vector<int>> index(n, vector<int>(4));

	for (int i = 0;i < n;i++)
	{
		int x1, x2, y1, y2;

		cin >> x1 >> y1 >> x2 >> y2;
		if (x2 > a) x2 = a;
		if (y2 > b) y2 = b;
		if (x1 < 0) x1 = 0;
		if (y1 < 0) y1 = 0;

		index[i][0] = x1;
		index[i][1] = y1;
		index[i][2] = x2;
		index[i][3] = y2;
	}


	int sum = 0;
	for (int i = 0;i < n;i++)
	{
		if (index[i][2] > index[i][0] && index[i][3] > index[i][1])
		{
			sum += (index[i][2] - index[i][0]) * (index[i][3] - index[i][1]);
		}
	}
	cout << sum << endl;
	return 0;
}