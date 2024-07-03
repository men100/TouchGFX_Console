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

    void volumeUp();
    void volumeDown();
protected:
    ModelListener* modelListener;
    int16_t tickCounter;
};

#endif // MODEL_HPP
