#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define f(i,x,y) for (int i = x; i < y; i++)
#define fd(i,x,y) for(int i = x; i>= y; i--)
#define FOR(it,A) for(typeof A.begin() it = A.begin(); it!=A.end(); it++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define vint vector<int>
#define ll long long
#define clr(A,x) memset(A, x, sizeof A)
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fst first
#define snd second
#define ones(x) __builtin_popcount(x)
#define cua(x) (x)*(x)
#define eps (1e-9)
#define oo (1<<30)
#define debug(x) cout <<#x << " = " << x << endl
#define adebug(x,n) cout <<#x<<endl; f(i,1,n+1)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; f(i,0,m)f(j,0,n)cout<<x[i][j]<<char(j+1==n?10:32)
#define sync ios_base::sync_with_stdio(false)

using namespace std;

template<class T> inline void mini(T &a,T b){if(b<a) a=b;}
template<class T> inline void maxi(T &a,T b){if(b>a) a=b;}

vint L[100010];
vector<bool> P[100010];
bool A[100010];
set<int> ans;

bool dfs(int u, int a)
{
    printf("k is %d, p is %d\n", u, a);
  bool f = false;
  int a1 = 0;
  for(int i=0; i < L[u].size(); i++)
  {
    if(L[u][i] == a)continue;
    if(P[u][i])
      f = true;
    if(dfs(L[u][i], u))
      f = true;
  }
  return A[u] = f;
}

void dfs2(int u, int a)
{
  for(int i=L[u].size()-1; i>=0; --i)
  {
    if(L[u][i] == a) continue;
    if(A[L[u][i]])
    {
      dfs2(L[u][i], u);
    }
    else
    {
      if(P[u][i])
        ans.insert(L[u][i]);
    }
  }
}

int main(){
  sync;
  int n, a, b, t;
  cin >> n;
  f(i,1,n){
    cin >> a >> b >> t;
    L[a].push_back(b);
    L[b].push_back(a);
    P[a].push_back(t==2?1:0);
    P[b].push_back(t==2?1:0);
  }
  dfs(1, -1);
  dfs2(1, -1);
  cout << ans.size() << endl;
  FOR(it, ans)
  {
    cout << *it << " ";
  }
  cout << endl;
}
