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
  int i, j, n, m, l;
  string k;
  getline(cin,k);
//   cout<<k<<endl;
  int d;
  cin>>d;
  vector<vector <int> > dp(d,vector<int> (2,0));
  //dp[sum%d][sm_already]
  dp[0][0]=1;

for(int idx =0;idx<k.length();idx++)
{
    vector<vector <int> > new_dp(d,vi (2)); // could've taken a 3d dp to avoid this. and take sum upto final idx to be 0
    for(int sum = 0; sum<d;sum++)
  {
      for (int j=0;j<2;j++)
      {
          for(int digit =0;digit<=9;digit++)
          {
              if(digit> k[idx]-'0' && !j)
              {
                  break;
              }
              else
              {
                  new_dp[(sum + digit)%d][j || (digit<k[idx]-'0')] += dp[sum][j];
                  new_dp[(sum + digit)%d][j || (digit<k[idx]-'0')]%=mod;
                //   int a = (sum + digit)%d;
                //   int b = j || (digit<k[idx]-'0');
                //   deb2( a, b);
                //   deb(dp[a][b]);
              }
              
          }

      }

  }
  dp = new_dp;
  
}
// deb2(dp[0][0],dp[0][1]);
int answer = (dp[0][0] + dp[0][1]) % mod;
answer = answer -1;
if(answer == -1) answer = mod-1;
cout<<answer<<endl;

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


