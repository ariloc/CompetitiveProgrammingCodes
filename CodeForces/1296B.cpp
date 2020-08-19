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

const int MAXN = std::numeric_limits<int>::max();

int binSrch (int &x) {
    int low = 0;
    int high = MAXN;

    while (high - low > 1) {
        int mid = low + (high - low) / 2;
        if (mid-floor(mid/10) >= x) high = mid;
        else low = mid;
    }

    return high;
}

int main() {
    FAST_IO;

    int t;
    cin >> t;

    forn (i,t) {
        int s;
        cin >> s;

        cout << binSrch(s) << '\n';
    }

    return 0;
}