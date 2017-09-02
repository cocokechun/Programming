#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

string pref[111];
string suff[111];

void getpref(int i, int len)
{
  return pref[i].substr(0, len);
}
void getsuf(int i, int len)
{
  return suff[i].substr(suff[i].size() - len);
}

void pre()
{
  pref[0] = "0";
  pref[1] = "1";
  for(int i=2;i<=100;i++)
    {
      if(pref[i-1].size() + pref[i-2].size() <= 100000)
	{
	  pref[i] = pref[i-1] + pref[i-2];
	  suff[i] = pref[i]; // same thing
	}
      else
	{
	  if(suff[i-1].size() <= 100000

int main()
{
  pre();
}
