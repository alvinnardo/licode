#include <bits/stdc++.h>
using namespace std;

// 享元接口
class TreeInterface {
  public:
    virtual void setX(int) = 0;
    virtual void setY(int) = 0;
    virtual void setSize(int) = 0;
    virtual void draw() = 0;
};

// 具体享元类
class Tree : public TreeInterface {
    string m_color;             // 内部状态
    int m_x{}, m_y{}, m_size{}; // 外部状态
  public:
    Tree(const string &color) { m_color = color; }
    void setX(int x) { m_x = x; }
    void setY(int y) { m_y = y; }
    void setSize(int sz) { m_size = sz; }
    void draw() override final {
        cout << "draw a " << m_color << " tree with " << m_size << " size, at ("
             << m_x << ", " << m_y << ")" << endl;
    }
};
using TreePtr = std::shared_ptr<Tree>;

// 享元工厂类
class TreeFactory {
    // 相同颜色的只保留一个对象
    std::unordered_map<string, TreePtr> umap;

  public:
    TreePtr createTree(string &&color) {
        if (!umap.count(color)) {
            umap[color] = std::make_shared<Tree>(color);
        }
        return umap[color];
    }
};
using TreeFactoryPtr = std::shared_ptr<TreeFactory>;

int main(void) {

    TreeFactoryPtr factory = std::make_shared<TreeFactory>();
    // 获取一棵红树，配置大小和位置
    auto tree1 = factory->createTree("red");
    tree1->setSize(10);
    tree1->setX(1);
    tree1->setY(2);
    tree1->draw();

    // 获取一棵红树，配置大小和位置
    // 其实返回的是同一个对象，只改变外部接口即可，节省内存
    auto tree2 = factory->createTree("red");
    tree2->setSize(20);
    tree2->setX(3);
    tree2->setY(4);
    tree2->draw();

    return 0;
}
