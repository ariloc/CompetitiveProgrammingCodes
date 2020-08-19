#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

int main() {
    FAST_IO;

    int N; cin >> N;

    int sum = 0, maxP = 400;
    vi sep;
    forn (i,N) {
        int x; cin >> x;
        sum += x;
        forn (j,sep.size()) {
            int range = sum-sep[j];
            if (abs(180-range) < abs(maxP-180)) maxP = range;
        }
        sep.pb(sum);
        if (abs(sum-180) < abs(maxP-180)) maxP = sum;
    }

    cout << abs((360-maxP)-maxP);

    return 0;
}