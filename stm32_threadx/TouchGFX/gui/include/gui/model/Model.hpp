#ifndef MODEL_HPP
#define MODEL_HPP

#include <cstdint>

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();

    uint8_t getSystemVolume() { return systemVolume; }
    uint8_t getCpuUsage() { return cpuUsage; }
    uint8_t getMemoryUsage() { return memoryUsage; }
    uint8_t getGpuUsage() { return gpuUsage; }

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
    int16_t tickCounter;
    uint8_t systemVolume;
    uint8_t cpuUsage;
    uint8_t memoryUsage;
    uint8_t gpuUsage;
};

#endif // MODEL_HPP
