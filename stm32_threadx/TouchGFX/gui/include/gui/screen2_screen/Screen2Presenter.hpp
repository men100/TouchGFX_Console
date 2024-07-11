#ifndef SCREEN2PRESENTER_HPP
#define SCREEN2PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Screen2View;

class Screen2Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    Screen2Presenter(Screen2View& v);

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

    virtual ~Screen2Presenter() {}

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
    void getEachUsage(uint8_t cpu[], uint8_t memory[], uint8_t gpu[]) {
    	model->getEachUsage(cpu, memory, gpu);
    }
    uint8_t getUsageIndex() { return model->getUsageIndex(); }

private:
    Screen2Presenter();

    Screen2View& view;
};

#endif // SCREEN2PRESENTER_HPP
