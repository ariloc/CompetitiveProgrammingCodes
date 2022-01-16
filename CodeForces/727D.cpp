#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

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

const int MAXT = 6;
const int MAXN = 1e5+5;

const string sz_txt[] = {"S", "M", "L", "XL", "XXL", "XXXL"};

int shirts[MAXT];
map<string,int> sizes;
string rta[MAXN];
vector<ii> typ;

int main() {
    FAST_IO;

    forn(i,MAXT) sizes[sz_txt[i]] = i;

    forn(i,MAXT) cin >> shirts[i];

    int n; cin >> n;
    forn(i,n) {
        string s; cin >> s;
        auto pos = s.find(',');
        if (pos == string::npos) 
            if ((--shirts[sizes[s]]) >= 0)
                rta[i] = s;
            else return cout << "NO", 0;
        else typ.pb({sizes[s.substr(0,pos)],i});
    }

    sort(all(typ));

    for (auto &i : typ) {
        if ((--shirts[i.fst]) >= 0)
            rta[i.snd] = sz_txt[i.fst];
        else if ((--shirts[i.fst+1]) >= 0)
            rta[i.snd] = sz_txt[i.fst+1];
        else return cout << "NO", 0;
    }

    cout << "YES\n";
    forn(i,n) cout << rta[i] << '\n';

    return 0;
}