#pragma once
#include <functional>
#include <iostream>

class ThreadActionItem
{
public : 
	std::function<void()> callback = nullptr;
	bool isExcute = false;
	int index = -1;

	~ThreadActionItem()
	{
		cout << "delete item : " << index << endl;
	}
};