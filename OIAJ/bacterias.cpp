#include <bits/stdc++.h>

#define forn(i,n) for(ll i = 0; i < ll(n); i++)
#define forsn(i,s,n) for(ll i = ll(s); i < ll(n); i++)
#define dforn(i,n) for (ll i = ll(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = ll(n)-1; i >= ll(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

int medir(const vector<int> &temperaturas); // Devuelve 1 si las bacterias sobreviven, 0 sino.

vi temp;
set<int> diferentes;
int cnt = 0;

void binSrch (int &A, int &B, int i) {
    int high = B;
    int low = A;
    bool lastState = false;
    cnt++;
    diferentes.insert(i);

    while (high - low > 1) {
        int mid = low+(high-low)/2;
        temp[i] = mid;
        lastState = medir(temp);
        if (lastState)
            low = mid;
        else high = mid;
    }

    if (!lastState) {
        if (low != temp[i]) temp[i] = low;
        else temp[i] = high;
    }
}

vector<int> bacterias(int N, int A,int B, int K)
{
    forn (i,N)
        temp.push_back(A);

    int high = N;
    int low = -1;
    int i = 0;

    for (int i = 0; i+4 < temp.size() and cnt < K; i+=4) {
        if (i+4 >= temp.size()) break;

        forsn (j,i,4)
            temp[j] = B;

        if (!medir(temp)) {
            temp[i+2] = A;
            temp[i+3] = A;

            if (!medir(temp)) {
                temp[i+1] = A;

                if (!medir(temp)) {
                    binSrch(A,B,i);
                    temp[i+1] = B;

                    if(!medir(temp))
                        binSrch(A,B,i+1);
                }
                else binSrch(A,B,i+1);

                if (!medir(temp)) goto GO_ON;
            }
            else {
                GO_ON:
                temp[i+3] = A;

                if (!medir(temp)) {
                    binSrch(A,B,i+2);
                    temp[i+3] = B;

                    if(!medir(temp))
                        binSrch(A,B,i+3);
                }
                else binSrch(A,B,i+3);
            }
        }
    }

    if (i-3 > 0) i-=3;
    forsn(k,i,temp.size()) {
        temp[k] = B;
        if (!medir(temp))
            binSrch(A,B,k);
    }

    forn (i,N)
        if (!diferentes.count(i))
            temp[i] = B;

    return temp;
}
