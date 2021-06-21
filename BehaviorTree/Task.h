#pragma once
#include<list>
#include<string>
#include<memory>
#include<vector>
/// <summary>
/// Task 行为树基类, 所有的行为都继承这个类
/// </summary>
class Task
{

protected:
	 enum taskState
	{
		SUCCESS,
		FAILED,
		STILL_RUNING,
		INITIALED,
	};
	taskState currentState;
	std::string name;
	Task() {};
	
public:
	Task* child;
	
	Task(std::string n) :name(n),currentState(INITIALED) {}
	virtual taskState run() {
		return INITIALED;
	}
	//Task(Task& t);
	Task(const Task& t);
	Task(Task&& t);
	~Task()
	{
		
			child->~Task();
		
	}
	/*bool addChild(const Task& task)
	{
		child=&(std::move(task));
	}*/
	virtual bool addChild(Task&& task)
	{
		child = &task;
	}
	virtual bool removeChild( Task& task)
	{
		if (child == &task)
		{
			delete child;
			child = nullptr;
		}
	}
	bool operator==(const Task& rhs)
	{
		return name==rhs.name;
	}
	bool operator==(Task& rhs) const
	{
		return name == rhs.name;
	}
	bool operator==(const Task& rhs) const
	{
		return name == rhs.name;
	}
	bool operator!=(const Task& t)
	{
		return !(*this==t);
	}
	//Task& operator=(const Task& t)
	//{
	//	if (*this == t)return *this;
	//	this->name = t.name;
	//	this->children = t.children;
	//	this->currentState = t.currentState;
	//	return *this;
	//}
	std::string getName() const
	{
		return name;
	}
};



