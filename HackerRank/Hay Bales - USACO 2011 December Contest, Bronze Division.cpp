// https://www.hackerrank.com/contests/simulacro-2-oia-2020/challenges/problem-0-hay-bales/problem
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

int hayBales(vector <int> v) {
    int s = 0, rta = 0;
    for (auto &i : v) s += i;
    int prom = s/(int)v.size();
    for (auto &i : v) rta += abs(i-prom);
    return rta/2;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector <int> v(N);
    for(int i=0; i<N; i++)
        cin >> v[i];

    cout << hayBales(v) << endl;

    return 0;
}
