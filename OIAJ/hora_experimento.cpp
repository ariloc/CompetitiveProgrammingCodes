#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

int main() {
    FAST_IO;

    int h,m,s,d;
    cin >> h >> m >> s >> d;

    int hPlus = d / 3600;
    h += hPlus;
    d %= 3600;
    if (h > 23) h -= 24;

    int mPlus = d / 60;
    m += mPlus;
    d %= 60;
    if (m > 59) {h++; m -= 60;}
    if (h > 23) h -= 24;

    s += d;
    if (s > 59) {m++; s -= 60;}
    if (m > 59) {h++; m -= 60;}
    if (h > 23) h -= 24;

    //if (h-10 < 0) cout << 0;
    cout << h << ' ';
    //if (m-10 < 0) cout << 0;
    cout << m << ' ';
    //if (s-10 < 0) cout << 0;
    cout << s;

    return 0;
}