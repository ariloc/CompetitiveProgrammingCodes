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

string s; int n,p;
bool posib = false;

void recur (int i) {
    forsn(j,s[i]-'a'+1,p) {
        if (i && ((s[i-1]-'a') == j)) continue;
        if (i > 1 && (((s[i-2])-'a') == j)) continue;
        posib = true; s[i] = (char)(j+'a'); break;
    }
    if (posib || !i) return;
    recur(i-1);
    forn(j,p) {
        if (i && ((s[i-1]-'a') == j)) continue;
        if (i > 1 && (((s[i-2])-'a') == j)) continue;
        s[i] = (char)(j+'a'); break;
    }
}

int main() {
    FAST_IO;

    cin >> n >> p;
    cin >> s;

    recur(s.size()-1);
    forsn(i,2,s.size()) if (s[i-1] == s[i] || s[i-2] == s[i]) {posib = false; break;}
    if ((int)s.size() > 1 && s[1] == s[0]) posib = false;

    if (!posib) cout << "NO\n";
    else cout << s;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
