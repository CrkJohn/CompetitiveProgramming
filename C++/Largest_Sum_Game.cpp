#include <bits/stdc++.h>
#define loop(i,a,b) for(i=a;i<b;i++)
#define rev(i,a,b)  for(i=a;i>=b;i--)
#define itloop(i,a) for(i=a.begin();i!=a.end();i++)
#define READ(file)  freopen(file, "r", stdin)
#define WRITE(file) freopen(file, "w", stdout)
#define pb(a)    push_back(a)
#define pf(a)    push_front(a)
#define tup(a,b) make_pair(a,b)
#define popb()   pop_back()
#define popf()   pop_front()
#define X        first
#define Y        second
#define LIM      100
#define INF      1000000010
#define SZ       1000005
#define upA(a)   a*a
#define base     10000
#define EPS      1e-9
#define LSOne(i) (i&(-i))

using namespace std;
typedef long long large;
typedef pair<int,int> ii;
typedef deque<int> di;
typedef deque<ii> dii;
typedef di::iterator dit;
typedef vector<int> vi;
typedef set<int> si;
typedef set<large> sl;
typedef complex<double> im;
typedef vector<char*> vs;
typedef vector<large> bigint;



long n[SZ];
int main(){
    long i,j;
    char str[SZ];
    while (gets(str)){

        memset(n,0,sizeof n);
        i=0;
        char * pch;
        pch = strtok(str," ");
        while(pch!=NULL){
            n[i] = atoi(pch);
            i++;
            pch = strtok(NULL," ");
        }

        long sum=0;
        long sump=-INF;
        loop(j,0,i){
            //printf("%d %d\n",n[j],sum);
            sum = sum + n[j];
            if (sum<0){
                sum=0;
            }
            sump = max(sump,sum);


        }
        printf("%ld\n",sump);
        str[SZ];
    }
    return 0;
}
