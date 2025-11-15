#include <bits/stdc++.h>
using namespace std;

// 代理模式类似装饰器模式，但目的不同，代理模式主要是做访问控制
// 共同接口
class Person {
  public:
    // setter 接口提供个人信息的修改
    virtual void setName(string &&) = 0;
    virtual void setAge(int) = 0;
    virtual void setGender(char) = 0;
    virtual void setInterests(string &&) = 0;
    virtual void setRate(double) = 0;
    virtual string getName() = 0;
    virtual int getAge() = 0;
    virtual char getGender() = 0;
    virtual string getInterests() = 0;
    virtual double getAvgRate() = 0; // 获取平均分
};
using personPtr = std::shared_ptr<Person>;

// 个人信息类
class PersonImpl : public Person {
    string m_name;
    int m_age{};
    char m_gender{'m'};
    string m_interests;
    double m_rate{};
    int m_rate_count{};

  public:
    PersonImpl(string &&name, int age, char gender, string &&interests)
        : m_name(std::move(name)), m_age(age), m_gender(gender),
          m_interests(std::move(interests)) {}

    void setName(string &&name) override final { m_name = std::move(name); }
    void setAge(int age) override final { m_age = age; }
    void setGender(char gender) override final { m_gender = gender; }
    void setInterests(string &&interests) override final {
        m_interests = std::move(interests);
    }
    void setRate(double rate) override final {
        m_rate += rate;
        m_rate_count++;
    }

    string getName() { return m_name; }
    int getAge() { return m_age; }
    char getGender() { return m_gender; }
    string getInterests() { return m_interests; }
    double getAvgRate() { return m_rate / m_rate_count; }
};

using personImplPtr = std::shared_ptr<PersonImpl>;

// 个人信息代理类
// 信息拥有者代理，可以修改个人信息，但不能添加评分
// 非信息拥有者代理，不可以修改个人信息，但可以添加评分和获取评分
class OwnerPersonProxy : public Person {
    personPtr m_person;

  public:
    OwnerPersonProxy(personPtr person) : m_person(person) {}
    void setName(string &&name) { m_person->setName(std::move(name)); }
    void setAge(int age) { m_person->setAge(age); }
    void setGender(char gender) { m_person->setGender(gender); }
    void setInterests(string &&interests) {
        m_person->setInterests(std::move(interests));
    }
    void setRate(double rate) {
        throw std::string("Invalid privilege, cannot set rate.");
    }

    string getName() { return m_person->getName(); }
    int getAge() { return m_person->getAge(); }
    char getGender() { return m_person->getGender(); }
    string getInterests() { return m_person->getInterests(); }
    double getAvgRate() { return m_person->getAvgRate(); } // 获取平均分
};

class NoOwnerPersonProxy : public Person {
    personPtr m_person;

  public:
    NoOwnerPersonProxy(personPtr person) : m_person(person) {}
    void setName(string &&name) {
        throw std::string("Invalid privilege, cannot set name.");
    }
    void setAge(int age) {
        throw std::string("Invalid privilege, cannot set age.");
    }
    void setGender(char gender) {
        throw std::string("Invalid privilege, cannot set gender.");
    }
    void setInterests(string &&interests) {
        throw std::string("Invalid privilege, cannot set interests.");
    }
    void setRate(double rate) { m_person->setRate(rate); }

    string getName() { return m_person->getName(); }
    int getAge() { return m_person->getAge(); }
    char getGender() { return m_person->getGender(); }
    string getInterests() { return m_person->getInterests(); }
    double getAvgRate() { return m_person->getAvgRate(); } // 获取平均分
};

int main(void) {

    personPtr joe_info =
        std::make_shared<PersonImpl>("Joe", 22, 'm', "jogging");
    personPtr owner_proxy = std::make_shared<OwnerPersonProxy>(joe_info);
    try {
        cout << "get age: " << owner_proxy->getAge() << endl;
        cout << "set age: 23" << endl;
        owner_proxy->setAge(23);
        cout << "get age: " << owner_proxy->getAge() << endl;

        cout << "set rate: 8" << endl;
        owner_proxy->setRate(8);
    } catch (std::string &e) {
        cout << "owner proxy error: " << e << endl;
    }

    personPtr others_proxy = std::make_shared<NoOwnerPersonProxy>(joe_info);
    try {
        cout << "set rate: add 8" << endl;
        others_proxy->setRate(8);
        cout << "set rate: add 9" << endl;
        others_proxy->setRate(9);
        cout << "get avg rate: " << others_proxy->getAvgRate() << endl;

        cout << "get age: " << others_proxy->getAge() << endl;
        cout << "set age: 24" << endl;
        others_proxy->setAge(24);

    } catch (std::string &e) {
        cout << "no owner proxy error: " << e << endl;
    }

    return 0;
}
