#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> A;
	for (int i = 0;i < n;i++)
	{
		int a;
		cin >> a;
		A.push_back(a);
	}

	vector<vector<int>> S;
	vector<vector<int>>T;
	for (int i = 0;i < m;i++)
	{
		int s;
		cin >> s;
		vector<int>temp;
		temp.push_back(s);
		for (int j = 0;j < s;j++)
		{
			int k;
			cin >> k;
			temp.push_back(k);
		}
		S.push_back(temp);

	}
	for (int i = 0;i < m;i++)
	{
		int t;
		cin >> t;
		vector<int>temp;
		temp.push_back(t);
		for (int j = 0;j < t;j++)
		{
			int k;
			cin >> k;
			temp.push_back(k);
		}
		T.push_back(temp);
	}

	for (int i = 0;i < m;i++)
	{
		vector<int> Si = S[i];
		vector<int>Ti = T[i];
		int ans1 = A[Si[1]];
		int ans2 = A[Ti[1]];
		for (int j = 2;j < Si[0];j++)
		{
			ans1 ^= A[Si[j]];
		}
		for (int j = 2;j < Ti[0];j++)
		{
			ans2 ^= A[Ti[j]];
		}

		if (ans1 == ans2) cout << "correct";
		else cout << "wrong";
		cout << endl;
	}
	return 0;
}