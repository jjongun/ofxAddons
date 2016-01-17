
#include "ofxXTweener.h"


#pragma region Easing functions

/***** LINEAR ****/
float Linear::easeNone(float t, float b, float c, float d) {
	return c*t / d + b;
}
float Linear::easeIn(float t, float b, float c, float d) {
	return c*t / d + b;
}
float Linear::easeOut(float t, float b, float c, float d) {
	return c*t / d + b;
}

float Linear::easeInOut(float t, float b, float c, float d) {
	return c*t / d + b;
}

/***** SINE ****/

float Sine::easeNone(float t, float b, float c, float d) {
	return c*t / d + b;
}
float Sine::easeIn(float t, float b, float c, float d) {
	return -c * cos(t / d * float(PI / 2)) + c + b;
}
float Sine::easeOut(float t, float b, float c, float d) {
	return c * sin(t / d * float(PI / 2)) + b;
}

float Sine::easeInOut(float t, float b, float c, float d) {
	return -c / 2 * float(cos(PI*t / d) - 1) + b;
}

/**** Quint ****/
float Quint::easeNone(float t, float b, float c, float d) {
	return c*t / d + b;
}
float Quint::easeIn(float t, float b, float c, float d) {
	return c*(t /= d)*t*t*t*t + b;
}
float Quint::easeOut(float t, float b, float c, float d) {
	return c*((t = t / d - 1)*t*t*t*t + 1) + b;
}

float Quint::easeInOut(float t, float b, float c, float d) {
	if ((t /= d / 2) < 1) return c / 2 * t*t*t*t*t + b;
	return c / 2 * ((t -= 2)*t*t*t*t + 2) + b;
}

/**** Quart ****/
float Quart::easeNone(float t, float b, float c, float d) {
	return c*t / d + b;
}
float Quart::easeIn(float t, float b, float c, float d) {
	return c*(t /= d)*t*t*t + b;
}
float Quart::easeOut(float t, float b, float c, float d) {
	return -c * ((t = t / d - 1)*t*t*t - 1) + b;
}

float Quart::easeInOut(float t, float b, float c, float d) {
	if ((t /= d / 2) < 1) return c / 2 * t*t*t*t + b;
	return -c / 2 * ((t -= 2)*t*t*t - 2) + b;
}

/**** Quad ****/
float Quad::easeNone(float t, float b, float c, float d) {
	return c*t / d + b;
}
float Quad::easeIn(float t, float b, float c, float d) {
	return c*(t /= d)*t + b;
}
float Quad::easeOut(float t, float b, float c, float d) {
	return -c *(t /= d)*(t - 2) + b;
}

float Quad::easeInOut(float t, float b, float c, float d) {
	if ((t /= d / 2) < 1) return ((c / 2)*(t*t)) + b;
	return -c / 2 * (((t - 2)*(--t)) - 1) + b;
	/*
	originally return -c/2 * (((t-2)*(--t)) - 1) + b;

	I've had to swap (--t)*(t-2) due to diffence in behaviour in
	pre-increment operators between java and c++, after hours
	of joy
	*/

}

/**** Expo ****/
float Expo::easeNone(float t, float b, float c, float d) {
	return c*t / d + b;
}
float Expo::easeIn(float t, float b, float c, float d) {
	return float((t == 0) ? b : c * pow(2, 10 * (t / d - 1)) + b);
}
float Expo::easeOut(float t, float b, float c, float d) {
	return float((t == d) ? b + c : c * (-pow(2, -10 * t / d) + 1) + b);
}

float Expo::easeInOut(float t, float b, float c, float d) {
	if (t == 0) return b;
	if (t == d) return b + c;
	if ((t /= d / 2) < 1) return float(c / 2 * pow(2, 10 * (t - 1)) + b);
	return float(c / 2 * (-pow(2, -10 * --t) + 2) + b);
}


/****  Elastic ****/
float Elastic::easeNone(float t, float b, float c, float d) {
	return c*t / d + b;
}
float Elastic::easeIn(float t, float b, float c, float d) {
	if (t == 0) return b;  if ((t /= d) == 1) return b + c;
	float p = d*.3f;
	float a = c;
	float s = p / 4;
	float postFix = float(a*pow(2, 10 * (t -= 1))); // this is a fix, again, with post-increment operators
	return float(-(postFix * sin((t*d - s)*(2 * PI) / p)) + b);
}

float Elastic::easeOut(float t, float b, float c, float d) {
	if (t == 0) return b;  if ((t /= d) == 1) return b + c;
	float p = d*.3f;
	float a = c;
	float s = p / 4;
	return float(a*pow(2, -10 * t) * sin((t*d - s)*(2 * PI) / p) + c + b);
}

float Elastic::easeInOut(float t, float b, float c, float d) {
	if (t == 0) return b;  if ((t /= d / 2) == 2) return b + c;
	float p = d*(.3f*1.5f);
	float a = c;
	float s = p / 4;

	if (t < 1) {
		float postFix = float(a*pow(2, 10 * (t -= 1))); // postIncrement is evil
		return float(-.5f*(postFix* sin((t*d - s)*(2 * PI) / p)) + b);
	}
	float postFix = float(a*pow(2, -10 * (t -= 1))); // postIncrement is evil
	return postFix * float(sin((t*d - s)*(2 * PI) / p)*.5f + c + b);
}

/****  Cubic ****/
float Cubic::easeNone(float t, float b, float c, float d) {
	return c*t / d + b;
}
float Cubic::easeIn(float t, float b, float c, float d) {
	return c*(t /= d)*t*t + b;
}
float Cubic::easeOut(float t, float b, float c, float d) {
	return c*((t = t / d - 1)*t*t + 1) + b;
}

float Cubic::easeInOut(float t, float b, float c, float d) {
	if ((t /= d / 2) < 1) return c / 2 * t*t*t + b;
	return c / 2 * ((t -= 2)*t*t + 2) + b;
}

/*** Circ ***/
float Circ::easeNone(float t, float b, float c, float d) {
	return c*t / d + b;
}
float Circ::easeIn(float t, float b, float c, float d) {
	return -c * (sqrt(1 - (t /= d)*t) - 1) + b;
}
float Circ::easeOut(float t, float b, float c, float d) {
	return c * sqrt(1 - (t = t / d - 1)*t) + b;
}
float Circ::easeInOut(float t, float b, float c, float d) {
	if ((t /= d / 2) < 1) return -c / 2 * (sqrt(1 - t*t) - 1) + b;
	return c / 2 * (sqrt(1 - t*(t -= 2)) + 1) + b;
}

/****  Bounce ****/
float Bounce::easeNone(float t, float b, float c, float d) {
	return c*t / d + b;
}
float Bounce::easeIn(float t, float b, float c, float d) {
	return c - easeOut(d - t, 0, c, d) + b;
}
float Bounce::easeOut(float t, float b, float c, float d) {
	if ((t /= d) < (1 / 2.75f)) {
		return c*(7.5625f*t*t) + b;
	}
	else if (t < (2 / 2.75f)) {
		float postFix = t -= (1.5f / 2.75f);
		return c*(7.5625f*(postFix)*t + .75f) + b;
	}
	else if (t < (2.5 / 2.75)) {
		float postFix = t -= (2.25f / 2.75f);
		return c*(7.5625f*(postFix)*t + .9375f) + b;
	}
	else {
		float postFix = t -= (2.625f / 2.75f);
		return c*(7.5625f*(postFix)*t + .984375f) + b;
	}
}

float Bounce::easeInOut(float t, float b, float c, float d) {
	if (t < d / 2) return easeIn(t * 2, 0, c, d) * .5f + b;
	else return easeOut(t * 2 - d, 0, c, d) * .5f + c*.5f + b;
}

/**** Back *****/
float Back::easeNone(float t, float b, float c, float d) {
	return c*t / d + b;
}
float Back::easeIn(float t, float b, float c, float d) {
	float s = 1.70158f;
	float postFix = t /= d;
	return c*(postFix)*t*((s + 1)*t - s) + b;
}
float Back::easeOut(float t, float b, float c, float d) {
	float s = 1.70158f;
	return c*((t = t / d - 1)*t*((s + 1)*t + s) + 1) + b;
}
float Back::easeInOut(float t, float b, float c, float d) {
	float s = 1.70158f;
	if ((t /= d / 2) < 1) return c / 2 * (t*t*(((s *= (1.525f)) + 1)*t - s)) + b;
	float postFix = t -= 2;
	return c / 2 * ((postFix)*t*(((s *= (1.525f)) + 1)*t + s) + 2) + b;
}

#pragma endregion


//implementation Tweener Class*********************************************************
#pragma region ofxXTween


float ofxXTweener::runEquation(int transition, int equation, float t, float b, float c, float d) {

	float result = 0;
	if (equation == EASE_IN) {
		result = funcs[transition]->easeIn(t, b, c, d);
	}
	else if (equation == EASE_OUT) {
		result = funcs[transition]->easeOut(t, b, c, d);
	}
	else if (equation == EASE_IN_OUT) {
		result = funcs[transition]->easeInOut(t, b, c, d);
	}
	else if (equation == EASE_NONE)
	{
		result = funcs[transition]->easeNone(t, b, c, d);
	}

	return result;
}


void ofxXTweener::callTween(long duration, float start , float end, int draw_priority, Transition transition,  Equation ease , TWEEN_CALLBACK update, DEFALUT_CALLBACK complete)
{
	updateTween = update;
	completeTween = complete;
	this->duration = duration;
	this->start_value = start;
	this->end_value = end;
	this->draw_priority = draw_priority;
	
	this->transition = transition;
	this->ease = ease;

	zerofloat = 0.0f;
	updateTween(0.0f);
	StartTimer(draw_priority);
}

void ofxXTweener::Run(long duration, float start, float end, int draw_priority, Transition transition, Equation ease, TWEEN_CALLBACK update, DEFALUT_CALLBACK complete)
{
	ofxXTweener* tween = new ofxXTweener();
	tween->callTween(duration, start, end, draw_priority, transition, ease, update,
	[complete , tween]() {
		complete();
		delete tween;
	});
}

void ofxXTweener::Run(long duration, float start, float end, int draw_priority, Transition transition, Equation ease, TWEEN_CALLBACK update)
{
	ofxXTweener* tween = new ofxXTweener();
	tween->callTween(duration, start, end, draw_priority, transition, ease, update ,
		[tween]() {
		delete tween;
	});
}

void ofxXTweener::Run(long duration, float start, float end, Transition transition, Equation ease, TWEEN_CALLBACK update, DEFALUT_CALLBACK complete)
{
	ofxXTweener* tween = new ofxXTweener();
	tween->callTween(duration, start, end, ofEventOrder::OF_EVENT_ORDER_APP, transition, ease, update,
		[complete , tween]() {
		complete();
		delete tween;
	});
}

void ofxXTweener::RunZeroToOne(long duration, Transition transition, Equation ease, TWEEN_CALLBACK update, DEFALUT_CALLBACK complete)
{
	ofxXTweener* tween = new ofxXTweener();
	tween->callTween(duration, 0, 1, ofEventOrder::OF_EVENT_ORDER_APP , transition, ease, update,
		[complete, tween]() {
		complete();
		delete tween;
	});
}

void ofxXTweener::RunZeroToOne(long duration, Transition transition, Equation ease, TWEEN_CALLBACK update)
{
	ofxXTweener* tween = new ofxXTweener();
	tween->callTween(duration, 0, 1, ofEventOrder::OF_EVENT_ORDER_APP, transition, ease, update,
		[tween]() {
		delete tween;
	});
}



void ofxXTweener::StartTimer(int draw_priority)
{
	start_time = ofGetElapsedTimef();
	ofAddListener(ofEvents().draw, this, &ofxXTweener::timeElapsed , draw_priority);
}

void ofxXTweener::StopTimer(int draw_priority)
{
	ofRemoveListener(ofEvents().draw, this, &ofxXTweener::timeElapsed , draw_priority);
}

void ofxXTweener::timeElapsed(ofEventArgs &e)
{
	float elapsed = ofGetElapsedTimef() - start_time;
	if (elapsed < 0.0001f)
		elapsed = 0;

	//float res = runEquation(CUBIC, EASE_OUT, elapsed, 0, 1, duration);
	float res = runEquation(transition, ease, elapsed, 0, 1, duration);

	res = ofMap(res, 0, 1, start_value, end_value);
	updateTween(res);

	if (elapsed > duration)
	{
		StopTimer(this->draw_priority);
		completeTween();
	}
}


ofxXTweener::ofxXTweener()
{
	zerofloat = 0.0f;
	this->funcs[LINEAR] = &nfLinear;
	this->funcs[SINE] = &nfSine;
	this->funcs[QUINT] = &nfQuint;
	this->funcs[QUART] = &nfQuart;
	this->funcs[QUAD] = &nfQuad;
	this->funcs[EXPO] = &nfExpo;
	this->funcs[ELASTIC] = &nfElastic;
	this->funcs[CUBIC] = &nfCubic;
	this->funcs[CIRC] = &nfCirc;
	this->funcs[BOUNCE] = &nfBounce;
	this->funcs[BACK] = &nfBack;


	lastTime = 0;

}
ofxXTweener::~ofxXTweener()
{
}
#pragma endregion


//implementation SimpleTween Class*********************************************************
#pragma region SimpleTween

SimpleTween::SimpleTween()
{
	this->funcs[LINEAR] = &nfLinear;
	this->funcs[SINE] = &nfSine;
	this->funcs[QUINT] = &nfQuint;
	this->funcs[QUART] = &nfQuart;
	this->funcs[QUAD] = &nfQuad;
	this->funcs[EXPO] = &nfExpo;
	this->funcs[ELASTIC] = &nfElastic;
	this->funcs[CUBIC] = &nfCubic;
	this->funcs[CIRC] = &nfCirc;
	this->funcs[BOUNCE] = &nfBounce;
	this->funcs[BACK] = &nfBack;

	//event
	//connect(&runTimer, SIGNAL(timeout()), this, SLOT(timeElapsed()));

	//qDebug() << "created simple tween";
}

SimpleTween::~SimpleTween()
{
	//qDebug() << "deleted simple tween";
}

float SimpleTween::runEquation(int transition, int equation, float t, float b, float c, float d)
{
	float result;
	if (equation == EASE_IN) {
		result = funcs[transition]->easeIn(t, b, c, d);
	}
	else if (equation == EASE_OUT) {
		result = funcs[transition]->easeOut(t, b, c, d);
	}
	else if (equation == EASE_IN_OUT) {
		result = funcs[transition]->easeInOut(t, b, c, d);
	}
	return result;
}

void SimpleTween::run(int duration, Transition transition, Equation equation, SimpleTween::TweenUpdateType callbackUpdate)
{
	_duration = duration;
	_transition = transition;
	_equation = equation;

	/*tick.restart();
	runTimer.start(17);*/

	_callbackUpdateFunc = callbackUpdate;
	_callbackUpdateFunc(0.0f);

	//qDebug() << "transtion : " << _transition << " eq : " << _equation;
}

void SimpleTween::timeElapsed()
{
	/*int elapsed = tick.elapsed();
	if (elapsed >= _duration)
	{
		_callbackUpdateFunc(1.0f);
		runTimer.stop();
		return;
	}
	float res = runEquation(_transition, _equation, elapsed, 0, 1, _duration);
	_callbackUpdateFunc(res);*/
}
#pragma endregion









void ofxTimer::delayCall(float interval , std::function<void()> callback)
{
	isDelayCall = true;
	this->interval = interval;
	this->callback = callback;
	Start();
}

void ofxTimer::Start()
{
	start_time = ofGetElapsedTimef();
	ofAddListener(ofEvents().update, this, &ofxTimer::update);
}


void ofxTimer::Stop()
{
	ofRemoveListener(ofEvents().update, this, &ofxTimer::update);
}

void ofxTimer::update(ofEventArgs & e)
{
	float elapsed = ofGetElapsedTimef() - start_time;
	if (elapsed < 0.0001f)
		elapsed = 0;

	if(isDelayCall == true)
	{ 
		if (elapsed > interval)
		{
			callback();
			Stop();
		}
	}  
	
	//cout << elapsed << endl;
}
