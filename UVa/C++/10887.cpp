#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define in() freopen("in.txt","r",stdin)
#define out() freopen("out.txt","w",stdout)
#define err() freopen("err.txt","w",stderr)


using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
    //in();
    //out();
		int ntc,m,n;
		map<string,int> mp;
		cin >> ntc;
		string lde;
    for1(cn,ntc){
        cin >> m >> n;
        getline(cin,lde);
        vector<string> str1(m) , str2(n);
        forn(i,m)getline(cin,str1[i]);
        forn(j,n)getline(cin,str2[j]);
        int sizeMap=0;
				mp.clear();
        forn(i,m){
            forn(j,n){
								string plusString= str1[i]+str2[j];
								if(mp[plusString]==0){
                    mp[plusString]=1;
                    sizeMap++;
                }
            }
        }
				cout <<  "Case "<<cn<<": "<<sizeMap<<endl;
    }
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    return 0;
}