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

    int N;
    cin >> N;

    forn(i,N) {
        ll n,s,k;
        set<int> done;
        cin >> n >> s >> k;

        forn (i,k) {
            ll x;
            cin >> x;
            done.insert(x);
        }

        if (!done.count(s)) {cout << 0 << '\n'; continue;}

        ll best = -1;
        forsn(i,1,n) {
            if (s-i > 0 and !done.count(s-i)) best = abs(s-(s-i));
            if (s+i <= n and !done.count(s+i) and (abs(s-(s+i)) < best or best == -1))
                best = abs(s-(s+i));
            if (best != -1)
                {cout << best << '\n'; break;}
        }
        continue;
    }

    return 0;
}