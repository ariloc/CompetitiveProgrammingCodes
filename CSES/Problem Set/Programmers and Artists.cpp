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

int const MAXN = 2e5+5;
int const INF = 2e9;

struct person {
    int p,a,id;
};

person per[MAXN];
person byProg[MAXN], byArt[MAXN];
bitset<MAXN> takenprog, takenart;

int difToProg (person x) { return x.p-x.a; }
int difToArt (person x) { return x.a-x.p; }

auto becomeProg = [](const person &lhs, const person &rhs) {
    int a = difToProg(lhs), b = difToProg(rhs);
    if (a != b) return a < b;
    return lhs.id < rhs.id;
};

auto becomeArt = [](const person &lhs, const person &rhs) {
    int a = difToArt(lhs), b = difToArt(rhs);
    if (a != b) return a < b;
    return lhs.id < rhs.id;
};

auto cmpProg = [](const person &lhs, const person &rhs) {
    return lhs.p < rhs.p;
};

auto cmpArt = [](const person &lhs, const person &rhs) {
    return lhs.a < rhs.a;
};

priority_queue<person,vector<person>,decltype(becomeArt)> curProg(becomeArt);
set<person,decltype(becomeProg)> curArt(becomeProg);
priority_queue<person,vector<person>,decltype(cmpProg)> unchosen(cmpProg);
set<person,decltype(cmpArt)> allArt(cmpArt);

int main() {
    FAST_IO;

    int n,A,B; cin >> A >> B >> n;
    forn(i,n) cin >> per[i].p >> per[i].a, per[i].id = i;

    forn(i,n) byProg[i] = byArt[i] = per[i];

    sort(byProg,byProg+n,[](const person &lhs, const person &rhs) {
        return lhs.p > rhs.p;
    });
    sort(byArt,byArt+n,[](const person &lhs, const person &rhs){
        return lhs.a > rhs.a;
    });
    
    ll sum = 0;
    
    forn(i,A) sum += byProg[i].p, takenprog[byProg[i].id] = true, curProg.push(byProg[i]);
    
    int sel = 0;
    forn(i,n) {
        if (sel == B) break;
        if (!takenprog[byArt[i].id]) {
            takenart[byArt[i].id] = true;
            sum += byArt[i].a;
            curArt.insert(byArt[i]);
            allArt.insert(byArt[i]);
            ++sel;
        }
    }

    forn(i,n) if (!takenart[i] && !takenprog[i]) unchosen.push(per[i]);

    if (B > 0 && A > 0) {
        while (true) {
            auto a = curProg.top(), b = *curArt.rbegin();
            ll sa = difToArt(a), sb = difToProg(b);
            ll sc = (!unchosen.empty() ? unchosen.top().p-(*allArt.begin()).a : -INF);

            if (sa + max(sb,sc) <= 0) break;

            curProg.pop();
            sum -= a.p;

            if (sc > sb) {
                auto c = unchosen.top(); unchosen.pop();

                auto olda = *allArt.begin();
                curArt.erase(olda);
                allArt.erase(olda);
                sum -= olda.a;
                unchosen.push(olda);

                curArt.insert(a);
                allArt.insert(a);
                sum += a.a;
                curProg.push(c);
                sum += c.p;
            }
            else {
                curArt.erase(b);
                allArt.erase(b);
                sum -= b.a;

                curArt.insert(a);
                allArt.insert(a);
                sum += a.a;
                curProg.push(b);
                sum += b.p;
            }
        }
    }

    cout << sum << '\n';

    return 0;
}
