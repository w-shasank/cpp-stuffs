#include<iostream>
using namespace std;
class polar{
    int radius;
    int theta;
  public:
    polar(int r = 0,int t= 0):radius(r),theta(t){}
    polar& operator =(const polar & other)
    {
        this->radius=other.radius;
       this->theta=other.theta;
        return this;
    }
    void display()
    {
        cout<<radius<<"    "<<tehta;
    }
};
int main()
{
 polar p(3,45);
 polar p1=p;
 return  0;
}


