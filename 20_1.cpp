#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

bool MySort(pair<double, int> A, pair<double, int>B)
{
	if (A.first != B.first) return A.first < B.first;
	else
	{
		return A.second < B.second;
	}
}


int main()
{
	int n, X, Y;
	cin >> n >> X >> Y;
	vector<pair<int, int>> index(n+1);
	for (int i = 1;i <= n;i++)
	{
		int x, y;
		cin >> x >> y;
		index[i] = { x,y };
	}

	vector<pair<double,int>> Dis(n+1);
	Dis[0] = { -1,0 };
	for (int i = 1;i <= n;i++)
	{
		double dis = sqrt(pow(index[i].first - X, 2) + pow(index[i].second - Y, 2));
		Dis[i] = { dis,i };
	}

	sort(Dis.begin(), Dis.end(),MySort);

	for (int i = 1;i <= 3;i++)
	{
		cout << Dis[i].second << endl;
	}



}