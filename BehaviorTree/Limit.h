#pragma once
#include"Decorator.h"
class Limit :
    public Decorator
{
private:
    int runLimit;
    int runSofar;
public:
    Limit(int num) :runLimit(num), runSofar(0)
    {

    }
    virtual taskState run() {
        if (runSofar >= runLimit)
        {
            return taskState::FAILED;
        }
        runSofar++;
        return child->run();
    }
};

