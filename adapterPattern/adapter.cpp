#include <iostream>
#include <string>
using namespace std;

// VGA接口
class VGA
{
public:
    virtual void play() = 0;
    string getType() const { return "VGA"; }
};
// TV01表示支持VGA接口的投影仪
class TV01 : public VGA
{
public:
    void play()
    {
        cout<<"paly video by VGA"<<endl;
    }
};

// HDMI接口
class HDMI
{
public:
    virtual void play() = 0;
    string getType() const { return "HDMI"; }
};
// TV01表示支持VGA接口的投影仪
class TV02 : public HDMI
{
public:
    void play()
    {
        cout<<"paly video by HDMI"<<endl;
    }
};

// 实现一个电脑类（只支持VGA接口）
class Computer
{
public:
    // 由于
    void playVideo(VGA *pVGA){
        pVGA->play();
    }


};
// 接口不兼容的解决方法
/*
1.换一个支持HDMI的电脑（代码重构）
2.买一个转换头（适配器），把VGA信号转为HDMI信号（添加适配器类）
*/

class VGAToHDMIAdapter : public VGA
{
public:
    VGAToHDMIAdapter(HDMI* pHDMI):_pHDMI(pHDMI){}
    void play(){
        _pHDMI->play();
    }
private:
    HDMI* _pHDMI;
};

int main()
{
    Computer computer;
    // VGA
    // computer.playVideo(new TV01());
    // 接口不兼容
    // computer.playVideo(new TV02());
    // VGA -> 转接口 ->HDMI
    // HDMI* hdmi = new TV02();
    // VGAToHDMIAdapter* vgaToHDMI = new VGAToHDMIAdapter(hdmi);
    // computer.playVideo(vgaToHDMI);

    // 
    computer.playVideo(new VGAToHDMIAdapter(new TV02()));

    return 0;
}