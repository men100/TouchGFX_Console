#ifndef MODEL_HPP
#define MODEL_HPP

#include <cstdint>

class ModelListener;

class Model
{
public:
	static const int USAGE_ARRAY_NUM = 60;

    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
    void setCurrentScreenIndex(uint8_t index) { currentScreenIndex = index; }
    void setBackLightState(bool isOn);
    bool getBackLightState() { return isBackLightOn; }
    void setBackLightBrightness(uint8_t brightness);
    uint8_t getBackLightBrightness() const { return backLightBrightness; }


    uint8_t getSystemVolume() { return systemVolume; }
    uint8_t getCpuUsage() { return cpuUsage[usageIndex]; }
    uint8_t getMemoryUsage() { return memoryUsage[usageIndex]; }
    uint8_t getGpuUsage() { return gpuUsage[usageIndex]; }
    void setEachUsage(uint8_t cpu, uint8_t memory, uint8_t gpu);
    void getEachUsage(uint8_t cpu[], uint8_t memory[], uint8_t gpu[]);
    uint8_t getUsageIndex() { return usageIndex; }

    void play();
    void nextMusic();
    void prevMusic();
    void volumeUp();
    void volumeDown();

    void displayPort();
    void hdmi1();
    void hdmi2();
    void typec();
protected:
    ModelListener* modelListener;
private:
    uint8_t currentScreenIndex;
    uint8_t backLightBrightness;
    int16_t tickCounter;
    bool isBackLightOn;
    uint8_t systemVolume;

    uint8_t usageIndex;
    uint8_t cpuUsage[USAGE_ARRAY_NUM];
    uint8_t memoryUsage[USAGE_ARRAY_NUM];
    uint8_t gpuUsage[USAGE_ARRAY_NUM];
};

#endif // MODEL_HPP
