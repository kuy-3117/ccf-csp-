#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int count = 0;

	vector<int> vec;
	for (int i = 0;i < k;i++)
	{
		int x, y;
		cin >> x >> y;
		bool flag = false;
		for (int j = 0;j < vec.size();j++)
		{
			if (vec[j] == y or y==0)
			{
				flag = true;
				break;
			}
		}
		vec.push_back(x);
		if (!flag) count++;
	}
	cout << count;
}