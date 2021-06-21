#pragma once
#include "Decorator.h"
class Inverter :
    public Decorator
{
public:
    virtual taskState run() {
        taskState res = child->run();
        if (res == SUCCESS)
            return FAILED;
        else if (res == FAILED)
            return SUCCESS;
        else
            {
            return res;
             }
    }
};

