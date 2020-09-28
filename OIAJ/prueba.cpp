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

const int INF = 3e6+2;

int prueba(string palabra) {
    int val = palabra.size()-1;
    int bestC = INF;

    forn(i,palabra.size()) {
        int j = palabra.size()-1, k = i;
        bool posib = false;

        while (palabra[j] == palabra[k]) {
            j--; k++;
            if (j < 0 or k >= palabra.size()) {posib = true; break;}
        }
        if (posib) {bestC = i; break;}
    }

    dforn(i,palabra.size()) {
        int j = 0, k = i;
        bool posib = false;

        while (palabra[j] == palabra[k]) {
            j++; k--;
            if (j >= palabra.size() or k < 0) {posib = true; break;}
        }
        if (posib) {bestC = min(bestC,(int)palabra.size()-i-1); break;}
    }

    return bestC;
}
