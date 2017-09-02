#include <iostream>
#include <functional>
#include <string>

using namespace std;
string hash(string s) {
    for (int i = 0; i < s.size(); i++) {
        s[i] += 6;
        s[i] %= 256;
    }
    return s;
}

int main ()
{

  cout << "happynewyear: " << hash("happynewyear") << endl;

  return 0;
}
