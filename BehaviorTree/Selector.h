#pragma once
#include"SelectorOrSequence.h"
class Selector :
    public SelectorOrSequence
{
public:
    virtual taskState run() {
        for (auto& c : children)
        {
            if (c->run() == SUCCESS)
                return SUCCESS;
        }
        return FAILED;
    }
};

