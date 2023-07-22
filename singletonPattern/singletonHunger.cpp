#include<iostream>
using namespace std; 

// 单例模式：
// 饿汉式单例模式：还没获取单例对象，实例对象就已经产生了
// 懒汉式单例模式：唯一的实例对象，直到第一次获取它的时候，才产生

// 饿汉式单例模式，一定是线程安全的
class Singleton
{
public:
    static Singleton* getInstance()
    {
        return &instance;
    }
private:
    static Singleton instance; //定义唯一的类的实例对象
    Singleton(){} //构造函数私有化
    Singleton(const Singleton&) = delete; //删除拷贝构造
    Singleton& operator=(const Singleton&) = delete; //删除赋值重载
};
Singleton Singleton::instance; //类的静态变量必须在类外定义
int main()
{
    Singleton *p1 = Singleton::getInstance();
    Singleton *p2 = Singleton::getInstance();
    Singleton *p3 = Singleton::getInstance();

    return 0;
}

// 懒汉式单例模式