#include "ofxDelayCall.h"
#include "ofUtils.h"




ofxDelayCall::ofxDelayCall()
{
	//cout << " new class " << endl;
}

ofxDelayCall::~ofxDelayCall()
{
	//cout << " delete call " << endl;
}

void ofxDelayCall::DelayCall(long interval, std::function<void()> callback)
{
	ofxDelayCall* call = new ofxDelayCall();
	call->delayCall(interval, [=]() {
		callback();
		delete call;
	});
}

void ofxDelayCall::StartTimer()
{
	//Ÿ�̸� ����
	ofAddListener(ofEvents().update, this, &ofxDelayCall::update);
}

void ofxDelayCall::StopTimer()
{
	//Ÿ�̸� ����
	ofRemoveListener(ofEvents().update, this, &ofxDelayCall::update);
}

void ofxDelayCall::update(ofEventArgs & e)
{
	float elapsed = ofGetElapsedTimef() - startTime;
	if (elapsed < 0.0001f) elapsed = 0;

	if (elapsed > interval)
	{
		//cout << "callback!" << endl;
		callback();
		StopTimer();
	}
}

void ofxDelayCall::delayCall(long interval, std::function<void()> callback)
{
	this->callback = callback;
	this->interval = interval;
	startTime = ofGetElapsedTimef();
	StartTimer();
}
