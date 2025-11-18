#include <bits/stdc++.h>
using namespace std;

// 产品
class House {
    string partA;
    string partB;
    string partC;

  public:
    void setPartA(string &&str) { partA = std::move(str); }
    void setPartB(string &&str) { partB = std::move(str); }
    void setPartC(string &&str) { partC = std::move(str); }
    string toString() {
        stringstream ss;
        ss << "A house with partA: " << partA << ", partB: " << partB
           << ", partC: " << partC;

        return ss.str();
    }
};
using HousePtr = std::shared_ptr<House>;

// 生成器
class Builder {
  public:
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual void buildPartC() = 0;
    virtual HousePtr getHouse() = 0;
};

class HouseBuilder : public Builder {
    HousePtr house;

  public:
    HouseBuilder() { house = std::make_shared<House>(); }
    void buildPartA() override final { house->setPartA("aaa"); }
    void buildPartB() override final { house->setPartB("bbb"); }
    void buildPartC() override final { house->setPartC("ccc"); }

    HousePtr getHouse() override final { return house; }
};
using BuilderPtr = std::shared_ptr<Builder>;

// 主管类
class Director {
    BuilderPtr builder;

  public:
    enum class type { SIMPLE, COMPLEX };
    Director(BuilderPtr ptr) : builder(ptr) {}
    void changeBuilder(BuilderPtr ptr) { builder = ptr; }

    // 主管指导要建造的类型
    void construct(Director::type t) {
        if (t == Director::type::SIMPLE) {
            builder->buildPartC();
        } else if (t == Director::type::COMPLEX) {
            builder->buildPartA();
            builder->buildPartB();
            builder->buildPartC();
        }
    }
    HousePtr getProduct() { return builder->getHouse(); }
};
using DirectorPtr = std::shared_ptr<Director>;

int main(void) {
    // 客户端和主管交互
    BuilderPtr builder = std::make_shared<HouseBuilder>();
    DirectorPtr director = std::make_shared<Director>(builder);
    director->construct(Director::type::COMPLEX);
    HousePtr house = director->getProduct();
    cout << house->toString() << endl;

    return 0;
}
