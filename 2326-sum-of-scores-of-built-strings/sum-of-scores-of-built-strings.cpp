#define sz(x) ((int)(x).size())
using ll = long long;
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll m){a = a % m; return expo(a, m-2, m);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return mod_mul(a, mminvprime(b, m), m);}
class Solution {
    struct Hashing{
        string s;
        ll p = 30;
        ll m = 1e9 + 7;
        int n;
        vector<ll> prefixHash;
        vector<ll> powersOfP;
        vector<ll> inversePowersOfP;
        Hashing(string queryString){
            s = queryString;
            n = s.size();
            prefixHash.resize(n);
            powersOfP.resize(n);
            inversePowersOfP.resize(n);
            calculatePowersAndInversePowersOfP();
            calculatePrefixHashes();
        }
        void calculatePowersAndInversePowersOfP(){ // O(n)
            ll currentPower = 1;
            for(int i = 0; i < n; i++){
                powersOfP[i] = currentPower;
                currentPower = (currentPower * p) % m;
            }
            inversePowersOfP[n - 1] = mminvprime(powersOfP[n - 1], m);
            for(int i = n - 2; i >= 0; i--){
                inversePowersOfP[i] = (inversePowersOfP[i + 1] * p) % m;
            }
        }
        void calculatePrefixHashes(){ // O(n)
            ll hashSoFar = 0;
            for(int i = 0; i < n; i++){
                hashSoFar = (hashSoFar + (s[i] - 'a' + 1) * powersOfP[i]) % m;
                prefixHash[i] = hashSoFar;
            }
        }
        
        
        ll substringHash(int l, int r){  // O(1)
            ll val1 = prefixHash[r];
            ll val2 = l > 0 ? prefixHash[l - 1] : 0LL;
            return ((val1 - val2 + m) * inversePowersOfP[l]) % m;
        }
    };
    public:
    long long sumScores(string s) {
        ll n = s.size();
        Hashing hs = Hashing(s);
        vector<ll> z(n, 0);
        z[0] = n;
        for(ll r = n-1; r>0; r--){
            
            ll low = r; 
            ll high = n-1;
            while(low <= high){
                ll mid = (low + high)/2;

                ll hashright = hs.substringHash(r, mid);
                ll hashleft = hs.substringHash(0, mid-r);
                
                if(hashleft == hashright){
                    z[r] = max(z[r], mid-r+1);
                    low = mid+1;
                } else {
                    high = mid-1;
                }

            }
        }

        ll ans = 0;
        for(auto x : z){
            ans += x;
        }
        return ans;

    }
};