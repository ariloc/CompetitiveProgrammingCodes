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

const int MAXN = 2e5+5;

ii arr[MAXN];
int FT[MAXN];
set<ii> nums;

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

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) cin >> arr[i].fst, arr[i].snd = i+2; // desfaso por seguridad de FT

    sort(arr,arr+n);

    forn(i,n) swap(arr[i].fst,arr[i].snd);
    nums.insert(arr[0]); setFT(arr[0].fst,1);
    auto it = nums.begin(); ii med = (*it);
    cout << "0 ";

    ll cnt = 0, inv = 0;
    forsn(i,1,n) {
        if (arr[i].fst > med.fst) { // si estoy a la derecha de la mediana
            cnt += arr[i].fst-med.fst-1-getFT(arr[i].fst)+getFT(med.fst); // sumo cantidad de swaps a mediana, es la diferencia de ind menos cantidad de elementos en medio (FT)
            int behind = getFT(MAXN-1)-getFT(arr[i].fst);
            cnt -= behind; // los que están atrás mío como yo estoy ahora, requieren un swap menos
        }
        else {
            cnt += med.fst-arr[i].fst-1-getFT(med.fst-1)+getFT(arr[i].fst);
            int behind = getFT(arr[i].fst);
            cnt -= behind;
        }

        setFT(arr[i].fst,1);
        nums.insert(arr[i]);

        // corrimiento de mediana
        bool ch = false;
        if ((i+1)&1) {if (arr[i].fst > med.fst) it++, ch = true;} // si éramos pares, solo se mueve el iterador si es mayor
        else if (arr[i].fst < med.fst) it--, ch = true; // si éramos impares, solo se mueve si es menor

        // corrección de cnt por mover
        if (ch) {
            ii aux = (*it);
            ll dif = abs(med.fst-aux.fst)-1, cntL = getFT(min(med.fst,aux.fst));
            cnt -= dif*cntL*(aux.fst < med.fst ? 1 : -1);
            cnt += dif*(i+1-cntL)*(aux.fst < med.fst ? 1 : -1);
        }

        med = (*it);
        inv += getFT(MAXN-1)-getFT(arr[i].fst);// sumamos las inversiones del nuevo número

        cout << cnt+inv << ' ';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
