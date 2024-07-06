#ifndef SCREEN1PRESENTER_HPP
#define SCREEN1PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Screen1View;

class Screen1Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    Screen1Presenter(Screen1View& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~Screen1Presenter() {}

    void setCurrentScreenIndex(uint8_t index)
    {
    	model->setCurrentScreenIndex(index);
    }
    void setBackLightState(bool isOn)
    {
    	model->setBackLightState(isOn);
    }
    bool getBackLightState()
    {
    	return model->getBackLightState();
    }

    void play()
    {
    	model->play();
    }
    void nextMusic()
    {
    	model->nextMusic();
    }
    void prevMusic()
    {
    	model->prevMusic();
    }
    void volumeUp()
    {
    	model->volumeUp();
    }
    void volumeDown()
    {
    	model->volumeDown();
    }
    void displayPort()
    {
    	model->displayPort();
    }
    void hdmi1()
    {
    	model->hdmi1();
    }
    void hdmi2()
    {
    	model->hdmi2();
    }
    void typec()
    {
    	model->typec();
    }
    uint8_t getSystemVolume()
    {
    	return model->getSystemVolume();
    }
    uint8_t getCpuUsage()
    {
    	return model->getCpuUsage();
    }
    uint8_t getMemoryUsage()
    {
    	return model->getMemoryUsage();
    }
    uint8_t getGpuUsage()
    {
    	return model->getGpuUsage();
    }
private:
    Screen1Presenter();

    Screen1View& view;
};

#endif // SCREEN1PRESENTER_HPP
