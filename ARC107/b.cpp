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
const ll mod = 1000000007;

int f(int a, int n){
    if(n >= a) return a - 1;
    if(n*2<a) return 0;
    int ret = 0;
    ret = a - 1 - 2 * (a - n - 1);
    return ret;
}

int main() {
    int N, K;
    cin >> N >> K;
    if(K<0) K *= -1;

    ll ans = 0;

    for(int i = 2; i <= 2 * N - K; i++){
        ans += (ll)f(i, N) * f(i + K, N);
    }
    cout << ans << endl;
    return 0;
}