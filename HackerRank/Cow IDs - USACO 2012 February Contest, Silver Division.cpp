// https://www.hackerrank.com/contests/simulacro-3-oia-2020/challenges/problem-2-cow-ids/problem
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

string cow_id(int N, int K) {
    set<int> posic;
    forn(i,K) posic.insert(i);
    forsn(i,1,N) {
        for (auto j = posic.begin(); j != posic.end();) {
            if (j == prev(posic.end()) || (*(next(j))) != ((*j)+1)) {
                int v = (*j); v++; posic.erase(j); posic.insert(v);
                break;
            }
            j = next(j); posic.erase(prev(j));
        }
        int cnt = 0;
        while ((int)posic.size() < K)
            posic.insert(cnt++);
    }
    string s; s.resize(*(posic.rbegin())+1,'0');
    for (auto &i : posic) s[i] = '1';
    reverse(all(s));
    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    cout << cow_id(N, K) << endl;

    return 0;
}
