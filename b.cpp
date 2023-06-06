#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if (n==1)
	{
		cout << 0;
	}else if (n == 2)
	{
		cout << 1;
	}
	else if (n>2)
	{
		int a;
		vector<int> g{0,1};
		for (size_t i = 2; i < n; i++)
		{
			a = g[i - 1] + g[i - 2];
			g.push_back(a);
			a = 0;
		}
		cout << g[n-1];
	}
	
}
