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
vector<string> tmp;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	std::cin >> N;
	deque<int> q;
	string u;
	while (N--)
	{
		string tmp;
		std::cin >> tmp;
		if (tmp[0] == 'f') // front
		{
			if (q.size() == 0)
			{
				cout << "-1\n";
			}
			else
			{
				cout << q.front() << "\n";
			}
		}
		if (tmp[0] == 'b') // back
		{
			if (q.size() == 0)
			{

				cout << "-1\n";
			}
			else
			{
				cout << q.back() << "\n";
			}
		}
		if (tmp[0] == 'e')
		{
			if (q.empty()) cout << "1\n";
			else cout << "0\n";
		}
		if (tmp[0] == 's')
		{
			cout << q.size() << "\n";
		}
		if (tmp[0] == 'p' && tmp[1] == 'u')
		{
			string temp;
			std::cin >> temp;
			q.push_back(atoi(temp.c_str()));
		}
		else if(tmp[0] == 'p' && tmp[1] == 'o')// pop
		{
			if (q.size() == 0)
				cout << "-1\n";
			else
			{
				cout << q.front() << "\n";
				q.pop_front();
			}
		}
	}
	
	return 0;
}
