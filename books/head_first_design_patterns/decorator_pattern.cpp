#include <format>
#include <iostream>
#include <memory>
using namespace std;

class Beverage { // 饮料
  public:
    virtual string getDescription() { return ""; }
    virtual double getCost() { return 0; }
};

class Espresso : public Beverage { // 浓缩咖啡
  public:
    string getDescription() override { return "Espresso"; }
    double getCost() override { return 1.99; }
};

class HouseBlend : Beverage { // 家常综合
  public:
    string getDescription() override { return "HouseBlend"; }
    double getCost() override { return 0.89; }
};

class DarkRoast : Beverage { // 深度拷贝
  public:
    string getDescription() override { return "DarkRoast"; }
    double getCost() override { return 0.99; }
};

class Decaf : Beverage { // 低咖啡因
  public:
    string getDescription() override { return "Decaf"; }
    double getCost() override { return 1.05; }
};

// 用继承 + 组合的方式
class CondimentDecortor : public Beverage { // 配料装饰器
  public:
    std::shared_ptr<Beverage> m_bptr;
    CondimentDecortor(std::shared_ptr<Beverage> ptr) : m_bptr(ptr) {}
};

class Mocha : public CondimentDecortor { // 摩卡
  public:
    Mocha(std::shared_ptr<Beverage> ptr) : CondimentDecortor(ptr) {}
    double getCost() override { return m_bptr->getCost() + 0.2; }
    string getDescription() override {
        return m_bptr->getDescription() + ", Mocha";
    }
};

class Soy : public CondimentDecortor { // 豆奶
  public:
    Soy(std::shared_ptr<Beverage> ptr) : CondimentDecortor(ptr) {}
    double getCost() override { return m_bptr->getCost() + 0.15; }
    string getDescription() override {
        return m_bptr->getDescription() + ", Soy";
    }
};

class Whip : public CondimentDecortor { // 奶泡
  public:
    Whip(std::shared_ptr<Beverage> ptr) : CondimentDecortor(ptr) {}
    double getCost() override { return m_bptr->getCost() + 0.1; }
    string getDescription() override {
        return m_bptr->getDescription() + ", Whip";
    }
};

class Milk : public CondimentDecortor { // 热奶
  public:
    Milk(std::shared_ptr<Beverage> ptr) : CondimentDecortor(ptr) {}
    double getCost() override { return m_bptr->getCost() + 0.1; }
    string getDescription() override {
        return m_bptr->getDescription() + ", Milk";
    }
};

int main(void) {
    // 想要一杯浓缩咖啡
    std::shared_ptr<Beverage> ptr = std::make_shared<Espresso>();
    cout << ptr->getDescription() << ": " << ptr->getCost() << endl;

    // 加一份摩卡，两份热奶
    ptr = std::make_shared<Mocha>(ptr);
    ptr = std::make_shared<Milk>(ptr);
    ptr = std::make_shared<Milk>(ptr);
    cout << ptr->getDescription() << ": " << ptr->getCost() << endl;

    return 0;
}
