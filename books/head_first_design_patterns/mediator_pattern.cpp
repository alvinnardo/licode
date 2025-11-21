#include <bits/stdc++.h>
using namespace std;

// 同事类接口
class User {
    string name;

  public:
    User(string &&nm) : name(std::move(nm)) {}
    virtual void send() = 0;
    virtual void receive() = 0;
    string &getName() { return name; }
};
using UserPtr = std::shared_ptr<User>;

// 中介者接口
class AbstractMediator {
  public:
    virtual void registerMember(UserPtr) = 0; // 注册成员
    virtual void removeMember(UserPtr) = 0;   // 删除成员
    virtual void reply(const string &) = 0;   // 回应请求
};

// 中介者
class Mediator : public AbstractMediator {
    vector<UserPtr> m_member;

  public:
    void registerMember(UserPtr ptr) override final { m_member.push_back(ptr); }
    void removeMember(UserPtr ptr) override final {
        for (auto it = m_member.begin(); it != m_member.end(); it++) {
            if ((*it)->getName() == ptr->getName()) {
                m_member.erase(it);
            }
        }
    }
    void reply(const string &name) override final {
        for (auto &member : m_member) {
            if (member->getName() != name) {
                member->receive();
            }
        }
    }
};
using MediatorPtr = std::shared_ptr<Mediator>;

// 同事类
class Friends : public User {
    MediatorPtr m_mediator;

  public:
    Friends(MediatorPtr mediator, string &&name)
        : User(std::move(name)), m_mediator(mediator) {}
    void send() override final {
        cout << getName() << " send" << endl;
        m_mediator->reply(getName());
    }
    void receive() override final { cout << getName() << " receive" << endl; }
};

int main(void) {
    MediatorPtr mediator = std::make_shared<Mediator>();
    UserPtr user1 = std::make_shared<Friends>(mediator, "user1");
    UserPtr user2 = std::make_shared<Friends>(mediator, "user2");
    UserPtr user3 = std::make_shared<Friends>(mediator, "user3");
    mediator->registerMember(user1);
    mediator->registerMember(user2);
    mediator->registerMember(user3);

    // 一个用户发送，中介者收到后向其他用户发送
    user1->send();
    user2->send();
    user3->send();

    return 0;
}
