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
typedef vector<ll> vll;

const int MAXN = 205;
const int MAXA = 26;
const ll INF = 1e18;
const ll NEUT = -INF;

struct entry {
    string s;
    ll c;

    bool operator< (const entry &o) const {
        return s < o.s;
    }
};

struct mat {
    vector<vll> M;
    mat() {};
    mat(int n, int m) : M(n,vll(m)) {};
    vll &operator[] (int x) {return M[x];}
    const vll &operator[] (int x) const {return M[x];}
    int size() const {return (int)M.size();}
};

mat operator* (mat A, mat B) {
    int n = A.size(), m = (int)B[0].size(), o = (int)A[0].size();
    mat R(n,m);
    forn(i,R.size()) forn(j,R[0].size()) R[i][j] = NEUT;

    forn(i,n) forn(j,m) forn(k,o)
        R[i][j] = max(R[i][j], A[i][k] + B[k][j]);
    return R;
}

mat matExp (mat A, ll k) {
    mat R = mat(A.size(),(int)A[0].size());
    bool blank = true;
    while (k) {
        if (k&1) {
            if (blank) blank = false, R = A;
            else R = (R*A);
        }
        A = (A*A); k >>= 1;
    }
    return R;
}


int S[MAXN][MAXA], cntTrie = 1;
ll dp[MAXN][MAXN];
entry dict[MAXN];
mat D;

void insert (const string &s) {
    int act = 0;
    forn(i,s.size()) {
        if (!S[act][s[i]-'a']) {
            D[act][cntTrie] = 0;
            S[act][s[i]-'a'] = cntTrie++;
        }
        act = S[act][s[i]-'a'];
    }
}

int search (const string &s) {
    int act = 0;
    forn(i,s.size()) {
        if (!S[act][s[i]-'a']) return 0;
        act = S[act][s[i]-'a'];
    }
    return act;
}

void add_edges (int ind) {
    entry x = dict[ind];
    string s = x.s;
    int src_ind = search(s);
    //cerr << src_ind << ' ' << s << endl;

    forn(i,MAXA) if (S[0][i]) {
        //cerr << s << ' ' << src_ind << ' ' << S[0][i] << ' ' << dp[ind][(int)s.size()-1] << endl;
        D[src_ind][S[0][i]] = dp[ind][(int)s.size()-1]; // si no hay solapamiento, también puedo
    }

    string aux1, aux2;
    dforsn(i,1,s.size()) {
        aux1.pb(s[i]);
        aux2 = aux1;

        reverse(all(aux2));
        int dest_ind = search(aux2);
        //cerr << aux2 << ' ' << dest_ind << endl;

        if (dest_ind)
            forn(j,MAXA) if (S[dest_ind][j]) {
                D[src_ind][S[dest_ind][j]] = dp[ind][(int)s.size() - (int)aux2.size() - 1]; // negativo, porque buscaré el "más corto"
                //cerr << src_ind << ' ' << S[dest_ind][j] << ' ' << D[src_ind][S[dest_ind][j]] << ' ' << (int)s.size() - (int)aux2.size() - 1 << ' ' << endl;
            }
    }
}


vi KMPcompute (string s) {
    int N = (int)s.size();
    vi KMP(N,0);
    forsn(i,1,N) {
        int j = KMP[i-1];
        while (j and s[i] != s[j])
            j = KMP[j-1];
        if (s[i] == s[j]) j++;
        KMP[i] = j;
    }
    return KMP;
}

void solveSubstr (int i, int j) { 
    string x = dict[j].s, s = dict[i].s;
    if ((int)x.size() > (int)s.size()) return;
    vi aux = KMPcompute(x+'$'+s);

    forsn(ind,2*(int)x.size(),aux.size()) if (aux[ind] == (int)x.size())
        dp[i][ind-2*(int)x.size()] += dict[j].c; /// !!!!

}

int main() {
    FAST_IO;

    D = mat(MAXN,MAXN);
    forn(i,MAXN) forn(j,MAXN) D[i][j] = NEUT;

    ll n,l; cin >> n >> l;
    forn(i,n) cin >> dict[i].c;
    forn(i,n) cin >> dict[i].s;

    // saco los iguales
    sort(dict,dict+n);
    int ind = 0;
    forsn(i,1,n)
        if (dict[ind].s == dict[i].s)
            dict[ind].c += dict[i].c;
        else dict[++ind] = dict[i];

    n = ind+1;

    //forn(i,n) cerr << dict[i].s << ' ' << dict[i].c << endl;

    forn(i,n) forn(j,n) if (i != j) solveSubstr(i,j);
    forn(i,n) dp[i][0] += dict[i].c;
    forn(i,n) forsn(j,1,dict[i].s.size()) dp[i][j] += dp[i][j-1]; // sumas en prefijos
    //forn(i,n) forn(j,dict[i].s.size()) cerr << dp[i][j] << " " << dict[i].s << " !!!" << endl;

    forn(i,n) insert(dict[i].s);
    forn(i,n) add_edges(i);

    //forn(i,cntTrie) {forn(j,cntTrie) cerr << (D[i][j] == INF ? -1 : D[i][j]) << ' '; cerr << endl;}

    mat aux_mat = matExp(D,l);
    /*mat aux_mat = D;
    forn(i,l) aux_mat = (aux_mat * D);*/

    ll maxi = 0;
    //forn(i,cntTrie) {forn(j,cntTrie) cerr << (D[i][j] == -INF ? -1 : D[i][j])  << ' '; cerr << endl;}
    forn(i,MAXA) forn(j,aux_mat[0].size())
        maxi = max(maxi,aux_mat[S[0][i]][j]);

    cout << maxi;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!