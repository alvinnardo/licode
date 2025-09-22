#include <iostream>
#include <memory>
#include <unordered_set>
using namespace std;

struct DataCenter;
struct Observer;
// 这里只给出一个 Observer 类
// 如果有其他具体类，可以将其改写
struct Observer {
    std::weak_ptr<DataCenter> center_ptr;
    float temperature{};
    float humidity{};
    float pressure{};

    Observer(std::weak_ptr<DataCenter> ptr);
    void display();
    void update();
    void update(float temperature, float humidity, float pressure);
};

struct DataCenter {
    float temperature{};
    float humidity{};
    float pressure{};
    std::unordered_set<std::shared_ptr<Observer>> uset;

    // 与观察者有关
    void addObserver(std::shared_ptr<Observer> ptr);
    void removeObserver(std::shared_ptr<Observer> ptr);
    void notifyObservers();
    // 外部调用，更改数据中心的数据
    void setData(float temperature, float humidity, float pressure);

    float getTemperature() { return temperature; }
    float getHumidity() { return humidity; }
    float getPressure() { return pressure; }
};

Observer::Observer(std::weak_ptr<DataCenter> ptr) : center_ptr(ptr) {}

void Observer::display() {
    cout << "temperature: " << temperature << ", humidity: " << humidity
         << ", pressure: " << pressure << endl;
};

// 方式 1：推送数据
void Observer::update(float temperature, float humidity, float pressure) {
    this->temperature = temperature;
    this->humidity = humidity;
    this->pressure = pressure;
    display();
};

// 方式 2：拉取数据，更好地方式
void Observer::update() {
    auto ptr = center_ptr.lock();
    if (!ptr) {
        cout << "Failed to get center." << endl;
        return;
    }
    this->temperature = ptr->getTemperature();
    this->humidity = ptr->getHumidity();
    this->pressure = ptr->getPressure();
    display();
};

void DataCenter::addObserver(std::shared_ptr<Observer> ptr) {
    uset.insert(ptr);
}
void DataCenter::removeObserver(std::shared_ptr<Observer> ptr) {
    uset.erase(ptr);
}
void DataCenter::notifyObservers() {
    for (auto &it : uset) {
        // it->update(temperature, humidity, pressure);
        it->update();
    }
}

// 外部调用，更改数据中心的数据
void DataCenter::setData(float temperature, float humidity, float pressure) {
    this->temperature = temperature;
    this->humidity = humidity;
    this->pressure = pressure;
    notifyObservers(); // 通知观察者数据发生改变
}

int main(void) {

    std::shared_ptr<DataCenter> center = std::make_shared<DataCenter>();
    std::shared_ptr<Observer> p1 = std::make_shared<Observer>(center);
    std::shared_ptr<Observer> p2 = std::make_shared<Observer>(center);
    std::shared_ptr<Observer> p3 = std::make_shared<Observer>(center);
    center->addObserver(p1);
    center->addObserver(p2);
    center->addObserver(p3);
    center->setData(1, 2, 3);

    center->removeObserver(p3);
    center->setData(4, 5, 6);

    return 0;
}
