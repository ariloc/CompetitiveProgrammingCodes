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

int cursos(int C, vector<string> &alumnos, vector<string> &asignacion) {
    int n = sz(alumnos);
    map<string,int> each;
    for (auto &i : alumnos) each[i]++;
    vector<vector<string>> cur(C,vector<string>());
    vector<string> rem;
    for (auto &e : each) {
        forn(i,C) forn(_,e.snd/C) cur[i].pb(e.fst);
        forn(_,e.snd%C) rem.pb(e.fst);
    }
    while (!rem.empty()) forn(i,C) cur[i].pb(rem.back()), rem.pop_back();

    vector<string> rta;
    forn(i,C) for (auto &al : cur[i]) rta.pb(al);
    asignacion = rta;

    return n/C;
}
