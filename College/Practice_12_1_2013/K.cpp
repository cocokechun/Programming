#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXP 60
int numPlates[MAXP];
int plates[MAXP][MAXP];
vector<int> nums;

int main ()
{
    int n, tc = 0;
    while (scanf("%d", &n) != EOF) {
        nums.clear();
        tc++;
        for (int i = 0; i < n; i++) {
            scanf("%d", &numPlates[i]);
            for (int j = 0; j < numPlates[i]; j++) {
                scanf("%d", &plates[i][j]);
                nums.push_back(plates[i][j]);
            }
        }

        vector<int>::iterator it;
        sort(nums.begin(), nums.end());
        it = unique (nums.begin(), nums.end());
        nums.resize( distance(nums.begin(),it) );
        /*for (int i = 0; i < nums.size(); i++) {
            printf("%d\n", nums[i]);
        }*/
        int numsegs = 0;

        for (int i = 0; i < n; i++) {
            bool inseg = false;
            int curnum = 0;
            int pidx = 0;

            while (true) {
                if (curnum >= nums.size()) break;
                if (pidx >= numPlates[i]) break;
                if (plates[i][pidx] == nums[curnum]) {
                    if (!inseg) numsegs++;
                    inseg = true;
                    pidx++;
                }
                else if (inseg && curnum < nums.size()-1 && plates[i][pidx] == nums[curnum+1]) {
                    curnum++;
                    pidx++;
                }
                else {
                    curnum++;
                    inseg = false;
                }

//                printf("%d %d %d %d %d\n", pidx, curnum, plates[i][pidx], nums[curnum], numsegs);
            }

//            printf("%d\n", numsegs);
        }
//        printf("%d\n", numsegs);
        printf("Case %d: %d\n", tc, 2*numsegs-n-1);
    }
    return 0;
}
