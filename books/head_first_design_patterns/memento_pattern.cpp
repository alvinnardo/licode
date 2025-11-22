#include <bits/stdc++.h>
using namespace std;

// 备忘录
class Memento {
    string m_state;

  public:
    Memento(const string &state) : m_state(state) {}
    string &getState() { return m_state; }
};
using MementoPtr = std::shared_ptr<Memento>;

// 备忘录维护者
// 组织成一个哈希表
class MementoTaker {
    unordered_map<string, MementoPtr> m_memento_table;

  public:
    void addMemento(const string &name, MementoPtr ptr) {
        m_memento_table[name] = ptr;
    }
    void removeMemento(const string &name) { m_memento_table.erase(name); }
    MementoPtr getMemento(const string &name) {
        if (!m_memento_table.count(name)) {
            throw std::string("no memento");
        }
        return m_memento_table[name];
    }
};
using MementoTakerPtr = std::shared_ptr<MementoTaker>;

// 游戏类
class Game {
    string m_state;

  public:
    Game() : m_state{"Running"} {}
    void setState(string &&state) { m_state = std::move(state); }
    string &getState() { return m_state; }
    MementoPtr saveMemento() { return std::make_shared<Memento>(m_state); }
    void restoreMemento(MementoPtr memento) { m_state = memento->getState(); }
};
using GamePtr = std::shared_ptr<Game>;

int main(void) {
    // 创建游戏
    GamePtr game = std::make_shared<Game>();
    MementoTakerPtr taker = std::make_shared<MementoTaker>();

    // 备份状态
    taker->addMemento("run", game->saveMemento());

    // 修改状态并再次备份
    game->setState("Stopped");
    cout << "current state: " << game->getState() << endl;

    // 恢复第一次的状态
    cout << "restore state" << endl;
    game->restoreMemento(taker->getMemento("run"));
    cout << "current state: " << game->getState() << endl;

    return 0;
}
