#pragma once

#include "ofEvents.h"
#include "ofUtils.h"
#include <functional>
#include <iostream>

#ifndef PI
#define PI 3.1415926535897932384626433832795
#endif


#pragma region Easing



class Easing
{
public:
	virtual float easeIn(float t, float b, float c, float d) = 0;
	virtual float easeOut(float t, float b, float c, float d) = 0;
	virtual float easeInOut(float t, float b, float c, float d) = 0;
	virtual float easeNone(float t, float b, float c, float d) = 0;
};

class Back : public Easing {

public:
	float easeNone(float t, float b, float c, float d);
	float easeIn(float t, float b, float c, float d);
	float easeOut(float t, float b, float c, float d);
	float easeInOut(float t, float b, float c, float d);
};


class Bounce : public Easing {

public:
	float easeNone(float t, float b, float c, float d);
	float easeIn(float t, float b, float c, float d);
	float easeOut(float t, float b, float c, float d);
	float easeInOut(float t, float b, float c, float d);
};

class Circ : public Easing {

public:
	float easeNone(float t, float b, float c, float d);
	float easeIn(float t, float b, float c, float d);
	float easeOut(float t, float b, float c, float d);
	float easeInOut(float t, float b, float c, float d);
};

class Cubic : public Easing {

public:
	float easeNone(float t, float b, float c, float d);
	float easeIn(float t, float b, float c, float d);
	float easeOut(float t, float b, float c, float d);
	float easeInOut(float t, float b, float c, float d);
};

class Elastic : public Easing {

public:
	float easeNone(float t, float b, float c, float d);
	float easeIn(float t, float b, float c, float d);
	float easeOut(float t, float b, float c, float d);
	float easeInOut(float t, float b, float c, float d);
};

class Expo : public Easing {

public:
	float easeNone(float t, float b, float c, float d);
	float easeIn(float t, float b, float c, float d);
	float easeOut(float t, float b, float c, float d);
	float easeInOut(float t, float b, float c, float d);
};

class Quad : public Easing {

public:
	float easeNone(float t, float b, float c, float d);
	float easeIn(float t, float b, float c, float d);
	float easeOut(float t, float b, float c, float d);
	float easeInOut(float t, float b, float c, float d);
};


class Quart : public Easing {

public:
	float easeNone(float t, float b, float c, float d);
	float easeIn(float t, float b, float c, float d);
	float easeOut(float t, float b, float c, float d);
	float easeInOut(float t, float b, float c, float d);
};

class Quint : public Easing {
public:
	float easeNone(float t, float b, float c, float d);
	float easeIn(float t, float b, float c, float d);
	float easeOut(float t, float b, float c, float d);
	float easeInOut(float t, float b, float c, float d);
};

class Sine : public Easing {
public:
	float easeNone(float t, float b, float c, float d);
	float easeIn(float t, float b, float c, float d);
	float easeOut(float t, float b, float c, float d);
	float easeInOut(float t, float b, float c, float d);
};

class Linear : public Easing {
public:
	float easeNone(float t, float b, float c, float d);
	float easeIn(float t, float b, float c, float d);
	float easeOut(float t, float b, float c, float d);
	float easeInOut(float t, float b, float c, float d);
};
#pragma endregion

enum Transition {
	LINEAR,
	SINE,
	QUINT,
	QUART,
	QUAD,
	EXPO,
	ELASTIC,
	CUBIC,
	CIRC,
	BOUNCE,
	BACK

};

enum Equation {
	EASE_IN,
	EASE_OUT,
	EASE_IN_OUT,
	EASE_NONE
};





static Linear nfLinear;
static Sine nfSine;
static Quint nfQuint;
static Quart nfQuart;
static Quad  nfQuad;
static Expo nfExpo;
static Elastic nfElastic;
static Cubic nfCubic;
static Circ nfCirc;
static Bounce nfBounce;
static Back nfBack;


typedef std::function<void(float)> TWEEN_CALLBACK;
typedef std::function<void()> DEFALUT_CALLBACK;
class ofxXTweener
{

protected:

	short currentFunction;
	Easing *funcs[11];
	long lastTime;


	float runEquation(int transition, int equation, float t, float b, float c, float d);

private:
	TWEEN_CALLBACK updateTween;
	DEFALUT_CALLBACK completeTween;

	float start_value = 0;
	float end_value = 0;
	int draw_priority = 100;

	float start_time = 0;
	long duration = 0;
	Transition transition ;
	Equation ease ;

	float zerofloat;
	void StartTimer(int = 100);
	void StopTimer(int = 100);
	void timeElapsed(ofEventArgs &e);

	ofxXTweener();
	~ofxXTweener();

public:

	

	void callTween(long duration, float start , float end , int draw_priority, Transition transition, Equation ease, TWEEN_CALLBACK update, DEFALUT_CALLBACK complete);

	static void Run(long duration , float start, float end, int draw_priority, Transition transition, Equation ease, TWEEN_CALLBACK update, DEFALUT_CALLBACK complete);

	static void Run(long duration, float start, float end, Transition transition, Equation ease, TWEEN_CALLBACK update, DEFALUT_CALLBACK complete);

	static void Run(long duration, float start, float end, int draw_priority, Transition transition, Equation ease, TWEEN_CALLBACK update);

	static void RunZeroToOne(long duration, Transition, Equation, TWEEN_CALLBACK, DEFALUT_CALLBACK);

	static void RunZeroToOne(long duration, Transition, Equation, TWEEN_CALLBACK);

};




class SimpleTween 
{
public:
	typedef function<void(float)> TweenUpdateType;

private:
	TweenUpdateType _callbackUpdateFunc;
	int _transition;
	int _equation;
	int _duration;

	Easing *funcs[11];
	/*QTimer runTimer;
	QTime tick;*/


public:
	SimpleTween();
	~SimpleTween();

	void run(int duration, Transition transition, Equation equation, TweenUpdateType callbackUpdate);

private:
	float runEquation(int transition, int equation, float t, float b, float c, float d);
	void timeElapsed();
};



class ofxTimer
{
private:
	bool isDelayCall = false;
	float start_time = 0;
	float interval = 0;
	std::function<void()> callback;

public:
	void delayCall(float interval , std::function<void()> callback);
	void Start();
	void Stop();
private:
	void update(ofEventArgs &e);
};