#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

vector<string> pintapatio(vector<string> mural)
{
    vector<string> rta;
    forn (i,mural[0].size()) {
        if (mural[0][i] == 'R' or mural[0][i] == 'P' or mural[0][i] == 'N' or mural[0][i] == 'M') {
            int j = i+1; ii ext = {1,i+1}, ot = {1,i};
            while(j < mural[0].size() and
                  (mural[0][j] == 'R' or mural[0][j] == 'N' or mural[0][j] == 'P' or mural[0][j] == 'M')) {
                ot.snd++; j++;
            }
            stringstream ss;
            ss << "R ";
            ss << ext.fst; ss << ' ';
            ss << ext.snd; ss << ' ';
            ss << ot.fst; ss << ' ';
            ss << ot.snd;
            string me; ss >> me;
            rta.pb(me);
        }
    }
    forn (i,mural[0].size()) {
        if (mural[0][i] == 'Z' or mural[0][i] == 'V' or mural[0][i] == 'P' or mural[0][i] == 'M') {
            int j = i+1; ii ext = {1,i+1}, ot = {1,i};
            while((j < mural[0].size() and
                  mural[0][j] == 'R' or mural[0][j] == 'Z' or mural[0][j] == 'V' or mural[0][j] == 'P')) {
                ot.snd++; j++;
            }
            stringstream ss;
            ss << "Z ";
            ss << ext.fst; ss << ' ';
            ss << ext.snd; ss << ' ';
            ss << ot.fst; ss << ' ';
            ss << ot.snd;
            string me; ss >> me;
            rta.pb(me);
        }
    }
    forn (i,mural[0].size()) {
        if (mural[0][i] == 'A' or mural[0][i] == 'N' or mural[0][i] == 'V' or mural[0][i] == 'M') {
            int j = i+1; ii ext = {1,i+1}, ot = {1,i};
            while((j < mural[0].size() and
                  mural[0][j] == 'A' or mural[0][j] == 'N' or mural[0][j] == 'V' or mural[0][j] == 'M')) {
                ot.snd++; j++;
            }
            stringstream ss;
            ss << "A ";
            ss << ext.fst; ss << ' ';
            ss << ext.snd; ss << ' ';
            ss << ot.fst; ss << ' ';
            ss << ot.snd;
            string me; ss >> me;
            rta.pb(me);
        }
    }
    return rta;
}

// ***************** EVALUADOR LOCAL *******************

#ifndef EVAL

    #include <iostream>
    #include <vector>
    #include <string>

    using namespace std;

    vector<string> pintapatio(vector<string> mural);

    int main()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int N,M;
        cin >> N >> M;
        vector<string> mural(N);
        for (int i=0;i<N;i++)
            cin >> mural[i];
        vector<string> pasadas = pintapatio(mural);
        cout << pasadas.size() << "\n";
        for (const string &pasada : pasadas)
            cout << pasada << "\n";
        return 0;
    }
#endif
