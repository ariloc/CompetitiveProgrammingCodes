#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define fst first
#define snd second

using namespace std;
typedef vector<string> vs;
typedef vector<int> vi;
typedef pair<int,int> ii;

const int MAXN = 100000;
const int X[] = {0,-1,0,1};
const int Y[] = {1,0,-1,0};

struct sorter {
    int num;
    char d;
    bool operator<(const sorter &a) const{
        return a.num > num;
    }
};

int prox; // indice disponible
int sig[MAXN][26]; // posibles letras minúsculas
int prefijos[MAXN][26];
bool final[MAXN]; //lugares donde terminan palabras

void agregar(const string &s, int raiz = 0){
    int actual = raiz;
    forn(i, s.size()){
        int letra = s[i] - 'a';
        if(sig[actual][letra] == -1)
            sig[actual][letra] = prox++;
        actual = sig[actual][letra];
        prefijos[actual][letra]++;
    }
    final[actual] = true;
}

int buscar(const string &s, int raiz = 0){
    int actual = raiz;
    forn(i, s.size()){
        int letra = s[i] - 'a';
        if(sig[actual][letra] == -1)
            return -1;
        actual = sig[actual][letra];
    }
    if(final[actual]) return 1;
    return 0;
}

vs rapi;
bitset<26> yes;
set<string> prim[26];
map<string, vi> refers;
char dir[] = {'S','O','N','E'};
vector<sorter> resultado;

void way(int &direct, int &posX, int &posY);
bool valido(int &x, int &y);

int main() {
    memset(sig, -1, sizeof(sig));
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int D,P;
    freopen("rapigrama.in","r",stdin);
    freopen("rapigrama.out","w",stdout);

    cin >> D >> P;

    forn (i,D) {
        string x;
        cin >> x;
        rapi.push_back(x);
    }
    forn (i,P) {
        string x, aux;
        cin >> x;
        aux+=x[0]; aux+=x[1];
        agregar(x);
        prim[x[0]-'a'].insert(aux);
        refers[x].push_back(i+1);
        yes[x[0]-'a'] = true;
    }
    forn (m,rapi.size()) {
        forn (n,rapi[0].size()) {
            char j = rapi[m][n];
            if (yes[j-'a']) {
                forn (i,4) {
                    string aux;
                    aux += j;
                    int tendX = X[i];
                    int tendY = Y[i];
                    int x = n+tendX;
                    int y = m+tendY;
                    if (not valido(x,y)) continue;
                    aux += rapi[y][x];
                    if (prim[j-'a'].count(aux)) {
                        while (true) {
                            int t = buscar(aux);
                            if (t == -1) break;
                            if (t > 0)
                                while (!refers[aux].empty()) {
                                    resultado.push_back({refers[aux].back(),dir[i]});
                                    refers[aux].pop_back();
                                }
                            way(i,x,y);
                            if (not valido(x,y)) break;
                            aux += rapi[y][x];
                        }
                    }
                }
            }
        }
    }
    sort (resultado.begin(),resultado.end());
    for (auto &i : resultado) {
        cout << i.num << ' ' << i.d << '\n';
    }
    return 0;
}

void way(int &direct, int &posX, int &posY) {
    switch (direct) {
        case 0 : posY++; break;
        case 1 : posX--; break;
        case 2 : posY--; break;
        case 3 : posX++; break;
    }
}

bool valido (int &x, int &y) {
    if (x < 0 or y < 0) return false;
    if (y >= rapi.size() or x >= rapi[0].size()) return false;
    return true;
}
