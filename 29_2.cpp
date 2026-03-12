#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;




int main()

{
	int n, m, k;
	cin >> n >> m >> k;
	vector<pair<int, int>> data_resource(n);

	for (int i = 0;i < n;i++)
	{
		int t, c;
		cin >> t >> c;
		data_resource[i] = { t,c };
	}

	sort(data_resource.begin(), data_resource.end(),
		[](const pair<int, int>& a, const pair<int, int>& b)
		{
			return a.first < b.first;
		});
	while (m > 0 && data_resource[0].first >= k)
	{
		m -= data_resource[n - 1].second;
		if (m < 0 or data_resource[n-1].first==k) break;
		data_resource[n - 1].first--;
		sort(data_resource.begin(), data_resource.end(),
			[](const pair<int, int>& a, const pair<int, int>& b)
			{
				return a.first < b.first;
			});

	}

	cout << data_resource[n - 1].first;

}