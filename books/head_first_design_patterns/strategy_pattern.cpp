#include <iostream>
#include <memory>
using namespace std;

// 将行为封装为一个算法家族
// Begin
struct QuarkBehavior { // 抽象行为类
    virtual void perfQuerk() = 0;
};

struct Quark : QuarkBehavior { // 具体类
    void perfQuerk() override { cout << "Quark Sound" << endl; }
};

struct Squark : QuarkBehavior { // 具体类
    void perfQuerk() override { cout << "Squark Sound" << endl; }
};
// End

struct Duck { // 主类
    std::shared_ptr<QuarkBehavior> quarkBehaviorPtr;
    void perfQuerk() { quarkBehaviorPtr->perfQuerk(); }
    // 可以动态修改叫声
    void setQuerkBehavior(std::shared_ptr<QuarkBehavior> ptr) {
        quarkBehaviorPtr = ptr;
    }
};

// 继承主类时，将抽象行为类实例化
struct MDuck : Duck {
    MDuck() { quarkBehaviorPtr = std::make_shared<Quark>(); }
};

struct FakeDuck : Duck {
    FakeDuck() { quarkBehaviorPtr = std::make_shared<Squark>(); }
};

int main(void) {

    using duckPtr = std::shared_ptr<Duck>;
    duckPtr duck1 = std::make_shared<MDuck>();
    duck1->perfQuerk();
    duck1->setQuerkBehavior(std::make_shared<Squark>());
    cout << duck1->quarkBehaviorPtr.use_count() << endl;

    duckPtr duck2 = std::make_shared<FakeDuck>();
    duck2->perfQuerk();

    return 0;
}
