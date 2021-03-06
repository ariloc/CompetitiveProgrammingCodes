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

int main() {
    FAST_IO;

    int N; cin >> N;

    int cnt = 0;
    vi pairs;

    forn (i,N) {int x; cin >> x; pairs.pb(x); if (x) cnt++;}
    while (!pairs.empty() and !pairs.back()) pairs.pop_back();

    bool uni = false;
    forn (i,pairs.size()) {
        if (pairs[i]) uni = true;
        if (uni) if (!pairs[i])
            if ((i+1 >= (int)pairs.size() or pairs[i+1]) and (!i or pairs[i-1]))
                cnt++;
    }

    cout << cnt;

    return 0;
}