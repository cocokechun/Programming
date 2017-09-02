#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;
int 
gcd ( int a, int b )
{
  int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

int p_gcd(int a, int b) {
    if (a == 1 || b == 1) {
        return 1;
    } else {
        return gcd(a,b);
    }
}

void solve() {
    int n;
    cin >> n;

    int l[n];

    int i, j; 
    int max = 0;
    for (i = 0; i < n; i++) {
        cin>>l[i];
        if (l[i] > max) {
            max = l[i];
        }
    }
    
    int min_gcd = p_gcd(l[0], l[1]);
    for (i = 2; i < n; i++) {
        min_gcd = p_gcd(min_gcd, l[i]); 
    }
    int result = max / min_gcd;
    if ((result - n) % 2 == 1) {
        cout<<"Alice\n";
    } else {
        cout<<"Bob\n";
    }
}

int main() {
    solve();
    return 0;
}
