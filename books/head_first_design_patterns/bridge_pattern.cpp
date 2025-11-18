#include <bits/stdc++.h>
using namespace std;

// 电视类
class TV {
  public:
    virtual void on() = 0;
    virtual void off() = 0;
    virtual void tuneChannel() = 0;
};
using TVPtr = std::shared_ptr<TV>;

class TV_TYPE1 : public TV {
  public:
    void on() override final { cout << "TYPE1 TV on" << endl; }
    void off() override final { cout << "TYPE1 TV off" << endl; }
    void tuneChannel() override final {
        cout << "TYPE1 TV tuneChannel" << endl;
    }
};

class TV_TYPE2 : public TV {
  public:
    void on() override final { cout << "TYPE2 TV on" << endl; }
    void off() override final { cout << "TYPE2 TV off" << endl; }
    void tuneChannel() override final {
        cout << "TYPE2 TV tuneChannel" << endl;
    }
};

class TV_TYPE3 : public TV {
  public:
    void on() override final { cout << "TYPE3 TV on" << endl; }
    void off() override final { cout << "TYPE3 TV off" << endl; }
    void tuneChannel() override final {
        cout << "TYPE3 TV tuneChannel" << endl;
    }
};

// 遥控器类
class RemoteControl {
    TVPtr m_tv;

  public:
    RemoteControl(TVPtr tv) : m_tv(tv) {}
    void on() { m_tv->on(); }
    void off() { m_tv->off(); }
    void setChannel() { m_tv->tuneChannel(); }
};
using RemoteControlPtr = std::shared_ptr<RemoteControl>;

class RemoteControl_TYPE1 : public RemoteControl {
  public:
    RemoteControl_TYPE1(TVPtr tv) : RemoteControl(tv) {}
};

class RemoteControl_TYPE2 : public RemoteControl {
  public:
    RemoteControl_TYPE2(TVPtr tv) : RemoteControl(tv) {}
};

class RemoteControl_TYPE3 : public RemoteControl {
  public:
    RemoteControl_TYPE3(TVPtr tv) : RemoteControl(tv) {}
};

int main(void) {

    // 3 类遥控器 和 3 类电视可以相互组合
    auto tv_type2 = std::make_shared<TV_TYPE2>();
    auto rc_type3 = std::make_shared<RemoteControl_TYPE3>(tv_type2);
    rc_type3->on();
    rc_type3->off();
    rc_type3->setChannel();

    return 0;
}
