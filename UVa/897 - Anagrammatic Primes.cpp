#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

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

const int MAXN = 1e7+5;

bitset<MAXN> done,anagram;
int anagramN[MAXN];

int main() {
    FAST_IO;

    for (int i = 4; i < MAXN; i+=2) done[i] = true;
    for (int i = 3; i < MAXN; i+=2)
        if (!done[i])
            for (int j = i+i; j < MAXN; j+=i)
                done[j] = true;

    forn(i,MAXN) if(!done[i]) {
        bool posib = true;
        stringstream ss; ss << i;
        string num; ss >> num; sort(all(num));
        do {
            int x = 0;
            forn(j,num.size()) {x *= 10; x += num[j]-'0';}
            if (done[x]) {posib = false; break;}
        } while(next_permutation(all(num)));
        if (posib) anagram[i] = true;
    }

    int act = 0;
    dforn(i,MAXN) {
        anagramN[i] = act;
        if (anagram[i]) act = i;
        if (i == 1 or i == 10 or i == 100 or i == 1000 or i == 10000 or i == 100000 or i == 1000000 or i == 10000000) act = 0;
    }

    int x;
    while (cin >> x) {
        if (!x) break;
        cout << anagramN[x] << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
 
