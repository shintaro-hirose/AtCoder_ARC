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
    vi As(N);
    rep(i, N) cin >> As[i];
    vi Bs(N);
    rep(i, N) cin >> Bs[i];
    vi Cs(M);
    vi Ds(M);
    vvi adj(N, vi(0));
    rep(i, M) {
        cin >> Cs[i] >> Ds[i];
        Cs[i]--;
        Ds[i]--;
        adj[Cs[i]].push_back(Ds[i]);
        adj[Ds[i]].push_back(Cs[i]);
    }
    // グループの合計値が前後一致していればOK

    vector<bool> seen(N, false);
    int groupCnt = -1;
    vvi G(N, vi(0));
    rep(i, N){
        if(seen[i]) continue;
        seen[i] = true;
        groupCnt++;
        G[groupCnt].push_back(i);
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int x: adj[cur]){
                if(seen[x]) continue;
                q.push(x);
                seen[x] = true;
                G[groupCnt].push_back(x);
            }
        }
    }
    string ans = "Yes";
    rep(i, groupCnt + 1){
        ll beforeSum = 0;
        ll afterSum = 0;
        for(int x: G[i]){
            beforeSum += As[x];
            afterSum += Bs[x];
        }
        if(beforeSum != afterSum){
            ans = "No";
            break;
        }
    }
    cout << ans << endl;

    return 0;
}