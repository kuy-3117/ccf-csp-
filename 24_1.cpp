#include<iostream>
#include<vector>
using namespace std;


int main()
{
	int n, N;
	cin >> n >> N;
	vector<int> A(n+1,0);
	for (int i = 1;i < n+1;i++)
	{
		cin >> A[i];
	}
	int sum = 0;

	for (int i = 1;i < n+1;i++)
	{
		sum += (i-1) * (A[i] - A[i - 1]);
	}

	sum += (N - A[n]) * n;
	cout << sum;
}