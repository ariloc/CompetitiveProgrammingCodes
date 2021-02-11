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

map<string,set<string>> wasUsed;
map<string,int> uses,realUses;
set<string> realUsers;
vector<pair<int,string>> lst;

int main() {
    FAST_IO;

    string s;
    int m; cin >> m; getline(cin,s);
    forn(i,m) {
        getline(cin,s);
        s += ' '; // dummy

        string w,usr; bool check = false;
        forn(j,s.size()) {
            if (s[j] == ' ') {
                if (!check) usr = w, check = true;
                else {
                    if (!wasUsed[usr].count(w)) realUses[w]++, wasUsed[usr].insert(w);
                    uses[w]++;
                }
                w.clear();
            } else w += s[j];
        }
        realUsers.insert(usr);
    }

    for (auto &i : realUses)
        if (i.snd == (int)realUsers.size()) lst.pb({uses[i.fst],i.fst});

    if (lst.empty()) return cout << "ALL CLEAR", 0;

    sort(all(lst),[](const auto &lhs, const auto &rhs)
                    {
                        if (lhs.fst == rhs.fst) return lhs.snd < rhs.snd;
                        return lhs.fst > rhs.fst;
                    });

    for (auto &i : lst) cout << i.snd << '\n';

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
