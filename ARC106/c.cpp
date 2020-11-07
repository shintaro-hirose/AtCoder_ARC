#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const ll mod = 1000000007;

int main() {
    int N, M; cin >> N >> M;
    if(N == 1 && M == 0){
        cout << 1 << " " << 2 << endl;
        return 0;
    }
    if(M < 0 || N - (M + 2) < 0){
        cout << -1 << endl;
        return 0;
    }

    rep(i, N - (M + 2)){
        cout << 1 + 2 * i << " " << 2 * (i + 1) << endl;
    }
    cout << 2 * (N - M - 1) + 1 << " " << (int)1e9 << endl;
    rep(i, M + 1){
        cout << 2 * (N - M) + i * 2 << " " << 2 * (N - M) + i * 2 + 1 << endl;
    }
    return 0;
}