#include<iostream>
using namespace std;
#include <string>
#include <memory>
/*
简单工厂（不是设计模式中的）
工厂方法
抽象工厂

工厂模式：主要是封装了对象的创建
*/

class Car
{
public:
    Car(string name):_name(name){}
    virtual void show() = 0;
protected:
    string _name;

};

class BWM : public Car
{
public:
    BWM(string name):Car(name) {}
    void show()
    {
        cout<<"获取一辆宝马"<<_name<<endl; 
    }
};

class Audi : public Car
{
public:
    Audi(string name):Car(name) {}
    void show()
    {
        cout<<"获取一辆奥迪:"<<_name<<endl;
    }
};

// 工厂方法
// 简单工厂的缺点是不满足软件开发的开闭原则，不同工厂没有区分
class Factory
{
public:
    virtual Car* createCar(string name) = 0;
};
// 宝马工厂
class BWMFactory : public Factory
{
public:
    Car* createCar(string name)
    {
        return new BWM(name);
    }
};
// 奥迪工厂
class Audiactory : public Factory
{
public:
    Car* createCar(string name)
    {
        return new Audi(name);
    }
};

int main(){
    unique_ptr<Factory> bmwfty(new BWMFactory());
    unique_ptr<Factory> audifty(new Audiactory());
    unique_ptr<Car> p1(bmwfty->createCar("X6"));
    unique_ptr<Car> p2(audifty->createCar("A8"));
    p1->show();
    p2->show();

    return 0;
}