#include<iostream>
#include<string>
#include<vector>
using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<string> password;

	for (int i = 0;i < n;i++)
	{
		string s;
		cin >> s;
		password.push_back(s);
	}

	for (int i = 0;i < n;i++)
	{
		int level = 0;
		string s = password[i];
		bool flag = false;//三种不同字符
		bool flag3 = false;
		bool flag4 = false;
		bool flag5 = false;
		bool flag2 = true;//同一字符不超过两次
		for (auto i : s)
		{
			if (i >= '0' and i <= '9')
			{
				flag3 = true;
			}
			if (i >= 'A' and i <= 'z')
			{
				flag4 = true;

			}
			if (i == '*' or i == '#')
			{
				flag5 = true;

			}
		}
		if (flag3 and flag4 and flag5) flag=true;

		vector<pair<char, int>> vec;
		for (int i = 0;i < s.size();i++)
		{
			char c = s[i];
			int count = 1;
			for (int j = i + 1;j < s.size();j++)
			{
				if (c == s[j])
				{
					count++;
				}
			}
			if (count >= 3)
			{
				flag2 = false;
				break;
			}
		}

		if (flag)
		{
			level++;
			if (flag2)
			{
				level++;
			}
		}
		cout << level << endl;


	}
}