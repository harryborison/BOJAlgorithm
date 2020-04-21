#include <math.h>
#include <stdio.h>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <stdlib.h>
using namespace std;

int main(void)
{
	string tmp, cyper;
	getline(cin,tmp);
	std::cin >> cyper;
	int c_idx = 0;
	string ans;
	for (int i = 0; i < tmp.size(); i++)
	{
		if (c_idx == cyper.size())
			c_idx = 0;
		//
		if (tmp[i] == ' ')
		{
			ans += ' ';
		}
		else
		{
			if (tmp[i] > cyper[c_idx])
			{
				ans += 'a' + (tmp[i] - cyper[c_idx] - 1);
			}
			else if (tmp[i] == cyper[c_idx])
			{
				ans += 'z';
			}
			else
			{
				int u = cyper[c_idx] - tmp[i];
				ans += 'z' - u;

			}
			///
		}
		c_idx++;

	}
	std::cout << ans;
	return 0;
}
