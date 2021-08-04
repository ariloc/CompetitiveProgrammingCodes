#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= s; i++)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

int main() {
    FAST_IO;

    string a,b; cin >> a >> b;
    if (a == b) cout << "Empate";
    else if ((a == "Piedra" and b != "Papel") or (a == "Papel" and b != "Tijera") or
             (a == "Tijera" and b != "Piedra")) cout << "Ana";
    else cout << "Bartolo";

    return 0;
}