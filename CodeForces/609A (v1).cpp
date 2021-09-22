#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0 ; i < int(n); i++)

using namespace std;

vector<int> usb;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,r=0;
    long long sz;
    cin >> N;
    cin >> sz;
    forn(i,N) {
        int x;
        cin >> x;
        usb.push_back(x);
    }
    sort(usb.rbegin(),usb.rend());
    for(auto i : usb) {
        r++;
        sz-=i;
        if (sz <= 0) break;
    }
    cout << r << endl;
}