#include<iostream>
#include<vector>
using namespace std;



int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> P(m+1,0);
	vector<int> T(m+1,0);
	for (int i = 1;i <= m;i++)
	{
		int p;
		cin >> p;
		P[i] = p;
	}
	for (int i = 1;i <= m;i++)
	{
		int t;
		cin >> t;
		T[i] = t;
	}
	vector<int> earlist(m+1);

	for (int i = 1;i <= m;i++)
	{
		int temp = P[i];
		int res = 1;
		while (temp != 0)
		{
			res += T[temp];
			temp = P[temp];
		}
		earlist[i] = res;
	}

	for (int i = 1;i < m + 1;i++)
	{
		cout << earlist[i] << " ";
	}
	cout << endl;
	bool flag = true;//判断是否需要计算最晚开始时间
	for (int i = 1;i < m + 1;i++)
	{
		if (earlist[i] + T[i]-1 > n)
		{
			flag = false;
			break;
		}
	}


	//我应该可以先不考虑先后关系算出最晚值，然后再根据先后关系修改相应值
	if (flag)
	{
		vector<int> latest(m + 1,1);
		for (int i = 1;i < m + 1;i++)
		{
			if (P[i] == 0)
			{
				latest[i] = n - T[i]+1;
			}
			else
			{
				latest[i] = n -T[i] + 1;
			}
		}

		//这一步中的temp1.temp2二者间的关系需要理解清楚，不过整体思想与前面计算最早时间的相差不大
		for (int i = 1;i < m + 1;i++)
		{
			int temp1 = i;
			int temp2 = P[i];
			while (temp2 != 0)
			{
				if (latest[temp1] <= latest[temp2])
				{
					latest[temp2] = latest[temp1] - T[temp2];
				}
				int temp = temp2;
				temp2 = P[temp2];
				temp1 = temp;

			}
		}
	

		for (int i = 1;i < m + 1;i++)
		{
			cout << latest[i] << " ";
		}

	}
}