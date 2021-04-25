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
 
const int MAXN = 102;
const int INF = 1e9+5;

set<vi> REFER;
int arr[MAXN];

void recur (vi mArr) {
    if (REFER.count(mArr)) return;
    REFER.insert(mArr);
    vi aux = mArr;
    swap(aux[0],aux[2]);
    swap(aux[1],aux[3]);
    recur(aux);

    aux = mArr;
    swap(aux[0],aux[3]);
    swap(aux[1],aux[4]);
    recur(aux);

    aux = mArr;
    swap(aux[1],aux[3]);
    swap(aux[2],aux[4]);
    recur(aux);
}

void genPosib() {
    recur({1,2,3,4,5});
}
 
int main() {
    FAST_IO;

    genPosib();
 
    int t; cin >> t;
    forn(o,t) {
        int n; cin >> n;
        forn(i,n) cin >> arr[i];
 
        bool isSorted = true;
        forsn(i,1,n) if (arr[i] < arr[i-1]) isSorted = false;
 
        if (!isSorted) {
            if (n > 4) {
                int toSort = 1, ini = 0;
                bool posib = true;
 
                while (ini < n-5 && posib) { // hasta que sea justo 5
                    int pos = -1;
                    forn(i,n) if (arr[i] == toSort) pos = i;
 
                    if (pos == n-1) {
                        if (pos-3 < ini) posib = false;
                        else {
                            swap(arr[pos],arr[pos-2]);
                            swap(arr[pos-1],arr[pos-3]);
                            pos -= 2;
                        }
                    }
 
                    if (pos == ini+1) {
                        if (pos+3 >= n) posib = false;
                        else {
                            swap(arr[pos],arr[pos+2]);
                            swap(arr[pos+1],arr[pos+3]);
                            pos += 2;
                        }
                    }
 
                    if (pos == ini+1 || pos == n-1) posib = false;
                    else {
                        swap(arr[ini],arr[pos]);
                        swap(arr[ini+1],arr[pos+1]);
                    }
 
                    ini++, toSort++;
                }
 
                if (!posib) cout << "NO\n";
                else {
                    vi aux;
                    forsn(i,n-5,n) aux.pb(arr[i]);

                    int mini = INF;
                    forn(i,aux.size()) mini = min(mini,aux[i]);
                    forn(i,aux.size()) aux[i] -= (mini-1); // así queda el más chico, 1

                    bool match = false;
                    for (auto &i : REFER) if (i == aux) match = true;
                    cout << (match ? "YES" : "NO") << '\n';
                }
            }
            else if (n == 4) { // caso 4 es simple swap
                swap(arr[0],arr[2]);
                swap(arr[1],arr[3]);

                isSorted = true;
                forsn(i,1,n) if (arr[i] < arr[i-1]) isSorted = false;

                cout << (isSorted ? "YES" : "NO") << '\n';
            }
            else cout << "NO\n";
        }
        else cout << "YES\n";
    }
 
    return 0;
}
 
/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!