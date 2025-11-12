#include <bits/stdc++.h>
using namespace std;

// 菜单项
class MenuItem {
    string m_name;
    string m_description;
    bool m_vegetarian;
    double m_price;

  public:
    MenuItem(string &&name) {};
    MenuItem(string &&name, string &&description, bool vegetarian, double price)
        : m_name(std::move(name)), m_description(std::move(description)),
          m_vegetarian(vegetarian), m_price(price) {}

    string getName() { return m_name; }
    string getDescription() { return m_description; }
    bool getVegetarien() { return m_vegetarian; }
    double getPrice() { return m_price; }
    void output() {
        cout << m_name << ", " << m_description << ", " << m_vegetarian << ", "
             << m_price << endl;
    }
};
using MiPtr = std::shared_ptr<MenuItem>;

// 迭代器接口
class Iterator {
  public:
    virtual bool hasNext() = 0;
    virtual MiPtr next() = 0;
};
using IteratorPtr = std::shared_ptr<Iterator>;

class ListIterator : public Iterator {
    list<MiPtr> m_list;
    list<MiPtr>::iterator m_it;

  public:
    ListIterator(auto &list) : m_list(list), m_it(m_list.begin()) {}

    bool hasNext() override final { return m_it != m_list.end(); }
    MiPtr next() override final {
        if (!hasNext()) {
            throw std::string("no next value");
        }

        auto &val = *m_it;
        m_it++;
        return val;
    }
};
using ListIteratorPtr = std::shared_ptr<ListIterator>;

class VectorIterator : public Iterator {
    vector<MiPtr> m_vec;
    int m_cur = -1; // 上次返回的位置

  public:
    VectorIterator(auto &vec) : m_vec(vec) {}

    bool hasNext() override final { return m_cur != m_vec.size() - 1; }
    MiPtr next() override final {
        if (!hasNext()) {
            throw std::string("no next value");
        }

        return m_vec[++m_cur];
    }
};
using VectorIteratorPtr = std::shared_ptr<VectorIterator>;

class HashIterator : public Iterator {
    unordered_map<string, MiPtr> m_umap;
    unordered_map<string, MiPtr>::iterator m_it;

  public:
    HashIterator(auto &umap) : m_umap(umap), m_it(m_umap.begin()) {}

    bool hasNext() override final { return m_it != m_umap.end(); }
    MiPtr next() override final {
        if (!hasNext()) {
            throw std::string("no next value");
        }

        auto &val = *m_it;
        m_it++;
        return val.second;
    }
};

// 菜单接口
class Menu {
    string menu_name;

  public:
    Menu(string &&name) : menu_name(name) {}
    virtual IteratorPtr createIterator() = 0;
    virtual void addItem(string &&name, string &&description, bool vegetarian,
                         double price) = 0;

    string &getName() { return menu_name; }
};
using MenuPtr = std::shared_ptr<Menu>;

class ListMenu : public Menu {
    list<MiPtr> menu_list;

  public:
    ListMenu(string &&name) : Menu(std::move(name)) {
        addItem("Breakfast1", "type1", true, 2.99);
        addItem("Breakfast2", "type2", false, 2.99);
        addItem("Breakfast3", "type3", true, 3.49);
    }

    IteratorPtr createIterator() { // 使用菜单创建一个迭代器
        return std::make_shared<ListIterator>(menu_list);
    }

    void addItem(string &&name, string &&description, bool vegetarian,
                 double price) override final {
        // 右值引用是左值，用 std::move 转为右值
        menu_list.push_back(std::make_shared<MenuItem>(
            std::move(name), std::move(description), vegetarian, price));
    }
};
using ListMenuPtr = std::shared_ptr<ListMenu>;

class VectorMenu : public Menu {
    vector<MiPtr> menu_vec;
    int m_size = 5;
    string menu_name;

  public:
    VectorMenu(string &&name) : Menu(std::move(name)) {
        addItem("Lunch1", "type1", true, 2.99);
        addItem("Lunch2", "type2", false, 2.99);
        addItem("Lunch3", "type3", false, 3.29);
    }

    IteratorPtr createIterator() {
        return std::make_shared<VectorIterator>(menu_vec);
    }

    void addItem(string &&name, string &&description, bool vegetarian,
                 double price) override final {
        if (menu_vec.size() == m_size) {
            throw std::string("menu is oversize");
        }

        menu_vec.push_back(std::make_shared<MenuItem>(
            std::move(name), std::move(description), vegetarian, price));
    }
};
using VectorMenuPtr = std::shared_ptr<VectorMenu>;

class HashMenu : public Menu {
    unordered_map<string, MiPtr> menu_umap;
    string menu_name;

  public:
    HashMenu(string &&name) : Menu(std::move(name)) {
        addItem("Dinner1", "type1", true, 3.99);
        addItem("Dinner2", "type2", false, 3.69);
        addItem("Dinner3", "type3", true, 4.29);
    }

    IteratorPtr createIterator() {
        return std::make_shared<HashIterator>(menu_umap);
    }

    void addItem(string &&name, string &&description, bool vegetarian,
                 double price) override final {
        string tname{name}; // 后面 move 走了，这里保存临时量
        menu_umap[std::move(tname)] = std::make_shared<MenuItem>(
            std::move(name), std::move(description), vegetarian, price);
    }
};

// 服务员，即调用者
class Waitress {
    MenuPtr breakfast_menu, lunch_menu, dinner_menu;

    void printSingleMenu(auto &menu) {
        cout << ">>>>> " << menu->getName() << " <<<<<" << endl;

        auto iter = menu->createIterator();
        while (iter->hasNext()) {
            iter->next()->output();
        }
    }

  public:
    Waitress(auto &menu1, auto &menu2, auto &menu3)
        : breakfast_menu(menu1), lunch_menu(menu2), dinner_menu(menu3) {}

    // 打印合并后的菜单
    void printMenu() {
        printSingleMenu(breakfast_menu);
        printSingleMenu(lunch_menu);
        printSingleMenu(dinner_menu);
    }

    // 只打印早餐菜单
    void printBreakfastMenu() { printSingleMenu(breakfast_menu); }
    // 只打印午餐菜单
    void printLunchMenu() { printSingleMenu(lunch_menu); }
    // 只打印晚餐菜单
    void printDinnerMenu() { printSingleMenu(dinner_menu); }
};
using WaitPtr = std::shared_ptr<Waitress>;

int main(int argc, char *argv[]) {

    MenuPtr breakfast_menu = std::make_shared<ListMenu>("breakfast_menu");
    MenuPtr lunch_menu = std::make_shared<VectorMenu>("lunch_menu");
    MenuPtr dinner_menu = std::make_shared<HashMenu>("dinner_menu");
    WaitPtr waitress =
        std::make_shared<Waitress>(breakfast_menu, lunch_menu, dinner_menu);

    waitress->printMenu();
    waitress->printBreakfastMenu();
    waitress->printLunchMenu();
    waitress->printDinnerMenu();

    return 0;
}
