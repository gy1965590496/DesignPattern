#include <iostream>
using namespace std;
// 装饰器：主要是增加现有类的功能


class Car
{
public:
    virtual void show() = 0;
};

class Bmw : public Car
{
public:
    void show(){
        cout<<"宝马，拥有的功能：基础功能";
    }
};
class Audi : public Car
{
public:
    void show(){
        cout<<"奥迪，拥有的功能：基础功能";
    }
};
class Benz : public Car
{
public:
    void show(){
        cout<<"奔驰，拥有的功能：基础功能";
    }
};

class Decorator01 : public Car
{
public:
    Decorator01(Car* p):_pCar(p){}
    void show(){
        _pCar->show();
        cout<<",自动刹车";
    }
private:
    Car* _pCar;
};

class Decorator02 : public Car
{
public:
    Decorator02(Car* p):_pCar(p){}
    void show(){
        _pCar->show();
        cout<<",车道偏离";
    }
private:
    Car* _pCar;
};

int main()
{
    Car* p1 = new Benz();
    p1 = new Decorator01(p1);
    p1 = new Decorator02(p1);
    p1->show();
    cout<<endl;

    Car* p2 = new Bmw();
    p2 = new Decorator01(p2);
    p2->show();
    cout<<endl;
}