#include <bits/stdc++.h>
using namespace std;

class Visitor;
using VisitorPtr = std::shared_ptr<Visitor>;

// 元素接口
class MenuItem {
  public:
    virtual void accept(VisitorPtr) = 0;
    virtual string &getName() = 0;
    virtual double getHealthRating() = 0;
    virtual double getCalories() = 0;
};
using MenuItemPtr = std::shared_ptr<MenuItem>;

// 具体元素类
class XiHongShi : public MenuItem,
                  public std::enable_shared_from_this<XiHongShi> {
    string m_name = "XiHongShi";
    double m_health_rating = 0.9;
    double m_calories = 19;

  public:
    void accept(VisitorPtr ptr) override final;
    string &getName() override final { return m_name; }
    double getHealthRating() override final { return m_health_rating; }
    double getCalories() override final { return m_calories; }
};
using XiHongShiPtr = std::shared_ptr<XiHongShi>;

class TuDou : public MenuItem, public std::enable_shared_from_this<TuDou> {
    string m_name = "TuDou";
    double m_health_rating = 0.85;
    double m_calories = 80;

  public:
    void accept(VisitorPtr) override final;
    string &getName() override final { return m_name; }
    double getHealthRating() override final { return m_health_rating; }
    double getCalories() override final { return m_calories; }
};
using TuDouPtr = std::shared_ptr<TuDou>;

class CaiHua : public MenuItem, public std::enable_shared_from_this<CaiHua> {
    string m_name = "CaiHua";
    double m_health_rating = 0.95;
    double m_calories = 20;

  public:
    void accept(VisitorPtr) override final;
    string &getName() override final { return m_name; }
    double getHealthRating() override final { return m_health_rating; }
    double getCalories() override final { return m_calories; }
};
using CaiHuaPtr = std::shared_ptr<CaiHua>;

// 访问者接口
class Visitor {
  public:
    virtual void visit(XiHongShiPtr) = 0;
    virtual void visit(TuDouPtr) = 0;
    virtual void visit(CaiHuaPtr) = 0;
    virtual string &getName() = 0;
};

// 具体访问者类
class HealthRatingVisitor : public Visitor {
    string m_name = "HealthRatingVisitor";

  public:
    void visit(XiHongShiPtr ptr) override final {
        cout << ptr->getName() << ": " << ptr->getHealthRating() << endl;
    }
    void visit(TuDouPtr ptr) override final {
        cout << ptr->getName() << ": " << ptr->getHealthRating() << endl;
    }
    void visit(CaiHuaPtr ptr) override final {
        cout << ptr->getName() << ": " << ptr->getHealthRating() << endl;
    }
    string &getName() override final { return m_name; }
};
using HealthRatingVisitorPtr = std::shared_ptr<HealthRatingVisitor>;

class CaloriesVisitor : public Visitor {
    string m_name = "CaloriesVisitor";

  public:
    void visit(XiHongShiPtr ptr) override final {
        cout << ptr->getName() << ": " << ptr->getCalories() << endl;
    }
    void visit(TuDouPtr ptr) override final {
        cout << ptr->getName() << ": " << ptr->getCalories() << endl;
    }
    void visit(CaiHuaPtr ptr) override final {
        cout << ptr->getName() << ": " << ptr->getCalories() << endl;
    }
    string &getName() override final { return m_name; }
};
using CaloriesVisitorPtr = std::shared_ptr<CaloriesVisitor>;

void XiHongShi::accept(VisitorPtr visitor) {
    visitor->visit(shared_from_this());
}
void TuDou::accept(VisitorPtr visitor) { visitor->visit(shared_from_this()); }
void CaiHua::accept(VisitorPtr visitor) { visitor->visit(shared_from_this()); }

// 组合元素类
class Menu {
    unordered_map<string, MenuItemPtr> m_umap;

  public:
    void addItem(MenuItemPtr item) { m_umap[item->getName()] = item; }
    void removeItem(string &&name) {
        if (!m_umap.count(name)) {
            throw std::string("no item in menu");
        }
        m_umap.erase(name);
    }

    void accept(VisitorPtr visitor) {
        for (auto &it : m_umap) {
            it.second->accept(visitor);
        }
    }
};
using MenuPtr = std::shared_ptr<Menu>;

int main(void) {
    // 创建菜单项
    MenuItemPtr xihongshi = std::make_shared<XiHongShi>();
    MenuItemPtr tudo = std::make_shared<TuDou>();
    MenuItemPtr caihua = std::make_shared<CaiHua>();

    // 创建菜单
    MenuPtr menu = std::make_shared<Menu>();
    menu->addItem(xihongshi);
    menu->addItem(tudo);
    menu->addItem(caihua);

    // 创建访问者
    cout << "=== headth rating visitor ===" << endl;
    VisitorPtr health_rating_visitor = std::make_shared<HealthRatingVisitor>();
    menu->accept(health_rating_visitor);

    cout << "=== calories visitor ===" << endl;
    VisitorPtr calories_visitor = std::make_shared<CaloriesVisitor>();
    menu->accept(calories_visitor);

    return 0;
}
