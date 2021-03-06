#include "ofxDelayCall.h"
#include "ofUtils.h"



//생성 시점, 소멸 시점을 그저 체크 하기 위하여 로그를 찍어 놨습니다.
ofxDelayCall::ofxDelayCall()
{
	//cout << " new class " << endl;
}

ofxDelayCall::~ofxDelayCall()
{
	//cout << " delete call " << endl;
}


void ofxDelayCall::StartTimer()
{
	//타이머 시작
	ofAddListener(ofEvents().update,this, &ofxDelayCall::update);
}

void ofxDelayCall::StopTimer()
{
	//타이머 삭제
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




void ofxDelayCall::DelayCall(long interval, std::function<void()> callback)
{
	ofxDelayCall* call = new ofxDelayCall();
	call->delayCall(interval, [callback,call]() {
		callback();
		delete call;
	});
}