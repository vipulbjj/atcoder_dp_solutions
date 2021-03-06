    #include<bits/stdc++.h>
    using namespace std;
    #define fo(i,n) for(i=0;i<n;i++)
    #define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
    #define ll long long
    #define deb(x) cout << #x << "=" << x << endl
    #define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
    #define pb push_back
    #define mp make_pair
    #define F first
    #define S second
    #define all(x) x.begin(), x.end()
    #define sortall(x) sort(all(x))
    #define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
    #define PI 3.1415926535897932384626
    typedef pair<int, int>	pii;
    typedef pair<ll, ll>	pl;
    typedef vector<int>		vi;
    typedef vector<ll>		vl;
    typedef vector<pii>		vpii;
    typedef vector<pl>		vpl;
    typedef vector<vi>		vvi;
    typedef vector<vl>		vvl;

    int mpow(int base, int exp); 
    void ipgraph(int n, int m);
    void dfs(int u, int par, vvl& dp);

    const int mod = 1'000'000'007;
    const int N = 3e5, M = N;
    //=======================

    vi g[N];
    int a[N];

    vvl multiply(vvl &a, vvl &b)
    {
        vvl res(a.begin(),a.end());
        int n = a.size();
        for(int i=0; i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                res[i][j] = 0;
                for(int k=0;k<n;k++)
                {
                    res[i][j]+= ((a[i][k] * b[k][j])%mod);
                    res[i][j]%=mod;
                }
            }
        }
        return res;
    }

    void solve() {
    
    ll i, j, n, m, k, l; 
    cin>>n>>k;
    vvl edges(n,vl (n));
    fo(i,n)fo(j,n)cin>>edges[i][j];

    vvl answer(n, vl(n));
    fo(i,n)answer[i][i]=1;

    // i need multiplication of edges^k * answer

    while(k)
    {
        if(k%2)answer = multiply(answer,edges);
        edges = multiply(edges,edges);

        k=k/2;
    }
    
    int total = 0;
    fo(i,n)
    {
        fo(j,n)
        {
            total+=answer[i][j];
            total %= mod;
        }
    }
    
    
    
    cout<< total <<endl;
    
    
    }

    int main() {
        #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
        #endif
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        

        int t = 1;
        // cin >> t;
        while(t--) {
        solve();
        }

        return 0;
    }

    int mpow(int base, int exp) {
    base %= mod;
    int result = 1;
    while (exp > 0) {
        if (exp & 1) result = ((ll)result * base) % mod;
        base = ((ll)base * base) % mod;
        exp >>= 1;
    }
    return result;
    }

    void ipgraph(int n, int m){
        int i, u, v;
        while(m--){
            cin>>u>>v;
        u--, v--;
            g[u].pb(v);
            g[v].pb(u);
        }
    }

    void dfs(int u, int par, vvl &dp){
        for(int v:g[u]){
            if (v == par) continue;
            dfs(v, u, dp);
            //ways to paint the subtree such that u is black
            dp[u][0]*=dp[v][1];
            dp[u][0]%=mod;

            dp[u][1]*=((dp[v][1]+dp[v][0])%mod);
            dp[u][1]%=mod;
            // deb(g[u].size());
            // deb2(u,v);
            // deb2(dp[u][0],dp[u][1]);

        }
    }


