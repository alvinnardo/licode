#include <bits/stdc++.h>
using namespace std;
class AbstractLogger;
using AbstractLoggerPtr = std::shared_ptr<AbstractLogger>;

enum class LOG_TYPE { DEBUG = 1, INFO = 2, ERROR = 3 };
class AbstractLogger {
    AbstractLoggerPtr next_logger;

  protected:
    LOG_TYPE m_level;

  public:
    void setNextLogger(AbstractLoggerPtr ptr) { next_logger = ptr; }
    void logMessage(LOG_TYPE level, string &&message) {
        if (m_level <= level) {
            write(std::move(message));
        } else if (next_logger) {
            next_logger->logMessage(level, std::move(message));
        }
    }
    virtual void write(string &&message) = 0;
};

// 详细程度从高到低
class DebugLogger : public AbstractLogger {
  public:
    DebugLogger() { m_level = LOG_TYPE::DEBUG; }
    void write(string &&message) override final {
        cout << "DEBUG: " << message << endl;
    }
};
class InfoLogger : public AbstractLogger {
  public:
    InfoLogger() { m_level = LOG_TYPE::INFO; }
    void write(string &&message) override final {
        cout << "INFO: " << message << endl;
    }
};
class ErrorLogger : public AbstractLogger {
  public:
    ErrorLogger() { m_level = LOG_TYPE::ERROR; }
    void write(string &&message) override final {
        cout << "ERROR: " << message << endl;
    }
};

int main(void) {
    AbstractLoggerPtr debug_logger = std::make_shared<DebugLogger>();
    AbstractLoggerPtr info_logger = std::make_shared<InfoLogger>();
    AbstractLoggerPtr error_logger = std::make_shared<ErrorLogger>();

    // 创建责任链，按详细程度顺序是 DEBUG, INFO, ERROR
    debug_logger->setNextLogger(info_logger);
    info_logger->setNextLogger(error_logger);

    // 这个例子没有设置全局日志等级，只是用于演示责任链如何处理一条日志请求
    AbstractLoggerPtr logger = debug_logger;
    logger->logMessage(LOG_TYPE::DEBUG, "This is a debug message.");
    logger->logMessage(LOG_TYPE::INFO, "This is an info message.");
    logger->logMessage(LOG_TYPE::ERROR, "This is an error message.");

    return 0;
}
