#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

void F(string& line, vector<char> f)
{
	string temp = "";
	for (auto i : line)
	{
		if (f[i] == '#')
		{
			temp += i;
		}
		else
		{
			temp += f[i];
		}
	}

	line = temp;
}



int main()
{
	string line;
	getline(cin, line);
	int n;
	cin >> n;
	cin.ignore();
	vector<char> f(128, '#');
	for (int i = 0;i < n;i++)
	{
		string s;
		getline(cin, s);
		f[s[1]] = s[2];
	}

	int m;
	cin >> m;
	for (int i = 0;i < m;i++)
	{
		string temp = line;
		int k;
		cin >> k;
		for (int j = 0;j < k;j++)
		{
			F(temp, f);
		}
		cout << temp << endl;
	}
}


//int main()
//{
//	cout << (int)'#';
//}