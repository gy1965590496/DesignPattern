#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
/*
行为型模式：主要关注对象是对象之间的通信
观察者模式Observer Pattern（发布-订阅模式）设计模式：主要关注的是对象的一对多关系
也就是多个对象都依赖一个对象，当该对象的状态发送改变时，其他对象都能接收到相应的通知

*/

// 观察者抽象类
class Observer
{
public:
    virtual void handle(int msgid) = 0;
};

class Observer1 : public Observer
{
public:
    void handle(int msgid)
    {
        switch (msgid)
        {
        case 1:
            cout<<"ob1 recv 1 msg"<<endl;
            break;
        case 2:
            cout<<"ob1 recv 2 msg"<<endl;
            break;
        
        default:
            cout<<"ob1 recv unkonw msg"<<endl;
            break;
        }
    }
};

class Observer2 : public Observer
{
public:
    void handle(int msgid)
    {
        switch (msgid)
        {
        case 2:
            cout<<"ob2 recv 2 msg"<<endl;
            break;
        
        default:
            cout<<"ob2 recv unkonw msg"<<endl;
            break;
        }
    }
};

class Observer3 : public Observer
{
public:
    void handle(int msgid)
    {
        switch (msgid)
        {
        case 1:
            cout<<"ob3 recv 1 msg"<<endl;
            break;
        
        case 3:
            cout<<"ob3 recv 3 msg"<<endl;
            break;
        
        default:
            cout<<"ob3 recv unkonw msg"<<endl;
            break;
        }
    }
};

// 主题类
class Subject
{
public:
    void addObserver(Observer* obser, int msgid)
    {
        _subMap[msgid].push_back(obser);

    }
    // 主题检测发送改变，通知相应的观察者
    void dispatch(int msgid)
    {
        auto it = _subMap.find(msgid);
        if(it!=_subMap.end()){
            for(Observer* pObser : it->second){
                pObser->handle(msgid);
            }
        }
    }
private:
    unordered_map<int, list<Observer*>> _subMap;
};

int main()
{
    Subject sub;
    Observer* p1 = new Observer1();
    Observer* p2 = new Observer2();
    Observer* p3 = new Observer3();

    sub.addObserver(p1, 1);
    sub.addObserver(p1, 2);
    sub.addObserver(p2, 2);
    sub.addObserver(p3, 1);
    sub.addObserver(p3, 3);

    int msgid = 0;
    for(;;){
        cout<<"输入消息";
        cin>>msgid;
        if(msgid==-1)
            break;
        sub.dispatch(msgid);
    }

    return 0;
}