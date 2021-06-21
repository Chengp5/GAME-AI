#pragma once
#include "Task.h"
class SelectorOrSequence :
    public Task
{
public:
    std::vector<Task*> children;
	virtual bool addChild(Task&& task)
	{
		children.push_back(&task);
	}
	virtual bool removeChild(Task& task)
	{
		Task* deleteItem;
		for(int i=0;i<children.size();++i)
		if (children[i]== &task)
		{
			deleteItem = children[i];
			children.erase(children.begin()+i);
			break;
		}
		if (deleteItem)
		{
			delete deleteItem;
		}
	}
	virtual taskState run() {
		return INITIALED;
	}
};

