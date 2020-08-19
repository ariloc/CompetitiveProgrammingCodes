#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= s; i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

const int MAXN = 45000015;
const int LOGMAXN = log2(MAXN)+1;
const int MAXP = 10;
const ll MOD = 1e9+7;

int q,m;
ll FT[MAXN];

struct trie {
    map<char,trie> edges;
    ll pob = 0;

    ll insert(const ll &val, const string &s, int i = 0) {
        if (i == (int)s.size()) {ll aux = pob; pob = val; return aux;}
        else {
            ll myVal = edges[s[i]].insert(val,s,i+1);
            pob -= myVal;
            pob += val;
            //cerr << i << ' ' << pob << ' ' << s << ' ' << "OK" << "!!!" << endl;
            return myVal;
        }
    }

    ll toRest (const string &a, const bool &mode, const int &j, int i = 0) {
        if (i == a.size()) return 0;
        if (i >= j) {
            ll sum = 0;
            //cerr << edges.size () << "!!!!" << endl;
            for (auto &o : edges) {
                if (mode and o.fst > a[i]) {sum += o.snd.pob; /*cerr << a << ' ' << a[i] << ' ' << o.snd.pob << ' ' << mode << ' ' << i << ' ' << o.fst << ' ' << pob << endl;*/}
                else if (!mode and o.fst < a[i]) {sum += o.snd.pob; /*cerr << a << ' ' << a[i] << ' ' <<  o.snd.pob << ' ' << mode << ' ' << i << ' ' << o.fst << ' ' << pob << endl;*/}
            }
            //cerr << sum << "OK" << endl;
            return sum+edges[a[i]].toRest(a,mode,j,i+1);
        }
        return edges[a[i]].toRest(a,mode,j,i+1);
    }

    ll dif (const string &a, const string &b, const int &j, int i = 0) {
        if (i == j) return pob-toRest(a,false,j,i)-toRest(b,true,j,i);
        //cerr << a[i] << endl;
        return edges[a[i]].dif(a,b,j,i+1);
    }

};

trie T;

/*ll getFT (int p) {
    ll r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

void setFT (int p, ll v) {
    for (int i = p; i < MAXN; i += i & -i)
        FT[i] += v;
}

int invertFT (ll p) {
    int x = 0;
    for (int d = 1<<(LOGMAXN-1); d; d>>=1) {
        if (FT[x|d] < p) {
            x |= d;
            p -= FT[x];
        }
    }
    return x+1;
}*/

void inicializar(int Q,int M)
{
    q = Q; m = M;
}

long long pueblo(string A, long long PA)
{
    return T.insert(PA,A);
}

long long consulta(string A, string B)
{
    forn (i,A.size()) if (A[i] != B[i]) return T.dif(A,B,i);
}

// ***************** EVALUADOR LOCAL *******************

#ifndef EVAL
    #include <iostream>

    using namespace std;

    void inicializar(int Q,int M);
    long long pueblo(string A, long long PA);
    long long consulta(string A, string B);

    int main()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int localQ, localM;
        cin >> localQ >> localM;
        inicializar(localQ, localM);
        for (int i=0;i<localQ;i++)
        {
            int t;
            cin >> t;
            if (t == 1)
            {
                string A;
                cin >> A;
                long long PA;
                cin >> PA;
                cout << pueblo(A,PA) << "\n";
            }
            else if (t == 2)
            {
                string A,B;
                cin >> A >> B;
                cout << consulta(A,B) << "\n";
            }
            else
            {
                cout << "OPERACION INVALIDA!" << endl;
                return 1;
            }
        }
        return 0;
    }
#endif
