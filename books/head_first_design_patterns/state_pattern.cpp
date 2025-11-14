#include <bits/stdc++.h>
using namespace std;

/**
  定义状态：
  1. 没有硬币
  2. 有硬币
  3. 卖出糖果
  4. 已售罄
  5. 赢家(两枚糖果)

  状态转换：
  1. 没有硬币 -> 有硬币
  2. 有硬币 -> 没有硬币
  3. 有硬币 -> 卖出糖果
  4. 卖出糖果 -> 没有硬币
  5. 卖出糖果 -> 已售罄
  6. 已售罄 -> 没有硬币
  7. 有硬币 -> 赢家
  8. 赢家 -> 没有硬币
  9. 赢家 -> 已售罄
 */
class Machine;
class State;
using machinePtr = std::shared_ptr<Machine>;
using statePtr = std::shared_ptr<State>;

class State {
    machinePtr m_machine;
    string state_name;

  public:
    static int getRandom(int a, int b) {
        std::uniform_int_distribution dist(a, b);
        std::mt19937 gen(std::random_device{}());
        return dist(gen);
    }

    State(string &&name) : state_name(std::move(name)) {}
    void setMachine(machinePtr ptr) { m_machine = ptr; }
    machinePtr getMachine() { return m_machine; }
    string &getStateName() { return state_name; }
    virtual void insertCoin() = 0;   // 投入硬币
    virtual void removeCoin() = 0;   // 取出硬币
    virtual void turnOnButton() = 0; // 按动按钮
    virtual void outputCandy() = 0;  // 吐出糖果
    virtual void refill(int) = 0;    // 重新填装
};

class NoCoinState : public State {
  public:
    NoCoinState(string &&name) : State(std::move(name)) {}
    void insertCoin();
    void removeCoin();
    void turnOnButton();
    void outputCandy();
    void refill(int);
};

class HasCoinState : public State {
  public:
    HasCoinState(string &&name) : State(std::move(name)) {}
    void insertCoin();
    void removeCoin();
    void turnOnButton();
    void outputCandy();
    void refill(int);
};

class SoldState : public State {
  public:
    SoldState(string &&name) : State(std::move(name)) {}
    void insertCoin();
    void removeCoin();
    void turnOnButton();
    void outputCandy();
    void refill(int);
};

class SoldOutState : public State {
  public:
    SoldOutState(string &&name) : State(std::move(name)) {}
    void insertCoin();
    void removeCoin();
    void turnOnButton();
    void outputCandy();
    void refill(int);
};

class WinnerState : public State {
  public:
    WinnerState(string &&name) : State(std::move(name)) {}
    void insertCoin();
    void removeCoin();
    void turnOnButton();
    void outputCandy();
    void refill(int);
};

// std::enable_shared_from_this 内部有一个 weak_ptr，指向当前对象的 this 指针
// 在内部调用 shared_from_this() 就能返回 shared_ptr
class Machine : public std::enable_shared_from_this<Machine> {
    statePtr no_coin_state = std::make_shared<NoCoinState>("NoCoinState");
    statePtr has_coin_state = std::make_shared<HasCoinState>("HasCoinState");
    statePtr sold_state = std::make_shared<SoldState>("SoldState");
    statePtr sold_out_state = std::make_shared<SoldOutState>("SoldOutState");
    statePtr winner_state = std::make_shared<WinnerState>("WinnerState");

    statePtr cur_state = sold_out_state;
    int m_candy_num{};

  public:
    Machine(int num) {
        cout << ">>>>> INIT MACHINE <<<<<" << endl;
        if (num < 0) {
            throw std::string("number of coins is invalid");
        } else if (num == 0) {
            cout << "NO CANDY, INTO SOLD_OUT_STATE." << endl;
            cur_state = sold_out_state;
        } else {
            cout << "PUT " << num << " CANDIES, INTO NO_COIN_STATE" << endl;
            cur_state = no_coin_state;
            m_candy_num = num;
        }
    }

    void setStateMachine() {
        has_coin_state->setMachine(shared_from_this());
        no_coin_state->setMachine(shared_from_this());
        sold_state->setMachine(shared_from_this());
        sold_out_state->setMachine(shared_from_this());
        winner_state->setMachine(shared_from_this());
    }

    void insertCoin() { cur_state->insertCoin(); }
    void removeCoin() { cur_state->removeCoin(); }
    void turnOnButton() {
        cur_state->turnOnButton();
        cur_state->outputCandy();
    }

    // getter and setter
    int getCandyNum() { return m_candy_num; }
    void setCandyNum(int num) { m_candy_num = num; }

    statePtr getCurState() { return cur_state; }
    statePtr getNoCoinState() { return no_coin_state; }
    statePtr getHasCoinState() { return has_coin_state; }
    statePtr getSoldState() { return sold_state; }
    statePtr getSoldOutState() { return sold_out_state; }
    statePtr getWinnerState() { return winner_state; }
    void setCurState(statePtr ptr) { cur_state = ptr; }

    void outputCurStateInfo() {
        cout << "Machine is in " << cur_state->getStateName()
             << " now, and has " << m_candy_num << " candi(es)." << endl;
    }
};

void NoCoinState::insertCoin() {
    cout << "Insert a Coin." << endl;
    auto ptr = getMachine();
    ptr->setCurState(ptr->getHasCoinState());
}
void NoCoinState::removeCoin() {
    cout << "No coin, cannot remove a coin." << endl;
}
void NoCoinState::turnOnButton() {
    cout << "No coin, please insert a coin at first." << endl;
}
void NoCoinState::outputCandy() {
    cout << "Please insert a coin at first." << endl;
}
void NoCoinState::refill(int num) {
    if (num < 0) {
        cout << "Candy number is invalid." << endl;
        return;
    }

    auto ptr = getMachine();
    ptr->setCandyNum(ptr->getCandyNum() + num); // 状态不变
}

void HasCoinState::insertCoin() {
    cout << "Cannot insert coin, mechine already has a coin" << endl;
}
void HasCoinState::removeCoin() {
    cout << "Remove coin success." << endl;
    auto ptr = getMachine();
    ptr->setCurState(ptr->getNoCoinState());
}
void HasCoinState::turnOnButton() {
    cout << "Turn on button." << endl;
    int t = getRandom(1, 10);
    auto ptr = getMachine();
    int num = ptr->getCandyNum();
    if (t == 1 && num > 1) { // 1/10 win
        cout << "Congradulations, you win." << endl;
        ptr->setCurState(ptr->getWinnerState());
    } else {
        cout << "Ready to output a candy." << endl;
        ptr->setCurState(ptr->getSoldState());
    }
}
void HasCoinState::outputCandy() {
    cout << "Please turn on the button at first." << endl;
}
void HasCoinState::refill(int) {
    cout << "Please wait until last operator is finished." << endl;
}

void SoldState::insertCoin() {
    cout << "Cannot insert a coin, please take the candy away." << endl;
}
void SoldState::removeCoin() {
    cout << "Please insert a coin at first." << endl;
}
void SoldState::turnOnButton() {
    cout << "Already turn on, please take the candy away." << endl;
}
void SoldState::outputCandy() {
    cout << "Give one candy." << endl;
    auto ptr = getMachine();
    int num = ptr->getCandyNum();
    ptr->setCandyNum(--num);
    if (num == 0) {
        ptr->setCurState(ptr->getSoldOutState());
    } else {
        ptr->setCurState(ptr->getNoCoinState());
    }
}
void SoldState::refill(int) {
    cout << "Please wait until last operator is finished." << endl;
}

void SoldOutState::insertCoin() {
    cout << "No candy now, please wait patiently." << endl;
}
void SoldOutState::removeCoin() {
    cout << "No coin, cannot remove a coin." << endl;
}
void SoldOutState::turnOnButton() {
    cout << "No coin, please insert a coin at first." << endl;
}
void SoldOutState::outputCandy() {
    cout << "Please insert a coin at first." << endl;
}
void SoldOutState::refill(int num) {
    if (num < 0) {
        cout << "Candy number is invalid." << endl;
        return;
    }

    auto ptr = getMachine();
    ptr->setCandyNum(ptr->getCandyNum() + num);
    ptr->setCurState(ptr->getNoCoinState()); // 状态改变
}

void WinnerState::insertCoin() {
    cout << "Cannot insert a coin, please take the candy away." << endl;
}
void WinnerState::removeCoin() {
    cout << "Please insert a coin at first." << endl;
}
void WinnerState::turnOnButton() {
    cout << "Already turn on, please take the candy away." << endl;
}
void WinnerState::outputCandy() {
    cout << "Give two candy." << endl;
    auto ptr = getMachine();
    int num = ptr->getCandyNum();
    num -= 2;
    ptr->setCandyNum(num);
    if (num == 0) {
        ptr->setCurState(ptr->getSoldOutState());
    } else {
        ptr->setCurState(ptr->getNoCoinState());
    }
}
void WinnerState::refill(int) {
    cout << "Please wait until last operator is finished." << endl;
}

int main(void) {

    // 初始化糖果机，添加 5 颗糖果
    machinePtr candy_machine = std::make_shared<Machine>(5);
    candy_machine->setStateMachine();
    // 测试 shared_from_this() 是否生效
    // cout << candy_machine.use_count() << endl;

    candy_machine->outputCurStateInfo();

    candy_machine->insertCoin();
    candy_machine->turnOnButton();
    candy_machine->outputCurStateInfo();

    candy_machine->insertCoin();
    candy_machine->turnOnButton();
    candy_machine->insertCoin();
    candy_machine->turnOnButton();
    candy_machine->outputCurStateInfo();

    return 0;
}
