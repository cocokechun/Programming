#include <string.h>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

int main()
{
   map<int, string> Employees;
   map<int, vector<int> > graph;

   // 1) Assignment using array index notation
   Employees[5234] = "Mike C.";
   Employees[3374] = "Charlie M.";
   Employees[1923] = "David D.";
   Employees[7582] = "John A.";
   Employees[5328] = "Peter Q.";

    graph[1].push_back(2);
    graph[1].push_back(3);

    for (map<int, vector<int> >::iterator i=graph.begin(); i!=graph.end(); i++) {
        cout << (*i).first << endl;
        vector<int> tmp = (*i).second;
        for (vector<int>::iterator ii = tmp.begin(); ii != tmp.end(); ii++) {
            cout << *ii << ' ';
        }
        cout << endl;
    }

   cout << "Employees[3374]=" << Employees[3374] << endl << endl;

   cout << "Map size: " << Employees.size() << endl;

   for( map<int,string>::iterator ii=Employees.begin(); ii!=Employees.end(); ++ii)
   {
       cout << (*ii).first << ": " << (*ii).second << endl;
   }
}
