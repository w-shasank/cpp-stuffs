#include<iostream>
#include<string>
using namespace std;
class entity{
    protected :
        void namer(){
            cout<<"My name is Shashank:";
        }
};
class person : public entity{
    public :
        void cafe(){
            cout<<"I am a person and I love to drink coffee"<<endl;
        }
        void showme(){
            namer();
            cout<<"I am a person"<<endl;
        }
};  
int main()
{
    person p;
    cout<<"This is a person class"<<endl;
    p.cafe();
    p.showme();
    return 0;
    
}