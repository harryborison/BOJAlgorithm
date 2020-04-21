#include <iostream>

using namespace std;

int main(void)
{
	int flag = 0;
	int N, L, D;
	int cnt=0;
	std::cin >> N >> L >> D;
	for (int t = 0; t < N; t++)
	{
		for (int k = 0; k < L; k++)
		{
			cnt++;
		}
		for (int u = 1; u <= 5; u++)
		{
			if (cnt % D == 0)
			{
				printf("%d", cnt);
				flag = 1;
				break;
			}
			cnt++;
		}
		if (flag == 1)
		{
			break;
		}
	}
	if (flag == 0)
	{
		for (;;)
		{
			if (cnt % D == 0)
			{
				printf("%d", cnt);
				break;
			}
			cnt++;
		}
		
	}
	return 0;
}