#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
    vector<double> student_marks(20);
 
    for (vector<double>::size_type i = 0; i < 20; i++)
    {
        cout << "Enter marks for student #" << i+1 
             << ": " << flush;
        cin >> student_marks[i];
    }
    // ... Do some stuff with the values
 
    return 0;
}
/*
vector<double> student_marks;
    // no size specified: vector contains
    // no elements
 
int num_students;
cout << "Number of students: " << flush;
cin >> num_students;
 
student_marks.resize (num_students);
 
for (vector<double>::size_type i = 0; i < num_students; i++)
{
    cout << "Enter marks for student #" << i+1 
         << ": " << flush;
    cin >> student_marks[i];
}*/
