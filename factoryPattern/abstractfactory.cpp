#include<iostream>
using namespace std;
#include <string>
#include <memory>
/*
简单工厂（不是设计模式中的）
特点：把对象的创建封装在一个接口函数里面，通过传入不同的标识，返回创建的对象
客户不用自己负责new对象，不用了解对象创建的详细过程

缺点：提供创建对象实例的接口不闭合，不能对修改关闭

工厂方法
特点：Factory基类，提供一个纯虚函数（创建产品），定义派生类（具体产品的工厂）负责创建对应的产品
可以做到不同的产品，在不同的工厂里面创建，能够对现有工厂，以及产品的修改关闭

缺点：实际上，很多产品是有关联关系的，属于一个产品簇，不应该放在不同的工厂里面去创建，这样一是
不符合实际产品的对象创建的逻辑，二十若产品簇中的子部件如果都使用工厂的话，工厂类太多了，不好维护

抽象工厂
把有关联关系的，属于一个产品簇的所有产品创建的接口函数，放在一个抽象工厂AbstractFactory中
派生类应该负责创建该产品簇里面所有的产品

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


class Light
{
public:
    virtual void show() = 0;
};

class BWMLight : public Light
{
public:
    void show(){cout<<"宝马灯"<<endl;}
};

class AudiLight : public Light
{
public:
    void show(){cout<<"奥迪灯"<<endl;}
};

// 工厂方法 => 抽象工厂（对一组有关联关系的产品簇提供产品对象的统一创建）
// 简单工厂的缺点是不满足软件开发的开闭原则，不同工厂没有区分
class AbstractFactory
{
public:
    virtual Car* createCar(string name) = 0;
    virtual Light* createCarLight() = 0;
};
// 宝马工厂
class BWMFactory : public AbstractFactory
{
public:
    Car* createCar(string name)
    {
        return new BWM(name);
    }
    Light* createCarLight()
    {
        return new BWMLight();
    }
};
// 奥迪工厂
class Audiactory : public AbstractFactory
{
public:
    Car* createCar(string name)
    {
        return new Audi(name);
    }
    Light* createCarLight()
    {
        return new AudiLight();
    }
};

int main(){
    unique_ptr<AbstractFactory> bmwfty(new BWMFactory());
    unique_ptr<AbstractFactory> audifty(new Audiactory());
    unique_ptr<Car> p1(bmwfty->createCar("X6"));
    unique_ptr<Car> p2(audifty->createCar("A8"));
    unique_ptr<Light> l1(bmwfty->createCarLight());
    unique_ptr<Light> l2(audifty->createCarLight());
    p1->show();
    p2->show();
    l1->show();
    l2->show();

    return 0;
}