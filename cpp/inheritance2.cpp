#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
class masterss
{
    private :
        string name="Master";
        int id=69;
    protected :
        string user_name;
        void introduce()
        {
        cout<<"Hi ! My name is :"<<name;
        cout<<"My professional id is :"<<id;
        }
        void giveintro()
        {
            cout<<"Whats yours ?";
            cin>>user_name;
        }
        
};
class slavess:public masterss{
    private :
        int password;
    public:
        void getPassword()
        {
            cout<<"Enter your password :";
            cin>>password;
        }
        bool Authenticate()
        {
            if(password)
            {
                cout<<"Authentication Successfull !!";
                 system("clear");
                return true;
            } 
        }
        void slaveintro()
        {
            introduce();
        }

        void slaveasksIntro()
        {
            giveintro();
        }

};
int main()
{
      slavess first;
      first.getPassword();
      if(first.Authenticate())
      {
        first.slaveintro();
        first.slaveasksIntro();      
      }

    return 0;
}