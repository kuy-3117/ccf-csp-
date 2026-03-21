#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> str_split(string s)
{
	vector<string> res;

	string temp = "";
	for (auto& i : s)
	{
		if (i != ' ')
		{
			if(i>='a' and i<='z') temp += i;

			else
			{
				temp += (i + 32);
			}
		}
		else
		{
			res.push_back(temp);
			temp = "";
		}
	}
	res.push_back(temp);

	return res;
}
void Remove_Same(vector<string>& vec)
{
	for (int i = 0;i < vec.size();i++)
	{
		for (int j = vec.size() - 1;j > i;j--)
		{
			if (vec[j] == vec[i])
			{
				vec.erase(vec.begin() + j);
			}
		}
	}
}

void print(vector<string> vec)
{
	for (auto i : vec)
	{
		cout << i << ' ';
	}
	cout << endl;
}

int main()
{
	int n, m;
	cin >> n >> m;
	cin.ignore();

	string s1, s2;
	getline(cin, s1);	
	getline(cin, s2);
	vector<string>A = str_split(s1);
	vector<string>B = str_split(s2);

	Remove_Same(A);
	Remove_Same(B);


	vector<string> same;
	for (auto i : A)
	{
		for (auto j : B)
		{
			if (i == j)
			{
				same.push_back(i);
				break;
			}
		}
	}

	print(A);
	print(B);
	print(same);
	int res1 = A.size() + B.size() - same.size();
	int res2 = same.size();
	cout << res2 << endl << res1;
	
}