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

enum CarType
{
    bwm, audi
};
// 简单工厂
class SimpleFactory
{
public:
    Car* createCar(CarType ct){
        switch (ct)
        {
        case bwm:
            /* code */
            return new BWM("X1");
        case audi:
            return new Audi("A6");
        
        default:
            cerr<<"参数不正确"<<endl;
            break;
        }
    }
};

int main(){
    // 传统创建方法，缺点：需要记住每种车的创建方法
    // Car* p1 = new BWM("X1");
    // Car* p2 = new Audi("A6");

    // 简单工厂
    // SimpleFactory *factory = new SimpleFactory();
    // Car* p1 = factory->createCar(bwm);
    // Car* p2 = factory->createCar(audi);
    
    unique_ptr<SimpleFactory> factory(new SimpleFactory());
    unique_ptr<Car> p1(factory->createCar(bwm));
    unique_ptr<Car> p2(factory->createCar(audi));

    p1->show();
    p2->show();
    // delete p1;
    // delete p2;
    // delete factory;

    return 0;
}