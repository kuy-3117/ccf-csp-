#include<iostream>
#include<vector>
using namespace std;


int get_sum(vector<int> vec)
{
	int res = 0;
	for (auto i : vec)
	{
		res += i;
	}
	return res;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> position(n+1, vector<int>(m));
	for (int i = 1;i < n+1;i++)
	{
		for (int j = 0;j < m;j++)
		{
			int num;
			cin >> num;
			position[i][j] = num;
		}
	}

	vector<int> high_box(n + 1,0);

	for (int i = 1;i < n + 1;i++)
	{
		for (int j = 1;j < n + 1;j++)
		{
			bool flag = true;
			for (int k = 0; k < m;k++)
			{
				if (position[i][k] >= position[j][k])
				{
					flag = false;
				}
			}

			if (flag)
			{
				if (high_box[i] == 0)
				{
					high_box[i] = j;
				}
				else
				{
					if (get_sum(position[high_box[i]]) > get_sum(position[j]))
					{
						high_box[i] = j;
					}
				}
			}
		}
	}

	for (int i = 1;i < n + 1;i++)
	{
		cout << high_box[i] << endl;
	}

}