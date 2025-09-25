#include <iostream>
#include <memory>
using namespace std;

// 用来产原料的工厂
class IngredientFactory {
    string fac_name;

  public:
    // 每一个方法创建一类对象
    virtual string createIn1() const = 0;
    virtual string createIn2() const = 0;
    void setName(string name) { fac_name = name; }
    string getName() const { return fac_name; }
};

class NyIngredientFactory : public IngredientFactory {
  public:
    NyIngredientFactory() { setName("Ny Ingredient Factory"); }
    string createIn1() const override { return "Ny In1"; }
    string createIn2() const override { return "Ny In2"; }
};

class ChicagoIngredientFactory : public IngredientFactory {
  public:
    ChicagoIngredientFactory() { setName("Chicago Ingredient Factory"); }
    string createIn1() const override { return "Chicago In1"; }
    string createIn2() const override { return "Chicago In2"; }
};

// 披萨类
class Pizza {
    string name;

    // 这里每一种调料也是用类实现，这里简单用字符串表示了
    string in1;
    string in2;

    // 组合实现抽象工厂方法

  public:
    std::shared_ptr<IngredientFactory> m_fac_ptr;
    Pizza(std::shared_ptr<IngredientFactory> ptr) : m_fac_ptr(ptr) {}
    void prepare() {
        in1 = m_fac_ptr->createIn1();
        in2 = m_fac_ptr->createIn2();
    }
    void setName(string name) { this->name = name; }
    string getName() const { return this->name; }
    string getFacName() const { return m_fac_ptr->getName(); }
    void make() { cout << "making pizza ..." << endl; }
};

class CheessPizza : public Pizza {
  public:
    CheessPizza(std::shared_ptr<IngredientFactory> ptr) : Pizza(ptr) {
        setName("Cheese Pizza");
    }
};

class PeperPizza : public Pizza {
  public:
    PeperPizza(std::shared_ptr<IngredientFactory> ptr) : Pizza(ptr) {
        setName("Peper Pizza");
    }
};

// 披萨商店类
class PizzaStore {
  public:
    std::shared_ptr<Pizza> orderPizza(string type) {
        std::shared_ptr<Pizza> pizza = createPizza(type);
        pizza->make();
        cout << "Order a " << type << " pizza with " << pizza->getFacName()
             << endl;
        return pizza;
    }

    // 工厂方法模式
    virtual std::shared_ptr<Pizza> createPizza(string type) = 0;
};

class NyPizzaStore : public PizzaStore {
  public:
    std::shared_ptr<Pizza> createPizza(string type) {
        // 创建 NY 本地的材料工厂
        std::shared_ptr<IngredientFactory> inptr =
            std::make_shared<NyIngredientFactory>();
        if (type == "cheese") {
            return std::make_shared<CheessPizza>(inptr);
        } else if (type == "peper") {
            return std::make_shared<PeperPizza>(inptr);
        }

        throw string("no " + type + " pizza in NyPizzaStore");
        return 0;
    }
};

int main(void) {
    std::shared_ptr<PizzaStore> psstr = std::make_shared<NyPizzaStore>();
    psstr->orderPizza("cheese");

    return 0;
}
