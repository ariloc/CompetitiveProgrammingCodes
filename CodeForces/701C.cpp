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
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int INF = 1e9;

set<char> typ;
map<char,int> aux;

int main() {
    FAST_IO;

    int n; cin >> n;
    string s; cin >> s;

    forn(i,n) typ.insert(s[i]);
    int cnt = (int)typ.size();

    int r = 0, mini = INF;
    forn(l,n) {
        while (r < n && (int)aux.size() < cnt) aux[s[r]]++, r++;

        if ((int)aux.size() < cnt) break;

        mini = min(mini,r-l);
        aux[s[l]]--;
        if (!aux[s[l]]) aux.erase(s[l]);
    }

    cout << mini;

    return 0;
}