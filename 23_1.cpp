#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> B(n);
	for (int i = 0;i < n;i++)
	{
		cin >> B[i];
	}

	int sum_max = B[0];
	int sum_min = B[0];
	for (int i = 1;i < n ;i++)
	{
		if (B[i] == B[i - 1])
		{
			sum_max += B[i];
			sum_min += 0;
		}
		else
		{
			sum_max += B[i];
			sum_min += B[i];
		}
	}

	cout << sum_max << endl << sum_min;
}
