#include <bits/stdc++.h>
using namespace std;

class Shape {
    int uniform{};

  protected:
    void setUniform(int uni) { uniform = uni; }

  public:
    // 模拟复杂逻辑
    void calUniform(int num) {
        if (num < 0) {
            uniform = -1;
        } else if (num == 0) {
            uniform = 0;
        } else {
            uniform = 1;
        }
    }
    int getUniform() { return uniform; }
    virtual std::shared_ptr<Shape> clone() = 0;
    virtual void draw() = 0;
};
using ShapePtr = std::shared_ptr<Shape>;

class CumberCircle : public Shape,
                     public std::enable_shared_from_this<CumberCircle> {
    string m_type = "circle";

  public:
    CumberCircle() {}
    CumberCircle(std::shared_ptr<CumberCircle> ptr) {
        setUniform(ptr->getUniform());
    }
    ShapePtr clone() override final {
        // 调用拷贝构造函数拷贝当前对象
        return std::make_shared<CumberCircle>(shared_from_this());
    }
    void draw() override final {
        cout << "Draw a circle with num " << getUniform() << "." << endl;
    }
};
class CumberTriangle : public Shape,
                       public std::enable_shared_from_this<CumberTriangle> {
    string m_type = "triangle";

  public:
    CumberTriangle() {}
    CumberTriangle(std::shared_ptr<CumberTriangle> ptr) {
        setUniform(ptr->getUniform());
    }
    ShapePtr clone() override final {
        return std::make_shared<CumberTriangle>(shared_from_this());
    }
    void draw() override final {
        cout << "Draw a triangle with num " << getUniform() << "." << endl;
    }
};

class Taker {
    unordered_map<int, ShapePtr> umap;

  public:
    void setShape(int id, ShapePtr ptr) { umap[id] = ptr; }
    ShapePtr getShape(int id) {
        if (!umap.count(id)) {
            throw std::string("no shape with id ") + to_string(id);
        }
        return umap[id]->clone();
    }
};
using TakerPtr = std::shared_ptr<Taker>;

int main(int argc, char *argv[]) {
    // 每次设置 uniform 都需要复杂的逻辑，则直接克隆一个使用
    TakerPtr taker = std::make_shared<Taker>();
    ShapePtr circle = std::make_shared<CumberCircle>();
    circle->calUniform(-10);
    taker->setShape(111, circle);

    // 使用克隆的对象
    ShapePtr circle2 = taker->getShape(111);
    cout << "use_count: " << circle2.use_count() << endl;
    cout << "uniform: " << circle2->getUniform() << endl;

    return 0;
}
