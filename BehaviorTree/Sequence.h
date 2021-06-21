#pragma once
#include"SelectorOrSequence.h"
class Sequence :
    public SelectorOrSequence
{
public:
    virtual taskState run() {
        for (auto& c : children)
        {
            if (c->run() == FAILED)
                return FAILED;
        }
        return SUCCESS;
    }
};

