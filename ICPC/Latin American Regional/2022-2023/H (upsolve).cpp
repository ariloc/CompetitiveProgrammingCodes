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
using pii = pair<int, int>;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

int const MAXN = 305;

set<int> posic[MAXN], bystpos[MAXN];
vector<string> horse;
map<string,int> mapita;
int stpos[MAXN];

set<int> intersect(set<int> &lhs, set<int> &rhs) {
    set<int> *a = &lhs, *b = &rhs;
    if ((*a).size() > (*b).size()) swap(a,b);
    set<int> rta;
    for (auto &i : *a) {
        if ((*b).count(i)) rta.insert(i);
    }
    return rta;
}

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) {
        string s; cin >> s;
        horse.pb(s);
        mapita[s] = i;
    }
    int r; cin >> r;
    forn(i,r) {
        int m,w; cin >> m >> w; --w;
        set<int> run;
        forn(j,m) {
            string s; cin >> s;
            run.insert(mapita[s]);
            stpos[mapita[s]] = max(stpos[mapita[s]],w);
        }
        if (posic[w].empty()) posic[w] = run;
        else {
            set<int> aux = intersect(posic[w],run);
            swap(posic[w],aux);
        }
    }

    set<int> unassigned;
    forn(i,n) unassigned.insert(i);
    forn(i,n) {
        if (posic[i].empty()) continue;
        vi toDel;
        for (auto &j : posic[i])
            if (stpos[j] > i) toDel.pb(j);
        for (auto &j : toDel) posic[i].erase(j);
        for (auto &j : posic[i]) unassigned.erase(j);
    }

    forn(i,n) if (!posic[stpos[i]].count(i)) bystpos[stpos[i]].insert(i), unassigned.erase(i);

    queue<int> pend;
    forn(i,n) {
        for (auto &j : bystpos[i]) pend.push(j);

        if (!posic[i].empty()) {
            cout << horse[*posic[i].begin()] << ' ';
            posic[i].erase(posic[i].begin());
            while (!posic[i].empty()) {
                pend.push(*posic[i].begin());
                posic[i].erase(posic[i].begin());
            }
        }
        else if (!pend.empty()) {
            cout << horse[pend.front()] << ' ';
            pend.pop();
        }
        else {
            cout << horse[*unassigned.begin()] << ' ';
            unassigned.erase(unassigned.begin());
        }
    }

    return 0;
}
