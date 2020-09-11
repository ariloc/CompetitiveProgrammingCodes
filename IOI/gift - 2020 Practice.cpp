#include "gift.h"

#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= s; i--)
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 5e5+5;

ii ranges[2*MAXN]; int ind = 0;
string necklace;
set<int> unblocked;
bitset<MAXN> enabled,twoBlockWide;
int FT[MAXN],aparic[5];

void setFT (int p, int v) {
    for (int i = p; i < MAXN; i += i & -i)
        FT[i] += v;
}

int getFT (int p) {
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

char op (char &i) {if (i == 'R') return 'B'; else return 'R';}

int construct(int n, int r, std::vector<int> a, std::vector<int> b, std::vector<int> x) {
    memset(aparic,-1,sizeof(aparic));
    necklace = string(n,'R'); // init
    forn(i,n) unblocked.insert(i+2);
    forn(i,r) {
        a[i] += 2; b[i] += 2; // desfase Fenwick
        if(x[i] == 1) { // si es de uno de ancho no me importa
            if (a[i] == b[i]) continue;
            auto it = unblocked.lower_bound(a[i]);
            vi toErase;
            while (it != unblocked.end() and (*it) <= b[i]) {toErase.pb(*it); it++;}
            for(auto &e : toErase) unblocked.erase(e);
        }
        else {
            if (b[i]-a[i] == 1) twoBlockWide[b[i]-2] = true;
            ranges[ind++] = {a[i],b[i]};
        }
    }

    auto it = unblocked.begin();
    int lstInd = -1;
    while (it != unblocked.end()) {
        int me = *it; enabled[me-2] = true;
        if (me-lstInd > 1) necklace[me-2] = 'B'; // checkboard pattern
        else necklace[me-2] = op(necklace[me-3]);
        lstInd = me;
        it++;
    }

    dforsn(i,1,n) { // caso borde
        if (twoBlockWide[i] and necklace[i] == necklace[i-1]) { // por twoBlockWide siempre i >= 1
            if (enabled[i-1]) necklace[i-1] = op(necklace[i-1]);
            else if (enabled[i]) necklace[i] = op(necklace[i]);
        }
    }

    forn(i,n) ranges[ind++] = {(necklace[i] == 'B')-2,i+2}; // checks finales

    sort(ranges,ranges+ind,[](const ii &a, const ii &b) {
        if (a.snd == b.snd) return a.fst < b.fst;
        return a.snd < b.snd;
    });

    // check si puedo
    bool posib = true;
    forn(i,ind) {
            //cerr << ranges[i].snd << ' ' << abs(ranges[i].fst) << endl;
        if (ranges[i].fst < 0) { // move the distinct
            if (aparic[abs(ranges[i].fst)] != -1) setFT(aparic[abs(ranges[i].fst)],-1);
            setFT(ranges[i].snd,1); aparic[abs(ranges[i].fst)] = ranges[i].snd;
        } else {
            int am = getFT(ranges[i].snd)-getFT(ranges[i].fst-1);
            if (am < 2) {posib = false; break;}
        }
    }

    if (posib) craft(necklace);

    return posib;
}
