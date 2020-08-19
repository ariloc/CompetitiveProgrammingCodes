#include "cave.h"
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

const int MAXN = 5000;

void exploreCave(int N) {
    int rta[N], known[N];
    bool mark[N];

    forn (i,N) mark[i] = 0;

    int Na = N;
    forn (i,Na) {
        int high = Na-i;
        int low = 0;

        bool mode = false;
        forn (j,N) if (!mark[j]) rta[j] = mode; // pruebo posición que me abra la puerta que quiero
        int tmpAns = tryCombination(rta);
        if (tmpAns <= i and tmpAns != -1) mode = true;

        while (high-low > 1) {
            int mid = low + (high-low)/2;

            int cnt = 0;
            forn (j,N) {
                if (mark[j]) continue;
                if (cnt < mid) {rta[j] = mode; cnt++;}
                else rta[j] = !mode;
            }

            tmpAns = tryCombination(rta);
            if (tmpAns > i or tmpAns == -1) high = mid; // si funciona, intento abrir menos puertas
            else low = mid; // de lo contrario más
        }

        int cnt = 0, ind = -1;
        forn (j,N) {
            if (mark[j]) continue;
            if (cnt < low) {rta[j] = mode; if (++cnt >= low) ind = j;}
            else rta[j] = !mode;
        }

        int choose = high;
        tmpAns = tryCombination(rta);
        if (tmpAns == -1 or tmpAns > i) choose = low; // será low si se la banca
        else forsn (j,ind+1,N) if (!mark[j]) {ind = j; break;} // de lo contrario high y busco indice sin ocupar próximo

        rta[ind] = mode;
        mark[ind] = true;
        known[ind] = i;
    }

    answer(rta,known);
}
