#include<iostream>
#include<vector>
#include<map>
#include<cmath>
using namespace std;

bool is_prime(int n)
{
	
	if (n <= 1) return false;
	else if (n == 2) return true;
	else
	{
		for (int i = 2;i < (int)sqrt(n)+1;i++)
		{
			if (n % i == 0)
			{
				return false;
			}
		}
		return true;
	}
}


int main()
{
	int q;
	cin >> q;
	vector<int> res;
	vector<pair<int, int>> temp;
	for (int i = 0;i < q;i++)
	{
		int n, k;
		cin >> n >> k;
		temp.push_back({ n,k });
	}

	for(int i=0;i<q;i++)
	{ 
		int n = temp[i].first;
		int k = temp[i].second;
		map<int, int> CountMap;
		for (int i = 2;i*i <= n;i++)
		{
			if (n % i == 0 and is_prime(i))
			{

				if (CountMap.find(i) == CountMap.end())
				{
					CountMap[i] = 1;
				}
				else
				{
					CountMap[i]++;
				}
				n /= i;
				i--;
			}
		}


		for (auto& pair : CountMap)
		{
			if (pair.first < k)
			{
				pair.second = 0;
			}
		}

		int ans = 1;
		for (const auto& pair : CountMap)
		{
			ans *= pow(pair.first, pair.second);
		}

		res.push_back(ans);
	}

	for (auto i : res)
	{
		cout << i << endl;
	}

}


//#include <iostream>
//#include <cmath>
//using namespace std;
//
//// 函数：计算n简化后的值
//long long simplify(long long n, int k) {
//    if (n <= 1) return 1;  // n为0或1时直接返回1
//
//    long long result = 1;
//
//    // 处理质因数2
//    if (n % 2 == 0) {
//        int exponent = 0;
//        while (n % 2 == 0) {
//            n /= 2;
//            exponent++;
//        }
//        if (exponent >= k) {
//            result *= pow(2, exponent);
//        }
//    }
//
//    // 处理奇数质因数
//    for (long long i = 3; i * i <= n; i += 2) {
//        if (n % i == 0) {
//            int exponent = 0;
//            while (n % i == 0) {
//                n /= i;
//                exponent++;
//            }
//            if (exponent >= k) {
//                result *= pow(i, exponent);
//            }
//        }
//    }
//
//    // 处理剩余的质因数（n本身是质数的情况）
//    if (n > 1 && k <= 1) {
//        result *= n;
//    }
//
//    return result;
//}
//
//int main() {
//    int q;
//    cin >> q;
//
//    for (int i = 0; i < q; i++) {
//        long long n;
//        int k;
//        cin >> n >> k;
//
//        cout << simplify(n, k) << endl;
//    }
//
//    return 0;
//}