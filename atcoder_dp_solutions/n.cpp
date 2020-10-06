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
    void dfs(int u, int par);

    const int mod = 1'000'000'007;
    const int N = 3e5, M = N;
    //=======================

    vi g[N];
    int a[N];


    void solve() {
    // ll inf 1e14;
    int i, j, n, m, k, l; 
    cin>>n;
    vector<int> vec(n);
    vl pref(n,0);
    fo(i,n) {cin>>vec[i];pref[i] = pref[i-1]+vec[i];}
    vvl T(n,vl(n,1e14));

    int length;
    fo(length,n)
    {
        for(int i = 0; i<n, i+length<n;i++)
        {
            j = i + length;
            if(i==j) T[i][j]=0;
            else
            {
                for(int k = i;k<j;k++)
                T[i][j] = min(T[i][j], T[i][k] + T[k+1][j] -pref[i-1] + pref[j]);
            }
            
            
            // deb2(i,j);
        }
    }
    cout<< T[0][n-1]<<endl;
    
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

    void dfs(int u, int par){
        for(int v:g[u]){
            if (v == par) continue;
            dfs(v, u);
        }
    }


