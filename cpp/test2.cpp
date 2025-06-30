#include<iostream>
using namespace std;
class  converter {
   int feet;
   int inches;
  public:
  converter(int meter)
  {
    int totalInches=meter *40;
    feet=totalInches/12;
    inches=totalInches%12;
  }
  void display()
  {
    cout<<endl<<"The height in feet and inches is :"<<feet<<"."<<inches;
  }

};
int main() {
    int meters;
    cout<<"Enter the distance in meters :"<<endl;
    cin>>meters;
    converter first = meters;
    first.display();
    return 0;
}