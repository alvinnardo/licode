#include <iostream>
#include <memory>
using namespace std;

// 抽象披萨类
struct Pizza {
    virtual void bake() { cout << "Baking ..." << endl; };
    virtual void cut() { cout << "Cut ..." << endl; };
    virtual void box() { cout << "Box ..." << endl; }
    virtual string getName() { return name; }

  protected:
    string name;
};

// 具体披萨类
struct NyPizzaTypeA : public Pizza {
    NyPizzaTypeA() { name = "NyPizzaTypeA"; }
};

struct NyPizzaTypeB : public Pizza {

    NyPizzaTypeB() { name = "NyPizzaTypeB"; }
};

struct NyPizzaTypeC : public Pizza {

    NyPizzaTypeC() { name = "NyPizzaTypeC"; }
};

struct ChicagoPizzaTypeA : public Pizza {
    ChicagoPizzaTypeA() { name = "ChicagoPizzaTypeA"; }
};
struct ChicagoPizzaTypeB : public Pizza {

    ChicagoPizzaTypeB() { name = "ChicagoPizzaTypeB"; }
};
struct ChicagoPizzaTypeC : public Pizza {

    ChicagoPizzaTypeC() { name = "ChicagoPizzaTypeC"; }
};

// 实现两个地区披萨店，每类披萨店可以生产自己风格的披萨
struct PizzaStore {
    std::shared_ptr<Pizza> orderPizza(string type) {
        std::shared_ptr<Pizza> pizza = createPizza(type);
        pizza->bake();
        pizza->cut();
        pizza->box();

        return pizza;
    }

    // 工厂方法模式，从这个方法创建一个 Pizza
    virtual std::shared_ptr<Pizza> createPizza(string type) = 0;
    virtual string getName() { return name; }

  protected:
    string name;
};

struct NyPizzaStore : public PizzaStore {
    NyPizzaStore() { name = "NyPizzaStore"; }

    std::shared_ptr<Pizza> createPizza(string type) {
        if (type == "A") {
            return std::make_shared<NyPizzaTypeA>();
        } else if (type == "B") {
            return std::make_shared<NyPizzaTypeB>();
        } else if (type == "C") {
            return std::make_shared<NyPizzaTypeC>();
        }

        throw std::string("No Type " + type);
    }
};

struct ChicagoPizzaStore : public PizzaStore {
    ChicagoPizzaStore() { name = "ChicagoPizzaStore"; }

    std::shared_ptr<Pizza> createPizza(string type) {
        if (type == "A") {
            return std::make_shared<ChicagoPizzaTypeA>();
        } else if (type == "B") {
            return std::make_shared<ChicagoPizzaTypeB>();
        } else if (type == "C") {
            return std::make_shared<ChicagoPizzaTypeC>();
        }

        throw std::string("No Type " + type);
    }
};

int main(void) {

    try {
        // 从 NY 披萨店预订 A 类型披萨
        std::shared_ptr<PizzaStore> store1 = std::make_shared<NyPizzaStore>();
        std::shared_ptr<Pizza> pizza1 = store1->orderPizza("A");
        cout << "get pizza " << pizza1->getName() << " from "
             << store1->getName() << endl;

        // 从 Chicago 披萨店预订 C 类披萨
        std::shared_ptr<PizzaStore> store2 =
            std::make_shared<ChicagoPizzaStore>();
        std::shared_ptr<Pizza> pizza2 = store2->orderPizza("C");
        cout << "get pizza " << pizza2->getName() << " from "
             << store2->getName() << endl;

        // 从 NY 披萨店预订 D 类披萨
        std::make_shared<NyPizzaStore>()->orderPizza("D");

    } catch (const std::string &e) {
        cout << e << endl;
    }

    return 0;
}
