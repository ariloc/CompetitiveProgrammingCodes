#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define pb push_back
#define fst first
#define snd second
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

int f (int x) {
    return x >= 10 ? 0 : x;
}

int envido(int numero1, string &palo1, int numero2, string &palo2, int numero3, string &palo3) {
    int maxi = max(f(numero1), max(f(numero2), f(numero3)));
    if (palo1 == palo2) {
        maxi = max(maxi, f(numero1) + f(numero2) + 20);
    }
    if (palo1 == palo3) {
        maxi = max(maxi, f(numero1) + f(numero3) + 20);
    }
    if (palo2 == palo3) {
        maxi = max(maxi, f(numero2) + f(numero3) + 20);
    }
    return maxi;
}
