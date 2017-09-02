#include <iostream>

using namespace std;

int binary_search(int A[], int n, int target) {
   int lo = 0;
   int hi = n;
   while (lo <= hi) {
      int mid = lo + (hi-lo)/2;
      if (A[mid] == target)
         return mid;            
      else if (A[mid] < target)
         lo = mid+1;
      else
         hi = mid-1;
    }
    return -1;
}
            
   // target was not found

int main() {
    int A[] = {0,1,2,3,4};

    printf("%d\n", binary_search(A, 1, 0));
    
}
