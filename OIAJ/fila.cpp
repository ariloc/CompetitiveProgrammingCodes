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

struct Fecha {
    int dia, mes,anno;

    bool operator> (const Fecha &o) const{
        if (o.anno == anno) {
            if (o.mes == mes) {
                return o.dia < dia;
            }
            return o.mes < mes;
        }
        return o.anno < anno;
    }

    bool operator== (const Fecha &o) const{
        if (dia == o.dia and mes == o.mes and anno == o.anno) return true;
        return false;
    }
};

bool sortCriteria (const ii &a, const ii &b) {
    if (a.fst == b.fst) return a.snd < b.snd;
    return a.fst > b.fst;
}

vector<Fecha> cercano;
vector<ii> angry; // enojo | id

int binSrch (Fecha &x, int &N) {
    int high = N;
    int low = -1;

    while (high-low > 1) {
        int mid = low + (high-low)/2;
        if (cercano[mid] > x) high = mid;
        else low = mid;
    }

    if (high < 0) return -1;
    return high;
}

int fila(vector<Fecha> orden, vector<int> &enojados) {
    Fecha young = {-1,-1,-1};
    forn (i,orden.size()) {
        if (young.dia == -1) young = orden[i];
        else if (orden[i] > young) young = orden[i];

        cercano.push_back(young);
    }

    forn (i,orden.size()) {
        int res = binSrch(orden[i],i);
        if (res == -1) res = 0;
        res = i-res;
        angry.push_back({res,i+1});
    }

    sort(all(angry),sortCriteria);

    int best = angry[0].fst;
    for (auto &i : angry) {
        if (!i.fst) break;
        enojados.push_back(i.snd);
    }
    return best;
}
