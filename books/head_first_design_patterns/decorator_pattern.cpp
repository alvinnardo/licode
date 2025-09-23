#include <format>
#include <iostream>
#include <memory>
using namespace std;

class Beverage { // 饮料
  protected:
    double cost{};
    string description;

  public:
    Beverage() {}
    virtual string getDescription() { return description; }
    virtual double getCost() { return cost; }
    virtual string getInfo() {
        return std::format("description: {}, cost: {}", getDescription(),
                           getCost());
    }
};

class Espresso : public Beverage { // 浓缩咖啡
  public:
    Espresso() {
        cost = 1.99;
        description = "Espresso";
    }
    string getDescription() override { return description; }
    double getCost() { return cost; }
};

class HouseBlend : Beverage { // 家常综合
  public:
    HouseBlend() {
        cost = 0.89;
        description = "HouseBlend";
    }
};

class DarkRoast : Beverage { // 深度拷贝
  public:
    DarkRoast() {
        cost = 0.99;
        description = "DarkRoast";
    }
};

class Decaf : Beverage { // 低咖啡因
  public:
    Decaf() {
        cost = 1.05;
        description = "Decaf";
    };
};

// 用继承 + 组合的方式
class CondimentDecortor : public Beverage { // 配料装饰器
  protected:
    Beverage beverage;

  public:
    CondimentDecortor() {}
    // virtual string getDescription() override { return description; }
    // virtual double getCost() override { return cost; }
    // string getInfo() override {
    //     return std::format("description: {}, cost: {}", getDescription(),
    //                        getCost());
    // }
};

class Mocha : public CondimentDecortor { // 摩卡
  public:
    Mocha(Beverage b) {
        beverage = b;
        cout << beverage.getDescription() << endl;
        cout << beverage.getCost() << endl;
        // cost = beverage.getCost() + 0.2;
        // description = beverage.getDescription() + ", Mocha";
    }
    double getCost() override { return beverage.getCost() + 0.2; }
    string getDescription() override {
        return beverage.getDescription() + ", Mocha";
    }
};

class Soy : public CondimentDecortor { // 豆奶
  public:
    Soy(Beverage b) {
        beverage = b;
        // cost = beverage.getCost() + 0.15;
        // description = beverage.getDescription() + ", Soy";
    }
};

class Whip : public CondimentDecortor { // 奶泡
  public:
    Whip(Beverage b) {
        beverage = b;
        // cost = beverage.getCost() + 0.1;
        // description = beverage.getDescription() + ", Whip";
    }
};

class Milk : public CondimentDecortor { // 热奶
  public:
    Milk(Beverage b) {
        beverage = b;
        // cost = beverage.getCost() + 0.1;
        // description = beverage.getDescription() + ", Milk";
    }
};

int main(void) {

    std::shared_ptr<Beverage> ptr = std::make_shared<Espresso>();
    cout << ptr->getInfo() << endl;
    cout << "===" << endl;

    // 想要一杯浓缩咖啡 加一份摩卡，两份热奶
    // std::shared_ptr<Beverage> p = std::make_shared<Mocha>(*ptr);
    // cout << p->getInfo() << endl;
    // // p = std::make_shared<Milk>(*p);
    // // p = std::make_shared<Milk>(*p);
    // p = std::make_shared<Mocha>(*p);
    // cout << p->getInfo() << endl;

    Beverage p = Mocha(*ptr);
    cout << p.getDescription() << endl;
    p = Mocha(p);
    cout << p.getDescription() << endl;

    return 0;
}
