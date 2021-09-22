#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)

using namespace std;

int main() {
    pair<int, int> pos;
    int cnt = 0;
    forn(i,5) {
        forn(j,5) {
            int x;
            cin >> x;
            if (x) pos = {i+1,j+1};
        }
    }
    while(pos.first != 3) {
        if (pos.first > 3) pos.first--;
        else pos.first++;
        cnt++;
    }
    while(pos.second != 3) {
        if (pos.second > 3) pos.second--;
        else pos.second++;
        cnt++;
    }
    cout << cnt;
    return 0;
}