#include <bits/stdc++.h>

#define forn(i,n) for(ll i = 0; i < ll(n); i++)
#define forsn(i,s,n) for(ll i = ll(s); i < ll(n); i++)
#define dforn(i,n) for (ll i = ll(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = ll(n)-1; i >= ll(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

vector<ll> modulos;

vector<int> aplicando(string n, int d, vector<int> a, vector<int> b) {
    vector<int> resultado;

    modulos.resize(n.size()+2);
    modulos[0] = 0;//(n[0]-48)%d;

    forsn (i,1,n.size()) {
        modulos[i] = (modulos[i-1]*10 + (n[i]-48)) % d;
    }

    for (auto &i : modulos) cout << i << ' ';
    cerr << endl;

    forn (i,a.size()) {
        cout << modulos[b[i]-1]-modulos[a[i]-1] << endl;
    }

    return resultado;
}

#ifndef EVAL
    #include <iostream>

    int main() {
        freopen("aplicando1.in","r",stdin);

        string n;
        int d;
        cin >> n >> d;
        int q;
        cin >> q;
        vector<int> a, b;
        a.reserve(q);
        b.reserve(q);
        for (int i=0;i<q;i++) {
            int aValue, bValue;
            cin >> aValue >> bValue;
            a.push_back(aValue);
            b.push_back(bValue);
        }
        vector<int> ret = aplicando(n, d, a, b);
        for (int x : ret)
            cout << x << endl;
    }
#endif
