// FIvanO
#include <iostream>
#include <fstream>
#include <iterator>
#include <math.h>
#include <algorithm>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <ctime>
#include <deque>
#define mp(x,y) make_pair(x,y)

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    string s;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        s += '#';
        bool flag = false;
        int l = s.length();
        l--;
        for (int j = 0; j < l; j++)
        {
            if ( (s[j] == s[j + 1]) || (s[j] == s[j + 2]) )
            {
                cout << "YES" << endl;
                flag = true;
                break;
            }
        }
        if (!flag) cout << "NO" << endl;
    }

    return 0;
}

