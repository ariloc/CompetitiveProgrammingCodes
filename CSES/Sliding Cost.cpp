#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 2e5;

void fastscan(int &num) { // getchar_unlocked() mejor que getchar(), mejor que scanf()
    register int c;
    c=getchar_unlocked();
    for (; (c>47 && c<58); c=getchar_unlocked())
        {num = num*10 + c - 48;}
}

int arr[MAXN];
priority_queue<ii> low; // max queue tiene los primeros n/2(+1) menores
priority_queue<ii,vector<ii>,greater<ii>> high; // min queue tiene los ultimos n/2 mayores

bool isLeft (int ind, int pInd, int pLow, int pHigh) { // check is estaba en la queue low antes
    if (arr[ind] < pLow) return true;
    else if (arr[ind] == pLow) {
        if (arr[ind] == pHigh) {
            if (pInd >= ind) return true;
            return false;
        }
        return true;
    }
    return false;
}

int main() {
    int n=0,k=0; fastscan(n); fastscan(k);
    forn(i,n) fastscan(arr[i]);

    if (k == 1) {forn(i,n) printf("0 "); return 0;} // caso 1 (las queues se rompen por .empty())

    ll sum = 0; int cntL = 0, cntR = 0;
    forn(i,k) low.push({arr[i],i});
    while(low.size() > (k+1)/2) {high.push(low.top()); low.pop();} // balance
    forn(i,k) sum += abs(low.top().fst-arr[i]); // diferencias iniciales
    cntL = low.size(); cntR = high.size(); // cantidad REAL en cada queue inicial
    printf("%lld ",sum); // primer valor (output)

    forsn(i,k,n) {
        ii pLow = low.top(), pHigh = high.top(); // previos max y min de los heap

        sum -= abs(pLow.fst-arr[i-k]); // saco viejo
        sum += abs(pLow.fst-arr[i]); // pongo nuevo "falso" (me conviene)
        if (isLeft(i-k,pLow.snd,pLow.fst,pHigh.fst)) cntL--; // si estaba a la izquierda o no, cambio la cantidad
        else cntR--;

        while (!low.empty() and low.top().snd <= i-k) low.pop(); // saco expirados
        while (!high.empty() and high.top().snd <= i-k) high.pop();

        // "Sliding Median"
        if (arr[i] <= low.top().fst) {
            low.push({arr[i],i}); cntL++;
            if (arr[i-k] > pLow.fst) {high.push(low.top()); low.pop(); cntL--; cntR++;}
        }
        else if (arr[i] >= high.top().fst) {
            high.push({arr[i],i}); cntR++;
            if (arr[i-k] <= pLow.fst) {low.push(high.top()); high.pop(); cntL++; cntR--;}
        }
        else if (arr[i-k] <= pLow.fst) {low.push({arr[i],i}); cntL++;}
        else {high.push({arr[i],i}); cntR++;}

        while (!low.empty() and low.top().snd <= i-k) low.pop(); // saco expirados (nuevos descubiertos)
        while (!high.empty() and high.top().snd <= i-k) high.pop();

        int borderL = 0, borderR = 0; // desfases si son necesarios
        // CASO BORDE -> Si pasa uno de la high queue a la low queue (se hace mediana) y con una ventana de lado par, desfaso para no sumar mal
        if (!isLeft(low.top().snd,pLow.snd,pLow.fst,pHigh.fst) && !(k&1)) {borderL = 1; borderR = -1;}

        sum += (pLow.fst-low.top().fst)*(cntL+borderL)*(low.top().fst > pLow.fst ? 1 : -1); // sumo defases según cambio de mediana
        sum += (pLow.fst-low.top().fst)*(cntR+borderR)*(low.top().fst < pLow.fst ? 1 : -1);

        printf("%lld ",sum); // output
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
