#include<bits/stdc++.h>
#include<cassert>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

const vi REYX = {0,1,0,-1,1,-1,1,-1};
const vi REYY  = {1,0,-1,0,1,-1,-1,1};

const vi TORX = {0,1,0,-1};
const vi TORY = {1,0,-1,0};

const vi ALFX = {1,-1,-1,1};
const vi ALFY = {-1,1,-1,1};

const vi DAMX = REYX;
const vi DAMY = REYY;

const vi CABX = {2,1,-1,-2,-2,-1,1,2};
const vi CABY = {1,2,2,1,-1,-2,-2,-1};

int const MAXN = 8;

struct mov {
    vi movx,movy;
    bool dist;
};

const map<string, mov> MOV = {
    {"rey", {REYX,REYY,false}},
    {"torre", {TORX,TORY,true}},
    {"alfil", {ALFX,ALFY,true}},
    {"dama", {DAMX,DAMY,true}},
    {"caballo", {CABX,CABY,false}}
};

bitset<MAXN> done[MAXN];

int tablero(string &pieza, string &salida, string &llegada, vector<string> &escaques) {
    int ix = salida[0]-'a', iy = salida[1]-'1';
    int jx = llegada[0]-'a', jy = llegada[1]-'1';

    reverse(all(escaques));

    mov movs = MOV.at(pieza);

    queue<pair<ii,int>> Q;
    Q.push({{ix,iy},0});
    done[iy][ix] = true;
    while(!Q.empty()) {
        auto e = Q.front(); Q.pop();
                
        if (e.fst.fst == jx && e.fst.snd == jy) {
            return e.snd;
        }

        forn(k,movs.movx.size()) {
            int lim = movs.dist ? 8 : 1;
            forsn(l,1,lim+1) {
                int tx = e.fst.fst + l * movs.movx[k], ty = e.fst.snd + l * movs.movy[k];
                if (tx < 0 || ty < 0 || tx >= 8 || ty >= 8) break;
                if (escaques[ty][tx] == 'X') break;
                if (done[ty][tx]) continue;

                done[ty][tx] = true;
                Q.push({{tx,ty},e.snd+1});
            }
        }
    }

    return -1;
}
