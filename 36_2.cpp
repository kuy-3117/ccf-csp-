#include<iostream>
#include<vector>
using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<int> A(n + 1);
	for (int i = 0;i < n + 1;i++)
	{
		cin >> A[i];
	}

	vector<int> B(n+1);
	B[0] = 0;
	for (int i = 1;i < n+1;i++)
	{
		cin >> B[i];
	}

	vector<int> res;
	for (int i = 0;i < n+1;i++)
	{
		int temp_B = B[i];
		
		B[i] = 0;
		int w = 0;
		int temp = 0;
		for (int j = 0;j < n + 1;j++)
		{
			temp = temp + A[j] - B[j];
			w = max(w, temp);
			
		}
		B[i] = temp_B;
		res.push_back(w);
	}

	for (int i = 1;i < n + 1;i++)
	{
		cout << res[i] << " ";
	}
	



}