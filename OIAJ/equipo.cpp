#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

pair< ll,pair<string,int> > best = {0,{"",0}};

struct trie {
    map<char,trie> ramas;
    int pasadas = 0;

    void insert (int pos, const string &s) {
        if (s.size()+1 != pos) {
            pasadas++;
            if (pasadas > 1) {
                ll calc = pasadas*pos*pos;
                if (calc > best.fst)
                    best = {calc,{s,pos}};
            }

            ramas[s[pos]].insert(pos+1,s);
        }
    }
};



int main() {
    FAST_IO;
    freopen("equipo.in","r",stdin);
    freopen("equipo.out","w",stdout);

    trie T;
    int p,c;

    cin >> p >> c;
    forn (i,c) {
        string s;
        cin >> s;
        T.insert(0,s);
    }

    cout << best.fst << '\n';
    forn (i,best.snd.snd) cout << best.snd.fst[i];

    return 0;
}
