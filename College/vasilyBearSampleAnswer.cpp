#include <cstdio>
#include <vector>
#include <cassert>
 
using namespace std;
 
vector < int > a, cur, ans;
int n, curb, bestb;
 
int main(){
        scanf("%d", &n); a.resize(n);
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        for(int bit = 0; bit < 31; bit++) {
                int totalAnd = (1<<30) - 1;
                cur.clear();
                for(int i = 0; i < n; i++) {
                        if ((a[i] & (1<<bit))) cur.push_back(a[i]), totalAnd &= a[i];
                }
                if ((totalAnd % (1<<bit)) == 0) ans = cur;
        }
        printf("%zu\n", ans.size());
        for(int i = 0; i < ans.size(); i++)
                printf("%d%c", ans[i], " \n"[i == (ans.size() - 1)]);
}
