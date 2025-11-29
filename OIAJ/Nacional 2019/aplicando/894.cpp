#include <iostream>
#include <vector>
#include <sstream>
#include <string>

#define forn(i,n) for(int i = 0; i < int(n); i++)

using namespace std;

vector<int> aplicando(string &n, int &d, vector<int> &a, vector<int> &b) {
    vector<int> r;
    forn (i, a.size()) {
        string x = n;
        stringstream c;
        long long num;
        int A = a[i];
        int B = b[i];
        x = x.substr(A-1,B-A+1);
        c << x;
        c >> num;
        r.push_back(num%d);
    }

    return r;
}

#ifndef EVAL
    #include <iostream>

    int main() {
        //freopen("aplicando2.in","r",stdin);

        string n;
        int d;
        cin >> n >> d;
        int q;
        cin >> q;
        vector<int> a, b;
        a.reserve(q);
        b.reserve(q);
        for (int i=0;i<q;i++) {
            int aValue, bValue;
            cin >> aValue >> bValue;
            a.push_back(aValue);
            b.push_back(bValue);
        }
        vector<int> ret = aplicando(n, d, a, b);
        for (int x : ret)
            cout << x << endl;
    }
#endif
