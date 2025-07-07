#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 3005;
int const DUMMY = 3001;
int const MOD = 1e9+7;

vi G[MAXN];
int out[MAXN];
bitset<MAXN> passed, done, scan, active;
int dpPosib[MAXN];
int dpLca[MAXN][MAXN];
int lengths[MAXN];
vi P;

int fact[MAXN], inv[MAXN], factInv[MAXN];

void precomp() {
    fact[0] = 1;
    forsn(i,1,MAXN) fact[i] = (fact[i-1]*(ll)i)%MOD;

    inv[1] = 1;
    forsn(i,2,MAXN) inv[i] = MOD - ((MOD/(ll)i)*(ll)inv[MOD%i])%MOD;

    factInv[0] = 1;
    forsn(i,1,MAXN) factInv[i] = (factInv[i-1]*(ll)inv[i])%MOD;
}

int nCr (int n, int r) {
    if (r > n) return 0;
    return ((ll)((fact[n]*(ll)factInv[r])%MOD)*factInv[n-r])%MOD;
}

int dfs(int st) {
    done[st] = true;
    int acc = 1;
    for (auto &i : G[st])
        if (!done[i])
            acc += dfs(i);
    return lengths[st] = acc;
}

bool detect_cycle(int st) {
    active[st] = true;
    for (auto &i : G[st])
        if (!scan[i] && (active[i] || detect_cycle(i)))
            return true;
    scan[st] = true;
    active[st] = false;
    return false;
}

int calc_tree(int st) {
    if (G[st].empty()) return dpPosib[st] = 1;
    if (dpPosib[st] != -1) return dpPosib[st];
    int acc = 1, cnt = 0;
    for (auto &i : G[st]) {
        int cur = calc_tree(i);
        acc = (((acc * (ll)cur)%MOD) * (ll)nCr((cnt+1) + lengths[i] - 1, lengths[i]))%MOD;
        cnt += lengths[i];
    }
    return dpPosib[st] = acc;
}

int go_lca(int st, int branch, int lca) {
    if (st == lca || st == DUMMY) return branch;
    int acc = 1, cnt = 0;
    for (auto &i : G[st]) {
        if (i == branch) continue;
        int cur = calc_tree(i);
        acc = (((acc * (ll)cur)%MOD) * (ll)nCr((cnt+1) + lengths[i] - 1, lengths[i]))%MOD;
        cnt += lengths[i];
    }
    int len = lengths[st]-1;
    forn(pos,len) {
        forsn(j,max(0,pos-cnt),pos+1) {
            // dp ... * nCr((j+1) + (pos-j) - 1, pos-j)
            int aux1 = (dpLca[branch][j] * (ll)nCr(pos, pos-j))%MOD;
            // ... * nCr(((lengths[branch]+1)-(j+1)) + (cnt-(pos-j)) - 1, cnt-(pos-j))
            int aux2 = (aux1 * (ll)nCr(lengths[branch] - pos + cnt - 1, cnt-pos+j))%MOD;
            dpLca[st][pos] = (dpLca[st][pos] + ((aux2 * (ll)acc)%MOD))%MOD;
        }
    }
    return go_lca(P[st], st, lca);
}

int go(int st, int lca) {
    int auxi = calc_tree(st);
    dpLca[st][lengths[st]-1] = auxi;
    return go_lca(P[st], st, lca);
}

int chat(int A, int B, vector<int> &C) {
    int N = (int)C.size();
    precomp();
    forn(i,N) C[i] = C[i] == -1 ? DUMMY : C[i];
    P = C;
    forn(i,N) dpPosib[i] = -1;
    dpPosib[DUMMY] = -1;
    // dpLca todos ceros...


    forn(i,N) {
        if (P[i] == DUMMY) continue;
        out[P[i]]++;
        G[P[i]].pb(i);
    }

    G[A].pb(B), out[A]++;
    forn(i,N)
        if (!scan[i] && detect_cycle(i))
            return 0;

    if (P[B] != DUMMY) {
        G[A].pop_back(); // Remove the double edge from tree for algorithm, but node still counts as "non independent"
        forn(i,N)
            if (out[i] > 0 && P[i] == DUMMY)
                G[DUMMY].pb(i);

        // Calc lengths
        dfs(DUMMY);

        int cur = B;
        while (cur != DUMMY)
            passed[cur] = true, cur = P[cur];
        int lca = A;
        while (lca != DUMMY && !passed[lca])
            lca = P[lca];

        if (lca != A && lca != B) {
            int lastA = go(A, lca);
            int lastB = go(B, lca);

            int combAB = 0;
            int lenA = lengths[lastA], lenB = lengths[lastB];
            int lenAB = lenA + lenB;
            vi dpAcc(lenB,0); // number of combinations where B is in the ith or less position
            forn(posB,lenB) dpAcc[posB] = dpLca[lastB][posB];
            forsn(i,1,lenB) dpAcc[i] = (dpAcc[i-1] + dpAcc[i])%MOD;
            forn(posA, lenA) {
                forsn(j,1,lenB+1) { // Assuming we put j elements right of A
                    int combs1 = nCr((posA+1) + j - 1, j); // Number of ways to put j elements right of A with repetition
                    int combs2 = nCr(((lenA+1)-(posA+1)) + (lenB-j) - 1, lenB-j); // Ways to put lenB-j elems left of A
                    int combs = (combs1 * (ll)combs2)%MOD;
                    combAB = (combAB + (dpLca[lastA][posA] * (ll)((combs * (ll)dpAcc[j-1])%MOD))%MOD)%MOD;
                }
            }
            
            int acc = 1, cnt = 0;
            for (auto &i : G[lca]) {
                if (i == lastA || i == lastB) continue;
                int cur = calc_tree(i);
                acc = (((acc * (ll)cur)%MOD) * (ll)nCr((cnt+1) + lengths[i] - 1, lengths[i]))%MOD;
                cnt += lengths[i];
            }

            // Combinamos ambos resultados
            acc = (((acc * (ll)combAB)%MOD) * (ll)nCr((cnt+1) + lenAB - 1, lenAB))%MOD;
            dpPosib[lca] = acc;
        }
        else { // Igual que normal, acá no hacer nada
        }
    }
    else {
        forn(i,N)
            if (out[i] > 0 && P[i] == DUMMY && i != B)
                G[DUMMY].pb(i);
        // Calc lengths
        dfs(DUMMY);
    }

    // Combinamos árboles y ponemos los sueltos
    int combTrees = calc_tree(DUMMY);
    int indep = N - (lengths[DUMMY]-1); // ojo lengths[DUMMY] tiene uno de más que cuenta el mismo dummy
    combTrees = (combTrees * (ll)nCr(lengths[DUMMY] + indep - 1, indep))%MOD;
    combTrees = (combTrees * (ll)fact[indep])%MOD;

    return combTrees;
}
