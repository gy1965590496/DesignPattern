#include <iostream>
using namespace std;

/*
代理模式：通过代理类，来控制实际对象的访问权限
客户    助理（proxy）   老板（委托类）

*/

class VideoSite
{
public:
    virtual void freeMovie() = 0;
    virtual void vipMovie() = 0;
    virtual void icketMovie() = 0;
};

class FixBugVideoSite : public VideoSite // 委托类
{
public:
    virtual void freeMovie()
    {
        cout << "免费电影" << endl;
    }
    virtual void vipMovie()
    {
        cout << "VIP电影" << endl;
    }
    virtual void icketMovie()
    {
        cout << "券电影" << endl;
    }
};

// 代理类 代理VideoSite
class FreeVideoSiteProxy : public VideoSite
{
public:
    FreeVideoSiteProxy() { pVideo = new FixBugVideoSite(); }
    ~FreeVideoSiteProxy() { delete pVideo; }
    virtual void freeMovie()
    {
        pVideo->freeMovie();
    }
    virtual void vipMovie()
    {
        cout << "你目前是普通游客，需要升级VIP，才能观看VIP电影" << endl;
    }
    virtual void icketMovie()
    {
        cout << "你目前没有券，需要购买电影券，才能观看电影" << endl;
    }
private:
    VideoSite *pVideo;
};

// 代理类 代理VideoSite
class VipVideoSiteProxy : public VideoSite
{
public:
    VipVideoSiteProxy() { pVideo = new FixBugVideoSite(); }
    ~VipVideoSiteProxy() { delete pVideo; }
    virtual void freeMovie()
    {
        pVideo->freeMovie();
    }
    virtual void vipMovie()
    {
       pVideo->vipMovie();
    }
    virtual void icketMovie()
    {
        cout << "你目前没有券，需要购买电影券，才能观看电影" << endl;
    }
private:
    VideoSite *pVideo;
};

void watchMovie(VideoSite* ptr){
    ptr->freeMovie();
    ptr->vipMovie();
    ptr->icketMovie();    
}

int main()
{
    // 无法控制权限
    // VideoSite *p1 = new FixBugVideoSite();
    // p1->freeMovie();
    // p1->icketMovie();
    // p1->vipMovie();

    // 
    VideoSite* p1 = new FreeVideoSiteProxy();
    watchMovie(p1);
    VideoSite* p2 = new VipVideoSiteProxy();
    watchMovie(p2);
    return 0;
}