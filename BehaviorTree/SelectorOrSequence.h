#pragma once
#include "Task.h"
class SelectorOrSequence :
    public Task
{
public:
    std::vector<TaskPtr> children;
	virtual bool addChild(TaskPtr&& task)
	{
		children.push_back(task);
	}
	virtual bool removeChild(const TaskPtr& task)
	{
		for(int i=0;i<children.size();++i)
		if (children[i]== task)
		{
			children.erase(children.begin()+i);
			break;
		}
		
	}
	virtual taskState run() {
		return INITIALED;
	}
};

