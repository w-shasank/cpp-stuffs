#include<iostream>
#include<cmath>
using namespace std;
class cartesian{
    float x,y;
public:
    cartesian(float first=0,float second=0):x(first),y(second){}
    void display()
    {
        cout<<x<<"    "<<y;
    }
};
class polar{
    int radius;
    int theta;
public:
    polar(int r=0,int t =0){
        radius=r;
        theta=t;
    }
    operator cartesian()
    {
       float radians= theta*3.14/180;
      float x = radius*cos(radians);
      float y= radius * sin(radians);
  return cartesian(x,y);

    }
};
int main()
{
    polar p(1,45);
    cartesian c=p;
    c.display();
    return 0;
}