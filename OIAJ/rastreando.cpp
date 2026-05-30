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
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const INF = 1e9;

vector<int> rastrear(vector<int> S);

int minsz(vector<ii> &ran) {
    int mini = INF;
    for (auto &i : ran) mini = min(mini,i.snd-i.fst);
    return mini;
}

vector<int> rastreando(int N) {
    vi p(N,-1);
    
    vector<ii> ran;
    ran.pb({0,N});
    while (minsz(ran) >= 2) {
        vector<ii> newran;
        for (auto &i : ran) {
            int mid = (i.fst+i.snd)/2;
            newran.pb({i.fst,mid});
            newran.pb({mid,i.snd});
        }
        swap(ran,newran);
        forn(i,N) if (p[i] != -1) p[i] *= 2;

        vi aux1, aux2;
        forn(i,ran.size())
            forsn(j,ran[i].fst,ran[i].snd)
                if (i&1) aux2.pb(j);
                else aux1.pb(j);

        vi r1 = rastrear(aux1);
        vi r2 = rastrear(aux2);

        set<int> sr1, sr2;
        for (auto &v : r1) sr1.insert(v);
        for (auto &v : r2) sr2.insert(v);

        for (auto &v : aux1)
            if (sr1.count(v) && p[v] != -1) p[v]++;
        for (auto &v : aux2)
            if (!sr2.count(v) && p[v] != -1) p[v]++;

        for (auto &v : r1)
            if (p[v] == -1) {
                forn(i,ran.size())
                    if (v >= ran[i].fst && v < ran[i].snd) {
                        p[v] = i+1;
                        break;
                    }
            }
        for (auto &v : r2)
            if (p[v] == -1) {
                forn(i,ran.size())
                    if (v >= ran[i].fst && v < ran[i].snd) {
                        p[v] = i-1;
                        break;
                    }
            }
    }
    
    for (auto &v : p) if (v != -1) v = ran[v].fst;

    vi auxi;
    forn(i,N) auxi.pb(i);
    vi rauxi = rastrear(auxi);
    int rt = rauxi.back();
    p[rt] = -1;

    forn(k,2) {
        auxi.clear();
        set<int> sauxi;
        forn(i,N) if ((i+k)&1) auxi.pb(i);
        rauxi = rastrear(auxi);
        for (auto &v : rauxi) sauxi.insert(v);
        for (auto &v : rauxi)
            if(p[v] != -1 && (p[v]+k)&1) {
                p[v]++;
            }

        for (int i = 1-k; i < N; i += 2)
            if (!sauxi.count(i) && !((p[i]+k)&1))
                p[i]++;
    }

    forn(j,N)
        if (p[j] == -1 && j != rt) {
            for (auto &i : ran) {
                if (i.fst <= j && j < i.snd && i.snd-i.fst > 1) {
                    if (i.fst == j) p[j] = i.fst+1;
                    else p[j] = i.fst;
                }
            }
        }

    return p;
}
