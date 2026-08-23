#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)

using namespace std;
typedef long long ll;

int main(){
    ll d,m,d1,n,d2; cin >> d >> m >> d1 >> n >> d2;

    int r = 0;
    forn(i,m) {
        if (d1 >= d) {
            d -= d1-d;
            r++;
        }
        if (d <= 0) { break; }
    }

    if (d <= 0) {
        cout << r << '\n';
        return 0;
    }

    forn(i,min(n,100000LL)) {
        if (d2 >= d) {
            d -= d2-d;
            r++;
        }
        if (d <= 0) { break; }
    }

    if (d <= 0) {
        cout << r << '\n';
        return 0;
    }

    cout << "-1\n";
    
    return 0;
}
