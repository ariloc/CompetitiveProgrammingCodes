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

int const MAXQ = 190;

int radar(char borde, int i);

ii query(char dir, int tam, int cot) {
    for (int i = min(cot,tam); i <= tam; i += cot) {
        int v = radar(dir, i);
        if (v != -1) return {v,i};
    }
    return {-1, -1};
}

void tiranic(int m, int n, vector<int> &distancias) {
    char totry[] = {'O', 'N'}, op[] = {'E', 'S'};
    bool swapped = false;
    if (n < m) swap(m,n), swap(totry[0],totry[1]), swap(op[0],op[1]), swapped = true;

    // calc best combo
    int cot[] = {1, 100};
    forsn(i,2,m+1) {
        int ops = m/i;
        int otside = (100+(i-1)-1)/(i-1);
        ops += n/otside;
        if (ops+3 <= MAXQ) { // +3 to count extra queries
            cot[0] = i, cot[1] = otside;
            break;
        }
    }

    forn(_,2) {
        ii found = query(totry[0],m,cot[0]);
        if (found.fst != -1) {
            found.snd = radar(totry[1], found.fst+1);
            ii ot;
            ot.fst = radar(op[0], found.snd+1);
            ot.snd = radar(op[1], found.fst+1);
            if (!swapped) distancias = {found.snd, ot.fst, ot.snd, found.fst};
            else distancias = {found.fst, ot.snd, ot.fst, found.snd};
            return;
        }
        else {
            swapped = !swapped;
            swap(m,n), swap(totry[0],totry[1]), swap(op[0],op[1]);
            swap(cot[0],cot[1]);
        }
    }
}
