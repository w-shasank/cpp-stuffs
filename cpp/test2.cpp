#include<iostream>
using namespace std;
class  converter {
   float feet;
   float inches;
  public:
  converter(float meter)
  {
    float totalInches=meter *39.37;
    feet=totalInches/12;
    inches=int(totalInches)%12;
  }
  void display()
  {
    cout<<endl<<"The height in feet and inches is :"<<feet<<"."<<inches;
  }

};
int main() {
   float meters;
    cout<<"Enter the distance in meters :"<<endl;
    cin>>meters;
    converter first = meters;
    first.display();
    return 0;
}