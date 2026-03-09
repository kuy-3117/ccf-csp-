#include<iostream>
#include<vector>
#include<string>
using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<vector<string>> table(n,vector<string>(8));
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < 8;j++)
		{
			cin >> table[i][j];
		}
	}

	vector<int> res;
	for (int i = 0;i < n;i++)
	{
		int count = 1;	
		for (int j = 0;j < i;j++)
		{
			bool flag = true;
			for (int k = 0;k < 8;k++)
			{
				if (table[i][k] != table[j][k])
				{
					flag = false;
					break;
				}
			}
			if (flag) count++;
		}
		res.push_back(count);
	}


	for (auto i : res)
	{
		cout << i << endl;
	}
}