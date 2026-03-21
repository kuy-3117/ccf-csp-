#include<iostream>
#include<vector>
using namespace std;


int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<pair<int, int>> plan;
	for (int i = 0;i < n;i++)
	{
		int x, y;
		cin >> x >> y;
		plan.push_back({ x,y });
	}
	vector<int> search;
	for (int i = 0;i < m;i++)
	{
		int t;
		cin >> t;
		search.push_back(t);
	}

	
	for (int i = 0;i < m;i++)
	{
		int count = 0;
		int start = search[i] + k;
		for (int j = 0;j < n;j++)
		{
			if (plan[j].first>= start && plan[j].first<= start+plan[j].second-1)
			{
				count++;
			}
		}
		cout << count << endl;
	}

}