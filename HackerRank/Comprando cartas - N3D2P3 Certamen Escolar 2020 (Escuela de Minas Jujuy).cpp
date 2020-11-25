// https://www.hackerrank.com/contests/simulacro-4-n3-oia-2020/challenges/comprando-cartas-joacru/problem
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

string ot;

struct trie {
    map<char,pair<int,trie>> edges;

    bool nd = false;
    //string meS;

    void insert(const string &s, int i = 0) {
        if ((int)s.size() == i) nd = true;
        else {
            edges[s[i]].fst++;
            edges[s[i]].snd.insert(s,i+1);
        }
    }


    void look (int P) {
        for (auto it = edges.rbegin(); it != edges.rend(); it++) {
                //cerr << it->snd.fst << ' ' << it->fst << endl;
            if (it->snd.fst <= P) {int x = it->snd.fst; P -= x;}
            else {
                ot += it->fst;
                it->snd.snd.look(P);
                return;
            }
        }
    }
};

trie T;

void iniciar(int N, int K){

}

int cnt = 0;

string dia(string A, int P){
    ot.clear();
    T.insert(A);
    //cerr << cnt++ << "!!!" << endl;
    T.look(P);
    return ot;
}

int main(){
     cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N, K;
    cin>>N>>K;
    iniciar(N, K);
    for(int i = 0; i < N; i++){
        string A;
        int P;
        cin>>A>>P;
        cout<<dia(A, P)<<"\n";
    }
    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
