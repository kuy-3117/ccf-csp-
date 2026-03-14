#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int predict(int y, int n)
{
	if (y < n) return 0;
	else return 1;
}

int main()
{
	int m;
	cin >> m;
	vector<pair<int, int>> Y;
	map<int, int> res;
	for (int i = 0;i < m;i++)
	{
		int y, result;
		cin >> y >> result;
		Y.push_back({ y,result });
		res[y] = 0;
	}

	for (auto& pair:res)
	{
		int temp = pair.first;
		for (int j = 0;j < m;j++)
		{
			if (predict(Y[j].first, temp) == Y[j].second)
			{
				res[temp]++;
			}
		}
	}
	int Max = 0;
	vector<int> max_count;
	for (auto& pair : res)
	{

		//cout << pair.first << ":" << pair.second << endl;
		if (pair.second > Max)
		{
			Max = pair.second;
		}
	}
	for (auto& pair : res)
	{
		if (pair.second == Max)
		{
			max_count.push_back(pair.first);
		}
	}

	sort(max_count.begin(), max_count.end());
	cout << max_count[max_count.size() - 1];
}