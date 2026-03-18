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

int arr[MAXN];

ll merge(int l, int mid, int r) {
    int asz = mid-l, bsz = r-mid;
    vector<int> a(asz), b(bsz);
    for (int i = 0; i < asz; i++) a[i] = arr[l+i];
    for (int i = 0; i < bsz; i++) b[i] = arr[mid+i];

    int aidx = 0, bidx = 0, idx = l;
    int beq = 0;
    ll acc = 0;
    while (aidx < asz && bidx < bsz) {
        if (a[aidx] <= b[bidx]) {
            int auxi = bidx;
            if (bidx && a[aidx] == b[bidx-1]) auxi -= beq;
            acc += auxi;
            arr[idx++] = a[aidx++];
        }
        else {
            if (bidx > 0 && b[bidx] != b[bidx-1])
                beq = 0;
            arr[idx++] = b[bidx++];
            beq++;
        }
    }

    while (aidx < asz) {
        int auxi = bidx;
        if (bidx && a[aidx] == b[bidx-1]) auxi -= beq;
        acc += auxi;
        arr[idx++] = a[aidx++];
    }
    while (bidx < bsz) arr[idx++] = b[bidx++];

    return acc;
}

ll split (int l, int r) {
    if (r-l == 1)
        return 0;

    int mid = (l+r)/2;
    ll acc = split(l,mid) + split(mid,r);
    acc += merge(l,mid,r);
    return acc;
}

int main() {
    FAST_IO;

    int t; cin >> t;

    forn(_,t) {
        int n; cin  >> n;
        forn(i,n) cin >> arr[i];

        cout << split(0,n) << '\n';
    }

    return 0;
}

