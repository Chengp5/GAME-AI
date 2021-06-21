#pragma once
#include"SelectorOrSequence.h"
#include<algorithm>
class NonDeterministicSelector :
    public SelectorOrSequence
{
public:
    virtual taskState run() {
        std::random_shuffle(children.begin(), children.end());
        for (auto& c : children)
        {
            if (c->run() == SUCCESS)
                return SUCCESS;
        }
        return FAILED;
    }
};

