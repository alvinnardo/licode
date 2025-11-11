#include <iostream>
#include <memory>
using namespace std;

// 给火鸡套一层衣服，使其看上去像鸭子，该层衣服就是适配器
// 要实现的接口
class Duck {
  public:
    virtual void quack() { cout << "ga ga" << endl; }
    virtual void fly() { cout << "flying" << endl; }
};

// 被适配者
class Turkey {
  public:
    virtual void gobble() = 0;
    virtual void fly() = 0;
};

class WildTurkey : public Turkey {
  public:
    void gobble() override { cout << "goo goo" << endl; }
    void fly() override { cout << "short flying" << endl; }
};

// 适配器
class DuckAdaptor : public Duck {

    std::shared_ptr<Turkey> m_tptr;

  public:
    DuckAdaptor(std::shared_ptr<Turkey> ptr) : m_tptr(ptr) {}

    void quack() { m_tptr->gobble(); }

    void fly() {
        for (int i = 0; i < 5; i++) {
            m_tptr->fly();
        }
    }
};

int main(void) {

    std::shared_ptr<Turkey> turkey_ptr = std::make_shared<WildTurkey>();
    std::shared_ptr<Duck> duck_ptr = std::make_shared<DuckAdaptor>(turkey_ptr);

    duck_ptr->quack();
    duck_ptr->fly();

    return 0;
}
