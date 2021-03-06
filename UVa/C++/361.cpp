#include<bits/stdc++.h>
#include<string>

#define fore(i,a,b) for(int i = a; i<b;i++)
#define forn(i,b) for(int i = 0; i<b;i++)
#define for1(i,b) for(int i = 1; i<=b;i++)
#define ford(i,a,b) for(int i = a; i>=b;i--)
#define fi first
#define se second
#define pb push_back
#define lec() freopen("in.txt","r",stdin); freopen("out.txt","w",stdout)
#define si(a) ((int)a.size())
#define eps 1e-10
#define all(x) (x).begin(),(x).end()


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


ostream & operator << (ostream &out, const pii &c){
	out << "x =" << c.fi << ", y = " << c.se << ";";
    	return out;
}

const double pi = (double)acos(-1.0);


struct point{
	double x,y;
	point(){x= y = 0.0;}
	point(double X ,double Y){
			x =  X;
			y = Y;
	}
  bool operator <(const point &other){
      if(fabs(x-other.x) > eps){return x < other.x;}
      return y < other.y;
  }
	bool operator==(const point &a) const {
			return fabs(x-a.x) < eps && fabs(y-a.y) < eps;
	}
	point operator+(const point &a) const {
        return point(x + a.x, y + a.y);
	}
	point operator-(const point &a) const {
        return point(x - a.x, y - a.y);
	}
	point operator/(const double val) const {
        return point(x / val, y / val);
	}
	point operator*(const double val) const {
        return point(x * val, y * val);
	}

};


ostream & operator << (ostream &out, const point &c){
	out << "(" << c.x << "," << c.y << ")";
    	return out;
}

point pivot;

double cross(point a, point b){
//	cerr << "\t a : " << a << "b : " << b << endl;
	return a.x*b.y - a.y *b.x;
}

bool ccw(point p,point q, point r){return cross(q-p,r-p)>0;}

double dist(point p, point q){
	return hypot(p.x-q.x,p.y-q.y);
}

bool angleCmp(point a, point b){
	if (fabs(cross(a-pivot,b-pivot)) < eps)return dist(pivot, a)<dist(pivot, b);    // check which one is closer
  point  d1  = a-pivot, d2 = b - pivot;
  return (atan2(d1.y, d1.x) - atan2(d2.y, d2.x)) < 0;
}

const double PI = acos(-1.);

double dot(point a, point b){
		return a.x*b.x + a.y*b.y;
}

double norm_sq(point a){return a.x*a.x + a.y*a.y;}

double angle(point a, point o, point b) {  // returns angle aob in rad
  point oa = a-o, ob = b-o;
  return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

double distToLine(point p, point a, point b, point &c) {
  point ap = p-a, ab = b-a;
  double u = dot(ap, ab) / norm_sq(ab);
  c =  a +  (ab * u);
  return dist(p, c);
}

/*
Retorna la distancia de p  a segmento ab defino por dos punto
el closest point va ser el 4 parametro
*/

double distToLineSegment(point p, point a, point b) {
  point ap = p-a, ab =  b-a;
  point c;
  double u = dot(ap, ab) / norm_sq(ab);
  if (u < 0.0) { c = point(a.x, a.y);// closer to a
    return dist(p, a); }// Euclidean distance between p and a
  if (u > 1.0) { c = point(b.x, b.y);                   // closer to b
    return dist(p, b); }         // Euclidean distance between p and b
  return distToLine(p, a, b, c);
}

bool inPolygon(point pt, const vector<point> &P) {
  if(si(P) == 0)return false;
  double sum = 0;    // assume the first vertex is equal to the last vertex
  forn(i,si(P)-1) {
  	if(distToLineSegment(pt,P[i],P[i+1])<eps)return 1;
    if (ccw(pt, P[i], P[i+1]))
         sum += angle(P[i], pt, P[i+1]);                   // left turn/ccw
    else sum -= angle(P[i], pt, P[i+1]); }                 // right turn/cw
  return fabs(fabs(sum) - 2*PI) < eps;
}


vector<point> CH(vector<point> &P){
    int n  = si(P);
    if(n==0)return P;
    if(n<=3){
				if(!(P[0]==P[n-1]))P.pb(P[0]);
				return P;
    }
    int P0 = 0;
		for1(i,n-1)if (P[i].y<P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))P0 = i;
		swap(P[0],P[P0]);
		pivot = P[0];
		sort(++P.begin(), P.end(),angleCmp);
		vector<point> S;
		S.pb(P[n-1]); S.pb(P[0]); S.pb(P[1]);
		int i = 2,j;
		while(i<n){
			j = si(S)-1;
			(ccw(S[j-1], S[j], P[i]))?S.pb(P[i++]):S.pop_back();
		}
		cerr << si(S) << endl;
    return S;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed;
	cerr.precision(2);
	cout.precision(0);
	cerr << fixed;
  //lec();
	int f= 0, c , r ,o , ntc = 1;
	while(1){
		cin >> c >> r >> o;
		if(c+r+o==0)break;
		vector<point> cops(c) , robberts(r) , other(o);
		map<string,int> cMap,rMap;
		forn(i,c){
				cin >> cops[i].x >> cops[i].y;
				int x = (int)cops[i].x;
				int y = (int)cops[i].y;
				string str  = to_string(x)+"-"+to_string(y);
				int sizeMap = cMap[str];
				cMap[str] = (sizeMap) ? sizeMap+1 : 1;
		}
		forn(i,r){
				cin >> robberts[i].x >> robberts[i].y;
				int x = (int)robberts[i].x;
				int y = (int)robberts[i].y;
				string str  = to_string(x)+"-"+to_string(y);
				int sizeMap = rMap[str];
				rMap[str] = (sizeMap) ? sizeMap+1 : 1;
		}
		forn(i,o)cin >> other[i].x >> other[i].y;
		vector<point> chCops = CH(cops);
		vector<point> chRob = CH(robberts);
		cout << "Data set "<<ntc++<<":\n";
		int sizeCops = si(chCops) , sizeRobs = si(chRob);
		for(point p : other){
					int chBool = 0,roBool = 0;
					int x = (int)p.x;
					int y = (int)p.y;
					string str  = to_string(x)+"-"+to_string(y);
					if(rMap[str]>=3)roBool=1;
					if(cMap[str]>=3)chBool=1;
					if(sizeCops>3)if(inPolygon(p,chCops))chBool = 1;
					if(sizeRobs>3)if(inPolygon(p,chRob))roBool = 1;
					cout << "     Citizen at (" << p.x<< "," << p.y <<") is";
					if(chBool)cout << " safe.\n";
					else if(roBool)cout << " robbed.\n";
					else cout << " neither.\n";
    }
		cout << endl;


	}
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	return 0;
}

