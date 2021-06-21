#pragma once
#include "Decorator.h"
class UntilFail :
    public Decorator
{
public:
    virtual taskState run() {
        while (true)
        {
            taskState result = child->run();
            if (result == taskState::FAILED)
                break;
        }
        return SUCCESS;
    }
};

