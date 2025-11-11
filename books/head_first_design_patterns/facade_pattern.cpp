#include <bits/stdc++.h>
using namespace std;

// 音响
struct Amplifier {
    void on() { cout << "amplifier on" << endl; }
    void off() { cout << "amplifier off" << endl; }
};
using AmpPtr = std::shared_ptr<Amplifier>;

struct Player {
    void on() { cout << "player on" << endl; }
    void off() { cout << "player off" << endl; }
};
using PlayerPtr = std::shared_ptr<Player>;

struct Projector {
    void on() { cout << "projector on" << endl; }
    void off() { cout << "projector off" << endl; }
};
using ProjectorPtr = std::shared_ptr<Projector>;

struct Light {
    void on() { cout << "light on" << endl; }
    void off() { cout << "light off" << endl; }
};
using LightPtr = std::shared_ptr<Light>;

struct Screen {
    void on() { cout << "screen on" << endl; }
    void off() { cout << "screen off" << endl; }
};
using ScreenPtr = std::shared_ptr<Screen>;

// 家庭影院外观
class HomeTheaterFacade {

    AmpPtr m_amp;
    PlayerPtr m_player;
    ProjectorPtr m_projector;
    LightPtr m_light;
    ScreenPtr m_screen;

  public:
    HomeTheaterFacade(AmpPtr amp, PlayerPtr player, ProjectorPtr projector,
                      LightPtr light, ScreenPtr screen)
        : m_amp(amp), m_player(player), m_projector(projector), m_light(light),
          m_screen(screen) {}

    void on() { // 一键启动
        cout << ">>>>> Facade on. <<<<< " << endl;
        m_amp->on();
        m_player->on();
        m_projector->on();
        m_light->on();
        m_screen->on();
    }

    void off() { // 一键停止
        cout << ">>>>> Facade off. <<<<< " << endl;
        m_amp->off();
        m_player->off();
        m_projector->off();
        m_light->off();
        m_screen->off();
    }
};
using FacadePtr = std::shared_ptr<HomeTheaterFacade>;

int main(void) {
    auto amp = std::make_shared<Amplifier>();
    auto player = std::make_shared<Player>();
    auto projector = std::make_shared<Projector>();
    auto light = std::make_shared<Light>();
    auto screen = std::make_shared<Screen>();

    // 创建一个家庭影院外观
    FacadePtr facade_ptr = std::make_shared<HomeTheaterFacade>(
        amp, player, projector, light, screen);
    facade_ptr->on();
    facade_ptr->off();

    return 0;
}
