#include<bits/stdc++.h>
 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int main() {
    FAST_IO;

    int n; cin >> n;

    set<int> auxi;
    vi div;
    for (int i = 2; i*i <= n; i++) {
        if (!(n%i)) {
            div.pb(i);
            int ot = n/i;
            if (ot != i)
                div.pb(ot);
        }
    }
    sort(all(div));

    if (div.empty())
        cout << "1\n1 1\n";
    else {
        set<int> asked;
        dforn(i,div.size()) {
            bool ok = true;
            for (auto &j : asked)
                if (!(j%div[i])) { ok = false; break; }
            if (ok) asked.insert(div[i]);
        }
        cout << (int)asked.size() << '\n';
        for (auto &i : asked)
            cout << "1 " << i << '\n';
    }

    return 0;
}
