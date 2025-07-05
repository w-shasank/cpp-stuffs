#include<iostream>
using namespace std;
#include<cstring>
class myString{
    private:
         char *string;
    public:
        myString():string(nullptr){}
        myString():string(char *str)
        {
            string = new char(strlen(str) + 1);
            strcpy(string, str);
        }


};
int main()
{
    
    char first[100],second[100];
    cout<<"Enter the first string :"<<endl;
    cin>>first[100];
    myString s1(first);
    cout<<"Enter th                                                                                                                                                                     e second string :"<<endl;
    cin>>second[100];
    myString s2(second);




    return 0;
}
