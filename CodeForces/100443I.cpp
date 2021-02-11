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

struct wordPQ {
    string s;
    int day,appear;

    bool operator< (const wordPQ &o) const {
        return day > o.day;
    }
};

struct wordSET {
    string s;
    int appear;

    bool operator< (const wordSET &o) const {
        if (appear == o.appear) return s < o.s;
        return appear > o.appear;
    }
};

map<string,int> overall,tmp;
set<wordSET> ordered;
priority_queue<wordPQ> histo;

int main() {
    FAST_IO;

    //freopen("entrada.txt","r",stdin);

    string s; bool active = 0; int actDay = 0;
    while (getline(cin,s)) {
        if (s == "<text>") {
            active = 1, actDay++;
            while (!histo.empty() && actDay-histo.top().day >= 7) {
                auto e = histo.top(); histo.pop();
                ordered.erase({e.s,overall[e.s]});
                //cerr << overall[e.s] << ' ' << e.appear << "!!!!" << endl;
                overall[e.s] -= e.appear;
                if (!overall[e.s]) overall.erase(e.s);
                else ordered.insert({e.s,overall[e.s]});
            }
            continue;
        }
        if (s == "</text>") {
            active = 0;
            for (auto &i : tmp) {
                if (overall.count(i.fst)) ordered.erase({i.fst,overall[i.fst]});
                overall[i.fst] += i.snd;
                ordered.insert({i.fst,overall[i.fst]});
                histo.push({i.fst,actDay,i.snd});
            }
            tmp.clear();
            continue;
        }

        if (active) {
            string aux;
            s += ' '; // dummy
            forn(j,s.size()) {
                if (s[j] >= 'a' && s[j] <= 'z') aux += s[j];
                else {
                    if (aux.size() >= 4) tmp[aux]++;
                    aux.clear();
                }
            }
        }
        else if ((int)s.size() > 4 && s.substr(0,4) == "<top") {
            int topN = 0;
            forn(j,s.size()) if (s[j] >= '0' && s[j] <= '9') topN = topN*10 + s[j]-'0';

            cout << "<top " << topN << ">\n";
            int prv = -1, cnt = 0;
            for (auto &i : ordered) {
                cnt++;
                if (cnt > topN && i.appear != prv) break;
                cout << i.s << ' ' << i.appear << '\n';
                prv = i.appear;
            }
            cout << "</top>\n";
        }
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
