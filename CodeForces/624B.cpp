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

    vi let;
    forn (i,N) {
        int x; cin >> x;
        let.pb(x);
    }

    sort(all(let));

    ll sum = 0;
    map<int,bool> registered;
    dforn (i,let.size()) {
        int x = 0;
        while (registered.count(let[i]-x)) x++;
        sum += max(0,let[i]-x);
        if (let[i]-x > 0) registered[let[i]-x] = true;
    }

    cout << sum;

    return 0;
}