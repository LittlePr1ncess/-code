#include<bits/stdc++.h>
using namespace std;
class Animal
{
    public:
        string name;
        string address;
        int number;
        Animal(string name,string address,int number)
        {
            this->name=name;this->address=address;this->number=number;
        }
        void init()
        {
            cin>>this->name>>this->address>>this->number;
        }
    
};
class Fish :public Animal
{
    public:
        string color;
        int age;
        int weight;
        ~Fish()
        {
            cout<<"wtybill全球错斩"<<endl;
        }
        Fish(string name,string address,int number,string color ,int age,int weight):Animal(name,address,number)
        {
            this->name=name;this->address=address;this->number=number;this->color=color;this->age=age;this->weight=weight;
        }
};
int main()
{
    Animal *xgz = new Animal("xgz","home",233);
    cout<<xgz->name<<" "<<xgz->address<<" "<<xgz->number<<endl;
    xgz->init();
    cout<<xgz->name<<" "<<xgz->address<<" "<<xgz->number<<endl;
    Fish *rwy = new Fish("1","2",3,"a",4,5);
    cout<<rwy->weight;
    system("pause");
}