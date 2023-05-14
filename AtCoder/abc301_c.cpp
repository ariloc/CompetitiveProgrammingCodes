#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

const int MAXA = 255;
const string cards = "atcoder";

int bank[MAXA], bank2[MAXA];

bool special (char x) {
    for (auto &i : cards) if (i == x) return true;
    return false;
}

int main() {
    FAST_IO;

    string a,b; cin >> a >> b;

    string a1, b1;
    string a2,b2;
    for (auto &i : a) if (!special(i) && i != '@') a1.pb(i); else a2.pb(i);
    for (auto &i : b) if (!special(i) && i != '@') b1.pb(i); else b2.pb(i);

    sort(all(a1));
    sort(all(b1));

    if (a1 != b1 || (int)a2.size() != (int)b2.size()) {
        cout << "No";
        return 0;
    }

    string a3,b3;
    int cnt1 = 0, cnt2 = 0;
    for (auto &i : a2) if (special(i)) a3.pb(i); else cnt1++;
    for (auto &i : b2) if (special(i)) b3.pb(i); else cnt2++;

    sort(all(a3));
    sort(all(b3));

    for (auto &i : a3) bank[i]++;
    for (auto &i : b3) bank2[i]++;
    forn(i,MAXA) {
        int mini = min(bank[i],bank2[i]);
        bank[i] -= mini;
        bank2[i] -= mini;
    }

    bool posib = 1;
    forn(i,MAXA) {
        cnt2 -= bank[i];
        cnt1 -= bank2[i];
    }

    if (cnt1 == cnt2 && cnt1 >= 0 && cnt2 >= 0) {
        cout << "Yes";
    }
    else cout << "No";

    return 0;
}
