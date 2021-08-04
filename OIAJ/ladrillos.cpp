#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define fst first
#define snd second

using namespace std;
typedef pair<int, int> ii;

vector<long long> f;
const int MAXN = 46;
const long long invalid = 1e9+10;

int fibo[MAXN];

void obtenerSecuencia (int &ini) {
    for (int i = ini+1; i < f.size(); i++) {
        if (f[i] == invalid) f[i] = f[i-1] + f[i-2];
    }
    for (int i = ini-1; i >= 0; i--) {
        if (f[i] == invalid) f[i] = f[i+2] - f[i+1];
    }
}

void obtenerVal(int &ini) {
    int fin = ini+1, indA, indB;
    long long b,x;

    while(f[fin] == invalid) fin++;
    b = f[fin];
    fin = fin-ini-1;
    ini++;

    indA = fibo[fin-1];
    indB = fibo[fin];
    x = (b - indA*f[ini-1]) / indB;
    f[ini] = x;


    obtenerSecuencia(ini);
}

void unicoValido(int &pos) {
    int ini;
    if (pos-1 > 0) {
        f[pos-1] = f[pos]/2;
        ini = pos;
    }
    else if (pos+1 < f.size()) {
        f[pos+1] = f[pos]+2;
        ini = pos+1;
    }
    obtenerSecuencia(ini);
}

int main() {

    freopen("ladrillos.in","r",stdin);
    freopen("ladrillos.out","w",stdout);
    int n;
    ii validos = {-1,-1};

    cin >> n;

    fibo[0] = fibo[1] = 1;
    for (int i = 2; i <= n; i++)
        fibo[i] = fibo[i-1] + fibo[i-2];

    forn (i,n) {
        string x;
        long long val;
        cin >> x;
        if (x[0] != '*') {
            val = atoi(x.c_str());
            if (validos.snd == -1)
                validos.fst = i;
            validos.snd++;
        }
        else val = invalid;
        f.push_back(val);
    }

    if (validos.snd == -1) {
        forn (i,n) cout << 0 << ' ';
        return 0;
    }
    else if (!validos.snd) {
        unicoValido(validos.fst);
    }
    else {
        forn (i,f.size()) {
            if (f[i] != invalid) {
                obtenerVal(i);
                break;
            }
        }
    }
    for (auto i : f) {
        cout << i << ' ';
    }
    return 0;
}