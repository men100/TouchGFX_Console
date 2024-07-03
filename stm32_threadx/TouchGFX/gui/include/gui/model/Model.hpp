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
    int16_t tickCounter;
};

#endif // MODEL_HPP
