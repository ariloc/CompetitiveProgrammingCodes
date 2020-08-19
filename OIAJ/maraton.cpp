#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i<int(n); i++)

using namespace std;

int cat[10] = {};

int main() {
//    freopen("maraton.in","r",stdin);
    int n;
    cin >> n;
    forn (i,n) {
        int c,num;
        cin >> num >> c;
        if(!cat[c-1]) cat[c-1] = num;
    }
    forn (i,10) {
        cout << i+1 << ' ' << cat[i] << endl;
    }
    return 0;
}
