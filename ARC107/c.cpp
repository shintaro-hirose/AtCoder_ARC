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
typedef vector<bool> vb;
typedef vector<vb> vvb;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const ll mod = 998244353;

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    
    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }
    
    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    
    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }
    
    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main() {
    int N, K; cin >> N >> K;
    vvi A(N, vi(N));
    rep(i, N) rep(j, N) cin >> A[i][j];

    UnionFind uf1(N);
    UnionFind uf2(N);

    vi cnt1(N);
    vi cnt2(N);

    ll kaijo[51];
    kaijo[0] = 1;
    rep(i,50){
        kaijo[i+1] = kaijo[i] * (i+1) % mod;
    }

    for(int i1 = 0; i1 < N - 1; i1++){
        for(int i2 = i1 + 1; i2 < N; i2++){
            bool isOK = true;
            rep(i3, N){
                if(A[i1][i3] + A[i2][i3] > K){
                    isOK = false;
                    break;
                }
            }
            if(isOK) {
                uf1.unite(i1, i2);
            }
        }
    }

    for(int i1 = 0; i1 < N - 1; i1++){
        for(int i2 = i1 + 1; i2 < N; i2++){
            bool isOK = true;
            rep(i3, N){
                if(A[i3][i1] + A[i3][i2] > K){
                    isOK = false;
                    break;
                }
            }
            if(isOK) {
                uf2.unite(i1, i2);
            }
        }
    }
    rep(i, N){
        cnt1[uf1.root(i)]++;
        cnt2[uf2.root(i)]++;
    }
    ll ans = 1;
    rep(i,N){
        // cout << "cnt1: " << cnt1[i] << endl;
        // cout << "cnt2: " << cnt2[i] << endl;
        if(cnt1[i] > 0) ans = ans * kaijo[cnt1[i]] % mod;
        if(cnt2[i] > 0) ans = ans * kaijo[cnt2[i]] % mod;
    }
    cout << ans << endl;
    return 0;
}