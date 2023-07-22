#include<iostream>
using namespace std; 
#include<mutex>

// 单例模式：
// 饿汉式单例模式：还没获取单例对象，实例对象就已经产生了
// 懒汉式单例模式：唯一的实例对象，直到第一次获取它的时候，才产生

std::mutex mtx;

// 懒汉式单例模式2
class Singleton
{
public:
    static Singleton* getInstance()
    {
        // 函数静态局部变量的初始化，在汇编指令上已经自动添加线程的互斥指令了
        static Singleton instance;
        return &instance;
    }
private:
    Singleton(){} //构造函数私有化
    Singleton(const Singleton&) = delete; //删除拷贝构造
    Singleton& operator=(const Singleton&) = delete; //删除赋值重载
};

int main()
{
    Singleton *p1 = Singleton::getInstance();
    Singleton *p2 = Singleton::getInstance();
    Singleton *p3 = Singleton::getInstance();

    return 0;
}

