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

const int MAXN = 2e5+5;

ll rta = 0, sum = 0;
ll FT[MAXN];

void setFT (int p, int v) {
    for (int i = p; i < MAXN; i += i & -i)
        FT[i] += v;
}

ll getFT (int p) {
    ll r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

int main() {
    FAST_IO;

    ll T,n; cin >> n; cin >> T;
    ll N = n;

    forn (i,n) {int x; cin >> x; setFT(i+1,x); sum += x;}

    while (n and sum) {
        rta += ll(T/sum)*n;
        T %= sum;

        while (n and sum > T) {
            int low = 0;
            int high = N+1;

            while (high - low > 1) {
                int mid = low + (high-low)/2;
                if (getFT(mid) > T) high = mid; // "upper_bound"
                else low = mid;
            }
            int outVal = getFT(high), inVal;
            if (high) inVal = getFT(high-1);
            else break;

            //cout << out << ' ' << in << ' ' << outVal << ' ' << inVal << endl;

            if (inVal == outVal) {sum = 0; break;}

            sum -= (outVal-inVal);
            setFT(high, -(outVal-inVal)); n--;
        }
    }

    cout << rta;

    return 0;
}