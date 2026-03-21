#include<iostream>
#include<vector>
using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> S;
	for (int i = 0;i < n;i++)
	{
		int w, score;
		cin >> w >> score;
		S.push_back({ w,score });
	}
	int res = 0;

	for (int i = 0;i < n;i++)
	{
		res += S[i].first * S[i].second;
	}

	if (res < 0) res = 0;
	cout << res;

}