#include<bits/stdc++.h>
#include<cassert>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int autocompletando(int K, vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto) {
    vector<string> pal;
    string cur;
    forn(i,sz(texto)) {
        if (texto[i] == ' ') {
            if (!cur.empty()) pal.pb(cur);
            cur = "";
        }
        else cur.pb(texto[i]);
    }
    if (!cur.empty()) pal.pb(cur);

    K -= 2;
    forsn(i,2,sz(pal)) {
        bool ok = false;
        forn(j,sz(r1)) if (r1[j] == pal[i-2] && r2[j] == pal[i-1] && r3[j] == pal[i]) {
            ok = true; break;
        }
        if (!ok) --K;
    }
    return K >= 0;
}
