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

multiset<int> ls,rs;

int main() {
    FAST_IO;

    int q; cin >> q;
    forn(i,q) {
        char typ; cin >> typ;
        int l,r; cin >> l >> r;
        if (typ == '+') {
            ls.insert(l);
            rs.insert(r);
        }
        else {
            ls.erase(ls.find(l));
            rs.erase(rs.find(r));
        }

        if (!ls.empty() && (*rs.begin()) < (*ls.rbegin()))
            cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
