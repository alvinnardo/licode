#include <bits/stdc++.h>
#include <thread>
using namespace std;

class Observer {
    string m_name;

  public:
    string getName() { return m_name; }
};

class BeatObserver : public Observer {
  public:
    virtual void updateBeat() = 0;
};

class BPMObserver : public Observer {
  public:
    virtual void updateBPM() = 0;
};

using BeatObserverPtr = std::shared_ptr<BeatObserver>;
using BPMObserverPtr = std::shared_ptr<BPMObserver>;

// 模型
class BeatModelInterface {
  public:
    virtual void initialize() = 0;                      // 初始化
    virtual void on() = 0;                              // 打开节拍器
    virtual void off() = 0;                             // 关闭节拍器
    virtual void setBPM(int bpm) = 0;                   // 设置频率
    virtual int getBPM() = 0;                           // 获取频率
    virtual void registerObserver(BeatObserverPtr) = 0; // 注册节拍观察者
    virtual void removeObserver(BeatObserverPtr) = 0;   // 删除节拍观察者
    virtual void registerObserver(BPMObserverPtr) = 0; // 注册节拍修改事件观察者
    virtual void removeObserver(BPMObserverPtr) = 0; // 删除节拍修改事件观察者
};

class BeatModel : public BeatModelInterface {
    list<BeatObserverPtr> m_beat_observers;
    list<BPMObserverPtr> m_bpm_observers;
    int m_bpm{90};
    std::jthread m_thread;
    bool m_stop{true};
    bool m_finished{true};
    std::mutex m_mutex;

    bool getStop();
    void setStop(bool val);
    bool getFinished();
    void setFinished(bool val);

  public:
    void initialize() override final;
    void on() override final;
    void off() override final;
    void run();

    void setBPM(int bpm) override final;
    int getBPM() override final;

    void registerObserver(BeatObserverPtr ptr) override final;
    void removeObserver(BeatObserverPtr ptr) override final;
    void registerObserver(BPMObserverPtr ptr) override final;
    void removeObserver(BPMObserverPtr ptr) override final;

    void notifyBeatObservers();
    void notifyBPMObservers();
};
using BeatModelPtr = std::shared_ptr<BeatModel>;

class View;
using ViewPtr = std::shared_ptr<View>;
// 控制器
class Controller : public std::enable_shared_from_this<Controller> {
    BeatModelPtr m_model;
    ViewPtr m_view;

  public:
    Controller(BeatModelPtr model);
    void createView();
    void start();
    void stop();
    void setBPM(int bpm);
    void increaseBPM();
    void decreaseBPM();
    ViewPtr getView();
};
using ControllerPtr = std::shared_ptr<Controller>;

// 视图
class View : public BeatObserver,
             public BPMObserver,
             public std::enable_shared_from_this<View> {
    BeatModelPtr m_model;
    ControllerPtr m_controller;

  public:
    View(BeatModelPtr model, ControllerPtr controller);

    void AddObserver();

    void updateBPM() override final;
    void updateBeat() override final;

    // 这里使用组合模式，统一管理组件，这里直接用数字模拟了
    void actionPerformed(int num);
};

// 模型
bool BeatModel::getStop() {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_stop;
}
void BeatModel::setStop(bool val) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_stop = val;
}
bool BeatModel::getFinished() {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_finished;
}
void BeatModel::setFinished(bool val) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_finished = val;
}

void BeatModel::initialize() {}
void BeatModel::on() {
    while (!getStop() || !getFinished()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    setBPM(90); // 重新初始化
    setStop(false);
    m_thread = std::jthread(std::bind(&BeatModel::run, this));
}
void BeatModel::off() {
    cout << "set stop " << endl;
    setStop(true);
}

void BeatModel::run() {
    // 这里会有多线程的问题，比如已经设置为停止但是没有真正停止
    // 所有对 m_stop 和 m_finished 变量加了锁
    while (!getStop()) {
        setFinished(false);
        notifyBeatObservers();
        std::this_thread::sleep_for(
            std::chrono::milliseconds(60000 / getBPM()));
        setFinished(true);
    }
}

void BeatModel::setBPM(int bpm) {
    m_bpm = bpm;
    notifyBPMObservers();
}
int BeatModel::getBPM() { return m_bpm; }

void BeatModel::registerObserver(BeatObserverPtr ptr) {
    m_beat_observers.push_back(ptr);
}
void BeatModel::removeObserver(BeatObserverPtr ptr) {
    auto it = m_beat_observers.begin();
    while (it != m_beat_observers.end()) {
        if ((*it)->getName() == ptr->getName()) {
            m_beat_observers.erase(it);
            break;
        }
    }
}

void BeatModel::registerObserver(BPMObserverPtr ptr) {
    m_bpm_observers.push_back(ptr);
}
void BeatModel::removeObserver(BPMObserverPtr ptr) {
    auto it = m_bpm_observers.begin();
    while (it != m_bpm_observers.end()) {
        if ((*it)->getName() == ptr->getName()) {
            m_bpm_observers.erase(it);
            break;
        }
    }
}

void BeatModel::notifyBeatObservers() {
    for (auto observer : m_beat_observers) {
        observer->updateBeat();
    }
}
void BeatModel::notifyBPMObservers() {
    for (auto observer : m_bpm_observers) {
        observer->updateBPM();
    }
}

// 视图
View::View(BeatModelPtr model, ControllerPtr controller)
    : m_model(model), m_controller(controller) {}

void View::AddObserver() {
    m_model->registerObserver(static_cast<BeatObserverPtr>(shared_from_this()));
    m_model->registerObserver(static_cast<BPMObserverPtr>(shared_from_this()));
}

void View::updateBPM() {
    // 从模型中获取数据，并显示
    int bpm = m_model->getBPM();
    cout << "current BPM: " << bpm << endl;
}

void View::updateBeat() {
    // 显示跳动
    cout << "Beat Beat Beat" << endl;
}

// 这里使用组合模式，统一管理组件，这里直接用数字模拟了
void View::actionPerformed(int num) {
    // 这里模拟填充数字以及增减的两个按钮
    // num < 0，就是减 1
    // num == 0，就是加 1
    // num > 0，就是将数字设置为 num
    if (num < 0) {
        m_controller->decreaseBPM();
    } else if (num == 0) {
        m_controller->increaseBPM();
    } else {
        m_controller->setBPM(num);
    }
}

// 控制器
Controller::Controller(BeatModelPtr model) : m_model(model) {}
void Controller::createView() {
    // 创建视图，并将视图配置为观察者
    m_view = std::make_shared<View>(m_model, shared_from_this());
    m_view->AddObserver();
}

void Controller::start() { m_model->on(); }
void Controller::stop() { m_model->off(); }
void Controller::setBPM(int bpm) { m_model->setBPM(bpm); }
void Controller::increaseBPM() {
    int bpm = m_model->getBPM();
    m_model->setBPM(bpm + 1);
}
void Controller::decreaseBPM() {
    int bpm = m_model->getBPM();
    m_model->setBPM(bpm - 1);
}
ViewPtr Controller::getView() { return m_view; }

int main(void) {

    BeatModelPtr model = std::make_shared<BeatModel>();
    // 控制器中创建视图
    // 视图依赖控制器和模型
    ControllerPtr controller = std::make_shared<Controller>(model);
    controller->createView();
    ViewPtr view = controller->getView();

    controller->start();
    std::this_thread::sleep_for(std::chrono::seconds(10));

    // 模拟在视图上配置新频率
    view->actionPerformed(120);
    std::this_thread::sleep_for(std::chrono::seconds(10));
    controller->stop();

    return 0;
}
