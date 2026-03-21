#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
using namespace std;


int main()
{
	int n, m;
	cin >> n >> m;

	vector<pair<int, double>> op;
	for (int i = 0;i < n;i++)
	{
		int k;
		double p;
		cin >> k >> p;
		op.push_back({ k,p });
	}

	vector<vector<double>> op_list;
	vector<pair<double,double>> res;
	for (int k = 0;k < m;k++)
	{
		double i, j, x, y;
		cin >> i >> j >> x >> y;
		op_list.push_back({ i,j,x,y });
	}

	for (int k = 0;k < m;k++)
	{
		double i = op_list[k][0];
		double j = op_list[k][1];
		double x = op_list[k][2];
		double y = op_list[k][3];


		for (int p = i - 1;p < j;p++)
		{
			if (op[p].first == 1)
			{
				x = op[p].second * x;
				y = op[p].second * y;
			}
			else
			{
				double temp = x;
				x = x * cos(op[p].second) - y * sin(op[p].second);
				y = temp * sin(op[p].second) + y * cos(op[p].second);
			}

		}

		res.push_back({ x,y });
	}

	for (auto& pair : res)
	{
		cout<<fixed<<setprecision(3) << pair.first << " " << pair.second << endl;
	}



}