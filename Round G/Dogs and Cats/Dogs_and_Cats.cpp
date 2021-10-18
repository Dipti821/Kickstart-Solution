// 📱💻🙂😈

#include<bits/stdc++.h>
using namespace std;
# define ll long long int
#define ld long double
#define F first
#define S second
#define nl "\n"
#define mem(v, t) memset(v, t, sizeof(v))
#define all(v) v.begin(), v.end()
#define sz(v) (ll)(v.size())
#define srt(v) sort(all(v))
#define rsrt(v) sort(v.rbegin(), v.rend())
#define pb push_back
#define f(a) for (ll i = 0; i < a; i++)
#define rep(i, a, b) for (ll i = a; i < b; i++)
#define rrep(i, a, b) for (ll i = a; i > b; i--)
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pair<ll, ll>>
#define mp make_pair
#define PI 3.141592653589793238462643383279502884197169399375
#define INF (ll)(1e18 + 5)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
const int N=1e6+5;
const ll M=1000000007;
#define inf INT_MAX
#define ninf INT_MIN
#define tc ll t;  cin>>t; while(t--)
#define t0 __builtin_ctz

const ll mod=998244353;


//<-------------------FOR ORDERED SET  ------------------------------------------------------------>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>


//<-------------------POWER CALCULATION------------------------------------------------------------>
ll power(ll x, ll y)
{
ll result=1;
       while(y>0)
	   {
		   if(y%2==1)
		   result=(result*x)%M;

		   x=(x*x)%M;
		   y=y/2;
	   }
	   return result%M;
}

//<-------------------   PRIME CHECK   ------------------------------------------------------------>
vector<ll>prime(1e6+1,1);

void sieve()
{
prime[0]=prime[1]=0;
for(ll i=2;i*i<=1e6;i++)
{
	if(prime[i])
	{
		for(ll j=i*i;j<=1e6;j+=i)
		prime[j]=0;
	}
}
}

//<-------------------CALCULATION OF COMBINATORICS------------------------------------------------->
ll nCr[1003][1003];
void combinatorics()
{
nCr[0][0] = 1;
	for(int i = 1;i<1003;i++)
	{
		for(int j = 0;j<=i;j++)
		{
			if(j == 0)
				nCr[i][j] = 1;
			else if(j==1)
				nCr[i][j] = i;
			else
			{
				nCr[i][j] = (nCr[i-1][j-1] + nCr[i-1][j])%(M-1);
			}
		}
	}
}

//<-------------------PRIME FACTORISATION---------------------------------------------------------->
ll prime_factors[100001]={};
void primefactorization(ll n)
{
ll c=0;
while(n%2==0)
{
c++;
n/=2;
}
if(c>0)
prime_factors[2]++;
 
for(ll i=3;i*i<=n;i+=2)
{
        c=0;
        while(n%i==0)
        {
                c++;
                n/=i;
        }
        if(c>0)
        prime_factors[i]++;
}
if(n>1)
prime_factors[n]++;
 
}

//<------------------- CODE BEGINS🙂🙃 ------------------------------------------------------------>
void solve()
{

    ll t;  cin>>t;
	rep(j,1,t+1)
	{
	ll n,d,c,m;  cin>>n>>d>>c>>m;
	string s;  cin>>s;
    
	ll cat=0,dog=0,flag=1;
	vll v(n,0);
	f(n)
	{
		if(s[i]=='D')
		v[i]=1;
	}
	for(ll i=n-2;i>=0;i--)
	v[i]+=v[i+1];

	f(n)
	{
	if(s[i]=='C')
    {
		if(c==0 && v[i]>0)
		{
			flag=0;
			break;
		}
		c--;
	}
		else
		{
			if(d==0)
			{
			flag=0;
			break;
		    }
			d--;
			c+=m;
		}	
	}
	if(flag==1)
	cout<<"Case #"<<j<<": "<<"YES"<<nl;
	else
	cout<<"Case #"<<j<<": "<<"NO"<<nl;
	
}
}

int main()
{
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif
    
   fast;
   //tc
   solve();
  
  return 0;
}
