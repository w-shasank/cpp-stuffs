#include<iostream>
#include<iomanip>
using namespace std;
class converters
{
    int foot;
    int inches;
  public:
  converters():foot(0),inches(0){}
  converters(int a, int b):foot(a),inches(b){}
     operator float () const
     {
        int totalInches =  foot*12 + inches;
        return totalInches/39.37 ;
     }
     void display()
     {
        cout<<"The height in feet and inches is :"<<foot<<"."<<inches;

     }
       

};
int main()
{

      converters c1(5,4);
      c1.display();
      float Meters=0 ;
      Meters=c1;
      cout  << "The height in meters is " << fixed<<setprecision(2)<< Meters << endl;


    return 0;
}