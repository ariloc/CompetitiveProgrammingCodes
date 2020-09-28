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

const int MAXN = 6e4+5;

int KMP[MAXN];

int KMPcompute (string s) { // saco los bordes, prefijos que son sufijos
    int N = s.size();
    forsn(i,1,N) {
        int j = KMP[i-1];
        while (j and s[i] != s[j])
            j = KMP[j-1];
        if (s[i] == s[j]) j++;
        KMP[i] = j;
    }
    return KMP[N-1]; // coincidencia del prefijo en el sufijo
}

int  prueba( string palabra )
{
    string tmp = palabra;
    reverse(all(palabra));
    return (int)palabra.size() - max(KMPcompute(palabra+'#'+tmp), KMPcompute(tmp+'#'+palabra)); // dada la mayor coincidencia, le esto lo que queda para completar
}

const static auto ___ = []() {
    FAST_IO; return 0;
}();
