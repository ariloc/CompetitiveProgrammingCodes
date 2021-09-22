#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0 ; i < int(n); i++)

using namespace std;

vector<int> usb;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, r = 0;
    cin >> N;
    forn (i,N) {
        int cnt = 0;
        forn (i,3) {
            int x;
            cin >> x;
            if (x) cnt++;
        }
        if (cnt >= 2) r++;
    }

    cout << r << endl;
}