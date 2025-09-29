#include <iostream>
#include <memory>
#include <vector>
using namespace std;

// 接收者，实际执行的对象
struct Light {
    void on() { cout << "light is on" << endl; }
    void off() { cout << "light is off" << endl; }
};

struct Fan {
    void on() { cout << "fan is on" << endl; }
    void off() { cout << "fan is off" << endl; }
};
using LightPtr = std::shared_ptr<Light>;
using FanPtr = std::shared_ptr<Fan>;

// 命令
struct Command {
    virtual void execute() {};
    virtual void undo() {};
};

struct NoCommand : public Command {
    void execute() override { cout << "no command execute" << endl; }
    void undo() override { cout << "no command undo" << endl; }
};

struct LightOnCommand : public Command {
    LightPtr light_ptr;
    LightOnCommand(LightPtr ptr) : light_ptr(ptr) {}
    void execute() override { light_ptr->on(); }
    void undo() override { light_ptr->off(); }
};

struct LightOffCommand : public Command {
    LightPtr light_ptr;
    LightOffCommand(LightPtr ptr) : light_ptr(ptr) {}
    void execute() override { light_ptr->off(); }
    void undo() override { light_ptr->on(); }
};

struct FanOnCommand : public Command {
    FanPtr fan_ptr;
    FanOnCommand(FanPtr ptr) : fan_ptr(ptr) {}
    void execute() override { fan_ptr->on(); }
    void undo() override { fan_ptr->off(); }
};

struct FanOffCommand : public Command {
    FanPtr fan_ptr;
    FanOffCommand(FanPtr ptr) : fan_ptr(ptr) {}
    void execute() override { fan_ptr->off(); }
    void undo() override { fan_ptr->on(); }
};

using CommandPtr = std::shared_ptr<Command>;

// 一个场景开关，可以一次执行多条命令
struct MacroCommand : public Command {
    vector<CommandPtr> group_commands;

    MacroCommand(vector<CommandPtr> ptrs) : group_commands(ptrs) {}

    void execute() {
        for (auto &ptr : group_commands) {
            ptr->execute();
        }
    }

    void undo() { // 从后往前撤销
        for (int i = group_commands.size() - 1; i >= 0; i--) {
            group_commands[i]->undo();
        }
    }
};

// 调用者
// 遥控器有 7 个槽，每个槽对应一个开启按钮和关闭按钮
// 遥控器有一个撤销按钮，能够撤销上一次的命令
struct Remote {
    static const int sz = 7;
    vector<CommandPtr> on_commands, off_commands;
    CommandPtr last_command;

    Remote() {
        for (int i = 0; i < sz; i++) {
            on_commands.emplace_back(std::make_shared<NoCommand>());
            off_commands.emplace_back(std::make_shared<NoCommand>());
        }
    }

    void setCommand(int slot, CommandPtr on, CommandPtr off) {
        on_commands[slot] = on;
        off_commands[slot] = off;
    }

    void resetCommand(int slot) {
        on_commands[slot] = std::make_shared<NoCommand>();
        off_commands[slot] = std::make_shared<NoCommand>();
    }

    void slotOnPushed(int slot) {
        on_commands[slot]->execute();
        last_command = on_commands[slot];
    }
    void slotOffPushed(int slot) {
        off_commands[slot]->execute();
        last_command = off_commands[slot];
    }

    void revokeCommandPushed() {
        last_command->undo();
        last_command = std::make_shared<NoCommand>();
    }
};

using RemotePtr = std::shared_ptr<Remote>;

int main(int argc, char *argv[]) {

    // 生成接收者对象
    LightPtr light = std::make_shared<Light>();
    FanPtr fan = std::make_shared<Fan>();

    // 生成命令对象
    CommandPtr light_on = std::make_shared<LightOnCommand>(light);
    CommandPtr light_off = std::make_shared<LightOffCommand>(light);
    CommandPtr fan_on = std::make_shared<FanOnCommand>(fan);
    CommandPtr fan_off = std::make_shared<FanOffCommand>(fan);

    // 生成调用者对象
    RemotePtr remote = std::make_shared<Remote>();
    remote->setCommand(0, light_on, light_off);
    remote->setCommand(1, fan_on, fan_off);

    // 测试接口
    remote->slotOnPushed(0);
    remote->slotOffPushed(0);
    remote->slotOnPushed(1);
    remote->revokeCommandPushed();

    remote->resetCommand(0);
    remote->slotOnPushed(0);

    // 测试宏命令接口
    CommandPtr party_on = std::make_shared<MacroCommand>(
        std::vector<CommandPtr>({light_on, fan_off}));
    CommandPtr party_off = std::make_shared<MacroCommand>(
        std::vector<CommandPtr>({light_off, fan_on}));
    remote->setCommand(2, party_on, party_off);
    remote->slotOnPushed(2);
    remote->revokeCommandPushed();

    return 0;
}
