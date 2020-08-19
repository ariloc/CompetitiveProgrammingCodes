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

map<string,string> asoc;

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    forn (i,n) {
        string pc,ip; cin >> pc >> ip;
        asoc[ip] = pc;
    }

    forn (i,m) {
        string comm,ip; cin >> comm >> ip;
        ip.pop_back();
        cout << comm << ' ' << ip << "; #" << asoc[ip] << '\n';
    }

    return 0;
}