#pragma once
#include "ofEvents.h"
#include "ThreadActionItem.h"
#include <functional>
#include <mutex>
class ofxMainThreadDispatcher
{
private:
	
public:
	static ofxMainThreadDispatcher* inst;
	static ofxMainThreadDispatcher* getInst()
	{
		if (ofxMainThreadDispatcher::inst == nullptr)
			inst = new ofxMainThreadDispatcher();
		return ofxMainThreadDispatcher::inst;
	}

	vector<ThreadActionItem*> actions;
	void Dispatch(function<void()> func);

	

private:


	ofxMainThreadDispatcher();
	~ofxMainThreadDispatcher();

	

	mutex mtx;
	void update(ofEventArgs & e);

	
};




