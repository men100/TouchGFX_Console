#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

class Screen1View : public Screen1ViewBase
{
public:
	const int BackLightOffTick = 3600; // バックライト消灯までの tick 数
	const int IndicatorDivider = BackLightOffTick / 100;

    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void play();
    virtual void nextMusic();
    virtual void prevMusic();
    virtual void volumeUp();
    virtual void volumeDown();

    virtual void displayPort();
    virtual void hdmi1();
    virtual void hdmi2();
    virtual void typec();

    virtual void backgroundTouched();

    virtual void handleTickEvent();
protected:
private:
    int16_t tickCounter;
};

#endif // SCREEN1VIEW_HPP
