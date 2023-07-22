#include<iostream>
using namespace std; 
#include<mutex>

// 单例模式：
// 饿汉式单例模式：还没获取单例对象，实例对象就已经产生了
// 懒汉式单例模式：唯一的实例对象，直到第一次获取它的时候，才产生

std::mutex mtx;

// 懒汉式单例模式，instance改为指针，第一次初始化为nullptr，第一次使用是new一个
class Singleton
{
public:
    static Singleton* getInstance()
    {
        // 锁放在这的话粒度太大
        if(instance==nullptr){
            // 锁放在这的话粒度合适，且注意一定要加上双重判断
            lock_guard<std::mutex> gurad(mtx);
            if(instance==nullptr){
                instance = new Singleton();
            }            
        }
        return instance;
    }
private:
    static Singleton *volatile instance; //定义唯一的类的指针实例对象
    Singleton(){} //构造函数私有化
    Singleton(const Singleton&) = delete; //删除拷贝构造
    Singleton& operator=(const Singleton&) = delete; //删除赋值重载
};
Singleton*volatile Singleton::instance = nullptr; //类的静态变量必须在类外定义
int main()
{
    Singleton *p1 = Singleton::getInstance();
    Singleton *p2 = Singleton::getInstance();
    Singleton *p3 = Singleton::getInstance();

    return 0;
}

