#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for (int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

const int MAXM = 3e5; // OJO que es grande a proposito
const int INF = 2e9;

struct trieSvNode {
    int bst, t_id, carrA, carrJ;

    bool operator< (const trieSvNode &o) const {
        if (bst != o.bst) return bst < o.bst;
        return t_id < o.t_id;
    }
};

set<trieSvNode> vals;
set<int> interA, interJ;
int bstEach[MAXM], prox_libre = 0;

void update (int myID, set<int> &idsA, set<int> &idsJ, int acc) {
    if (bstEach[myID]) {
        auto it = vals.lower_bound({bstEach[myID],myID,-INF,-INF});
        if (it != vals.end()) vals.erase(it);
    }
    bstEach[myID] = (!idsA.empty() && !idsJ.empty() ? acc : 0);
    vals.insert({bstEach[myID],myID,(idsA.empty() ? -1 : (*idsA.begin())),(idsJ.empty() ? -1 : (*idsJ.begin()))});
}

struct trie {
    map<int,trie> edges;
    set<int> idsA, idsJ;
    int myID = -1;

    void insert (const vi &carr, int id, bool per, int i = 0) {
        if (myID == -1) myID = prox_libre++;

        if (per) idsJ.insert(id);
        else idsA.insert(id);

        update(myID,idsA,idsJ,i);

        if (i < (int)carr.size()) edges[carr[i]].insert(carr,id,per,i+1);
    }

    void erase (const vi &carr, int id, bool per, int i = 0) {
        // considero que hay erase cuando existe

        if (per) idsJ.erase(id);
        else idsA.erase(id);

        update(myID,idsA,idsJ,i);

        if (i < (int)carr.size()) edges[carr[i]].erase(carr,id,per,i+1);
    }
};

int myN = 0;
trie T;

void inicializar(int N) {
    myN = N;
    forn(i,MAXM) bstEach[i] = -1;
}

int actualizar(vector<int> &car, int num, int per, int op, vector<int> &elegidas) {
    if (op) T.insert(car,num,per);
    else T.erase(car,num,per);

    if (per) {
        if (op) interJ.insert(num);
        else interJ.erase(num);
    }
    else {
        if (op) interA.insert(num);
        else interA.erase(num);
    }

    if (interA.empty() || interJ.empty()) {elegidas = {-1,-1}; return -1;}
    // en teoría, acá no está vacío
    auto aux = *vals.rbegin();
    if (!aux.bst) elegidas = {*interA.begin(), *interJ.begin()};
    else elegidas = {aux.carrA, aux.carrJ};
    return aux.bst;
}
