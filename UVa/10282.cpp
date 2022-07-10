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
typedef long double ld;

map<string, string> dict;

int main() {
    string s;
    while (getline(cin,s) && !s.empty()) {
        string a,b;
        int ind = 0;
        for (ind = 0; s[ind] != ' '; ind++)
            a.pb(s[ind]);
        ++ind;
        for (; ind < (int)s.size(); ind++)
            b.pb(s[ind]);
        dict[b] = a;
    }
    while (getline(cin,s)) {
        if (dict.count(s)) cout << dict[s] << '\n';
        else cout << "eh\n";
    }

    return 0;
}