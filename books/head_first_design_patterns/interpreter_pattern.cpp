#include <bits/stdc++.h>
using namespace std;

// 解释器抽象接口
class Expression {
  public:
    virtual int interpret() = 0;
};
using ExpressionPtr = std::shared_ptr<Expression>;

// 终结符
class NumberExpression : public Expression {
    int m_num{};

  public:
    NumberExpression(int num) : m_num(num) {}

    int interpret() override final { return m_num; }
};

// 非终结符
class AddExpression : public Expression {
    ExpressionPtr m_left, m_right;

  public:
    AddExpression(ExpressionPtr left, ExpressionPtr right)
        : m_left(left), m_right(right) {}
    int interpret() override final {
        return m_left->interpret() + m_right->interpret();
    }
};

class SubExpression : public Expression {
    ExpressionPtr m_left, m_right;

  public:
    SubExpression(ExpressionPtr left, ExpressionPtr right)
        : m_left(left), m_right(right) {}
    int interpret() override final {
        return m_left->interpret() - m_right->interpret();
    }
};

class MultiExpression : public Expression {
    ExpressionPtr m_left, m_right;

  public:
    MultiExpression(ExpressionPtr left, ExpressionPtr right)
        : m_left(left), m_right(right) {}
    int interpret() override final {
        return m_left->interpret() * m_right->interpret();
    }
};

class DivExpression : public Expression {
    ExpressionPtr m_left, m_right;

  public:
    DivExpression(ExpressionPtr left, ExpressionPtr right)
        : m_left(left), m_right(right) {}
    int interpret() override final {
        return m_left->interpret() / m_right->interpret();
    }
};

int main(void) {
    ExpressionPtr num1 = std::make_shared<NumberExpression>(20);
    ExpressionPtr num2 = std::make_shared<NumberExpression>(10);
    ExpressionPtr add_num = std::make_shared<AddExpression>(num1, num2);
    ExpressionPtr sub_num = std::make_shared<SubExpression>(num1, num2);
    ExpressionPtr multi_num = std::make_shared<MultiExpression>(num1, num2);
    ExpressionPtr div_num = std::make_shared<DivExpression>(num1, num2);
    cout << num1->interpret() << " + " << num2->interpret() << " = "
         << add_num->interpret() << endl;
    cout << num1->interpret() << " - " << num2->interpret() << " = "
         << sub_num->interpret() << endl;
    cout << num1->interpret() << " * " << num2->interpret() << " = "
         << multi_num->interpret() << endl;
    cout << num1->interpret() << " / " << num2->interpret() << " = "
         << div_num->interpret() << endl;

    return 0;
}
