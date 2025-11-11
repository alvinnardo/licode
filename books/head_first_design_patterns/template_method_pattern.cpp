#include <bits/stdc++.h>
using namespace std;

struct Beverage {

    // 框架算法流程
    void prepareRecipe() {
        boilWater();
        brew();
        pourInCup();
        if (needCondiments()) {
            addCondiments();
        }
    }

    // 用 final 标记不能被修改的方法
    virtual void boilWater() final { cout << "boil water" << endl; }

    virtual void pourInCup() final { cout << "pour in cup" << endl; }

    // 派生类必须要实现的方法
    virtual void brew() = 0;
    virtual void addCondiments() = 0;

    // 钩子函数，派生类可以选择是否覆盖
    virtual bool needCondiments() { return true; }
};

using BeveragePtr = std::shared_ptr<Beverage>;

struct Coffee : public Beverage {

    Coffee() { cout << ">>>>> create a coffee <<<<<" << endl; }
    void brew() override { cout << "brew coffee" << endl; }
    void addCondiments() override { cout << "add sugur" << endl; }

    // 覆盖钩子
    // 这里可以自定义复杂的钩子，比如让用户从键盘输入是否添加配料
    bool needCondiments() override { return false; }
};

struct Tea : public Beverage {
    Tea() { cout << ">>>>> create a tea <<<<<" << endl; }
    void brew() override { cout << "brew tea" << endl; }
    void addCondiments() override { cout << "add lemon" << endl; }
};

int main(int argc, char *argv[]) {

    BeveragePtr coffee = std::make_shared<Coffee>();
    coffee->prepareRecipe();

    BeveragePtr tea = std::make_shared<Tea>();
    tea->prepareRecipe();

    return 0;
}
