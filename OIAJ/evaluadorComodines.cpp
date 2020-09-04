#include <iostream>
#include <vector>
#include <cstdio>
#include "comodines.cpp"

using namespace std;

int comodines(vector<vector<int> > grilla);

static void leerVector(vector<int> &v, int N)
{
    for (int i=0;i<N;i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
}

static void leerVectorDeVector(vector<vector<int> > &v, int N, int M)
{
    for (int i=0;i<N;i++)
    {
        v.push_back(vector<int>());
        leerVector(v.back(), M);
    }
}

int main()
{
    freopen("comodines.in","r",stdin);
    int N, M;
    cin >> N >> M;
    vector<vector<int> > grilla;
    leerVectorDeVector(grilla, N, M);
    cout << comodines(grilla) << endl;
    return 0;
}

