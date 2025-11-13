#include <bits/stdc++.h>
using namespace std;

// 组件，在以下例子中，组件可以是菜单或者是菜单项
// 组件中的方法都是默认行为，当继承时覆盖各自有用的方法
class MenuComponent {
    string m_name;
    string m_description;

  public:
    MenuComponent(string &&name, string &&description)
        : m_name(std::move(name)), m_description(std::move(description)) {}
    virtual string getName() { // menu, menuItem
        return m_name;
    }
    virtual string getDescription() { // menu, menuItem
        return m_description;
    }
    virtual void print() { // menu, menuItem
        throw std::string("no support print()");
    }
    virtual void add(std::shared_ptr<MenuComponent> comp) { // menu

        throw std::string("no support add()");
    }
    virtual void remove(std::shared_ptr<MenuComponent> comp) { // menu

        throw std::string("no support remove()");
    }
    virtual std::shared_ptr<MenuComponent> getChild(int i) { // menu
        throw std::string("no support getChild()");
    }
    virtual double getPrice() { // menuItem

        throw std::string("no support getPrice()");
    }
    virtual bool isVegetarian() { // menuItem

        throw std::string("no support isVegetarian()");
    }
};
using menuComponentPtr = std::shared_ptr<MenuComponent>;

// 菜单
class Menu : public MenuComponent {
    vector<menuComponentPtr> m_vec;

  public:
    Menu(string &&name, string &&description)
        : MenuComponent(std::move(name), std::move(description)) {}
    void print() override final { // menu, menuItem
        cout << ">>>>> Menu <<<<<" << endl;
        cout << "-- name: " << getName() << endl;
        cout << "-- description: " << getDescription() << endl;
        for (auto &ptr : m_vec) { // 递归调用
            ptr->print();
        }
    }

    void add(menuComponentPtr comp) override final { // menu
        m_vec.push_back(comp);
    }
    void remove(menuComponentPtr comp) override final { // menu
        for (int i = 0; i < m_vec.size(); i++) {
            auto &ptr = m_vec[i];
            if (ptr->getName() == comp->getName() &&
                ptr->getDescription() == comp->getDescription()) {
                m_vec.erase(m_vec.begin() + i);
                break;
            }
        }
    }
    std::shared_ptr<MenuComponent> getChild(int i) override final { // menu
        if (i < 0 || i > m_vec.size() - 1) {
            throw std::string("index over size");
        }
        return m_vec[i];
    }
};
using menuPtr = std::shared_ptr<Menu>;

// 菜单项
class MenuItem : public MenuComponent {
    bool m_isVegetarian;
    double m_price;

  public:
    MenuItem(string &&name, string &&description, bool vegetarian, double price)
        : MenuComponent(std::move(name), std::move(description)),
          m_isVegetarian(vegetarian), m_price(price) {}
    void print() override final { // menu, menuItem
        cout << ">>> MenuItem <<<" << endl;
        cout << "-- name: " << getName() << endl;
        cout << "-- description: " << getDescription() << endl;
        cout << "-- isVegetarian: " << isVegetarian() << endl;
        cout << "-- getPrice: " << getPrice() << endl;
    }

    double getPrice() override final { // menuItem
        return m_price;
    }
    bool isVegetarian() override final { // menuItem
        return m_isVegetarian;
    }
};
using menuItemPtr = std::shared_ptr<MenuItem>;

class Waitress {
    menuComponentPtr allMenus;

  public:
    Waitress(menuComponentPtr ptr) : allMenus(ptr) {}
    void printMenu() { allMenus->print(); }
};
using waitressPtr = std::shared_ptr<Waitress>;

int main(void) {
    // 创建菜单
    menuComponentPtr pancakeHouseMenu =
        std::make_shared<Menu>("PANCAKE HOUSE MENU", "Breakfast");
    pancakeHouseMenu->add(
        std::make_shared<MenuItem>("Breakfast1", "type1", true, 2.99));
    pancakeHouseMenu->add(
        std::make_shared<MenuItem>("Breakfast2", "type2", false, 2.99));
    pancakeHouseMenu->add(
        std::make_shared<MenuItem>("Breakfast3", "type3", true, 3.49));

    menuComponentPtr dinerMenu = std::make_shared<Menu>("DINER MENU", "Lunch");
    dinerMenu->add(std::make_shared<MenuItem>("Lunch1", "type1", true, 3.49));
    dinerMenu->add(std::make_shared<MenuItem>("Lunch2", "type2", false, 2.99));
    dinerMenu->add(std::make_shared<MenuItem>("Lunch3", "type3", false, 3.29));

    menuComponentPtr cafeMenu = std::make_shared<Menu>("CAFE MENU", "Dinner");
    cafeMenu->add(std::make_shared<MenuItem>("Dinner1", "type1", true, 3.99));
    cafeMenu->add(std::make_shared<MenuItem>("Dinner2", "type2", false, 3.69));
    cafeMenu->add(std::make_shared<MenuItem>("Dinner3", "type3", true, 4.29));

    menuComponentPtr dessertMenu =
        std::make_shared<Menu>("DESSERT MENU", "Dessert");
    dessertMenu->add(
        std::make_shared<MenuItem>("Dessert", "type1", true, 1.59));

    dinerMenu->add(dessertMenu); // 附加子菜单

    // 所有菜单的组合
    menuComponentPtr allMenus =
        std::make_shared<Menu>("ALL MENUS", "all menus");
    allMenus->add(pancakeHouseMenu);
    allMenus->add(dinerMenu);
    allMenus->add(cafeMenu);

    // 招待员
    waitressPtr wptr = std::make_shared<Waitress>(allMenus);
    wptr->printMenu();

    return 0;
}
