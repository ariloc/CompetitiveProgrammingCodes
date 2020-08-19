#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 1e5;

ll calc(ll x) {
    return (x*(x+1))+((x*(x-1))/2);
}

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        int x; cin >> x;

        int cnt = 0;
        while (x > 1) {
            int low = -1;
            int high = MAXN;
            while (high-low>1) {
                int mid = (high+low)/2;
                if (calc(mid) >= x) high = mid;
                else low = mid;
            }
            cnt++;
            x -= ((calc(high) <= x) ? calc(high) : calc(low));
        }
        cout << cnt << '\n';
    }

    return 0;
}