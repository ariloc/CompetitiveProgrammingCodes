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

    int t;
    cin >> t;

    forn (i,t) {
        int n,m,sum1 = 0, sum2 = 0;
        cin >> n >> m;

        forn (j,n) {
            int x;
            cin >> x;
            sum1 += x;
            if (j) sum2 += x;
        }

        int low = -1;
        int high = m+1;
        while (high - low > 1) {
            int mid = low + (high-low)/2;
            if (mid >= sum1) high = mid;
            else low = mid;
        }
        if (high >= m) cout << m << '\n';
        else cout << high << '\n';
    }

    return 0;
}