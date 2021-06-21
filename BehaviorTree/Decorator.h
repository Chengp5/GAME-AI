#pragma once
#include "Task.h"
class Decorator :
    public Task
{
public:
    virtual taskState run() {
        return INITIALED;
    }
};

