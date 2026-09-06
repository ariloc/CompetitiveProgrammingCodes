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

int recetas(vector<string> heladera, vector<vector<string> > libro, vector<int> &realizables) {
    set<string> ing;
    for (auto &s : heladera) ing.insert(s);
    vi realiz;
    forn(i,sz(libro)) {
        bool ok = true;
        for (auto &j : libro[i])
            if (!ing.count(j)) ok = false;
        if (ok) realiz.pb(i+1);
    }
    realizables = realiz;
    return sz(realiz);
}
