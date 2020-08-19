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

const int MAXN = 102;
const int MAXP = 10000;
bitset<MAXN> PB;
bitset<MAXN> PR;

int main() {
    FAST_IO;

    int N, dif = 0; cin >> N;
    forn (i,N) {
        int x; cin >> x;
        if (x) PR[i] = true;
    }
    forn (i,N) {
        int x; cin >> x;
        if (x) PB[i] = true;
    }
    int SR, SB; SR = SB = 0;
    forn (i,N) {
        if (PR[i] and !PB[i]) dif++;
        if (PR[i]) SR++;
        if (PB[i]) SB++;
    }
    int toOvercome = SB-SR;
    if (toOvercome < 0) cout << 1;
    else if (!dif) cout << -1;
    else {
        int high = MAXP;
        int low = 0;

        while(high-low > 1) {
            int mid = low + (high - low)/2;
            if (SR-dif+(mid*dif) >= SB+1) high = mid;
            else low = mid;
        }

        cout << high;
    }

    return 0;
}