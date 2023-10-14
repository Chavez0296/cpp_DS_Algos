#include <iostream>
using namespace std;

class Student
{
    public:
    string getName() const;
    string addStudent(string& name);
    private:
    const string name;
    const int age;
    const char grade;

};
string Student::getName() const
{
    return name;
}
int main()
{
    cout << "Hello World." << endl;
    return 0;
}