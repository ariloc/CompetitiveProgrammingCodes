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

    string s; cin >> s;
    int N; cin >> N;

    bool prim = false, seg = false;
    forn (i,N) {
        string x; cin >> x;
        if (x == s) prim = seg = true;
        if (x[1] == s[0]) prim = true;
        if (x[0] == s[1]) seg = true;
    }

    if (prim and seg) cout << "YES";
    else cout << "NO";

    return 0;
}