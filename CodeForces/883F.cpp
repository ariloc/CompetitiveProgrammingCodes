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

set<string> str;

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(o,n) {
        string s; cin >> s;
        string aux;

        int cnt = 0;
        forn(i,s.size()) {
            if (cnt && s[i] != 'k' && s[i] != 'h')
                aux += string(cnt,'k'), cnt = 0;

            if (s[i] == 'u') aux += "oo";
            else if (s[i] == 'k') cnt++;
            else if (s[i] == 'h') {
                if (cnt) cnt = 0;
                aux.pb('h');
            }
            else aux.pb(s[i]);
        }
        if (cnt) aux += string(cnt,'k');
        str.insert(aux);
    }

    cout << (int)str.size();

    return 0;
}