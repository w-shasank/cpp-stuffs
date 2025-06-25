#include<iostream>
using namespace std;
class newClass {
    int x;
    int y;
    public:
    newClass(int a, int b) : x(a) ,y(b) {}

newClass(const newClass &obj)
{
    x= obj.x;
    y= obj.y;
}

};
int main() {
    newClass obj1(10, 20);
    newClass obj2 = obj1; // Copy constructor is called here
    cout << "Object created and copied successfully." << endl;
    return 0;
}