#include "ofxThreadWatchDog.h"




ofxMainThreadDispatcher* ofxMainThreadDispatcher::inst = nullptr;



void ofxMainThreadDispatcher::Dispatch(std::function<void()> func)
{
	ThreadActionItem* item = new ThreadActionItem();
	item->callback = func;
	item->index = static_cast<int>(actions.size());

	mtx.lock();
	actions.push_back(item);
	mtx.unlock();
}






ofxMainThreadDispatcher::ofxMainThreadDispatcher()
{
	ofAddListener(ofEvents().update, this, &ofxMainThreadDispatcher::update);
}


ofxMainThreadDispatcher::~ofxMainThreadDispatcher()
{
}

void ofxMainThreadDispatcher::update(ofEventArgs & e)
{
	for (size_t i = 0; i < actions.size(); i++)
	{
		if (actions.at(i)->isExcute == false)
		{
			actions.at(i)->callback();
			actions.at(i)->isExcute = true;
			delete actions.at(i);
			actions.erase(actions.begin() + i);
			
		}
	}
}
