#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
int N;
int main(void)
{

    std::cin >> N;
    vector<int> sang;
    vector<int> gon;
    int check[203] = { 0, };
    for (int i = 0; i < N; i++)
    {
        int u;
        std::cin >> u;
        sang.push_back(u);
        check[u] = 1;
    }
    sort(sang.begin(), sang.end());
    for (int i = 1; i <= 2 * N; i++)
    {
        if (!check[i]) gon.push_back(i);
    }
    sort(gon.begin(), gon.end());
    int s_idx = 0;
    int g_idx = 0;
    int field = sang[0];
    sang.erase(sang.begin());
    int turn = 1; // gon 이 할차례
    // turn == 0 // sang이 할 차례
    s_idx++;
    while (1)
    {
      //  printf("%d %d %d\n", field, gon.size(), sang.size());
        if (sang.size() == 0 || gon.size() == 0)
            break;

        if (turn == 0)
        {
            if (field == -1)
            {
                field = sang[0];
                turn = 1;
                sang.erase(sang.begin());
            }
            else
            {
                auto it = upper_bound(sang.begin(), sang.end(), field);
                if (it == sang.end()) // gon 이 이상의 카드가 없다면
                {
                    field = -1;
                    turn = 1;
                }
                else
                {
                    turn = 1;
                    field = *it;
                    sang.erase(it);
                }
            }


        }
        else if (turn == 1) // gon 차례
        {
            if (field == -1)
            {
                field = gon[0];
                turn = 0;
                gon.erase(gon.begin());
            }
            else
            {
                auto it = upper_bound(gon.begin(), gon.end(), field);
                if (it == gon.end()) // gon 이 이상의 카드가 없다면
                {
                    field = -1; 
                    turn = 0; 
                }
                else
                {
                    turn = 0;
                    field = *it;
                    gon.erase(it);
                }
            }
        }
        //상근먼저시작
   
    }
    printf("%d %d", gon.size(), sang.size());

    return 0;
}