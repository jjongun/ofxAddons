#pragma once

#include "ofEvents.h"

class ofxDelayCall 
{

private:

	float interval = 0;
	float startTime = 0;
	std::function<void()> callback;

	void StartTimer();
	void StopTimer();
	void update(ofEventArgs &e);
	void delayCall(long interval, std::function<void()> callback);

	ofxDelayCall();
	~ofxDelayCall();

public:
	
	static void DelayCall(long interval, std::function<void()> callback);
	
};

