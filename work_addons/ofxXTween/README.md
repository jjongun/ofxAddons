# ofxDelayCall
simple using 
```c++
ofxXTweener::Run(3.0 , 30 , 100 , 100 , Transition::BACK, Equation::EASE_IN_OUT , 
		[](float v) {
			ofSetColor(ofColor::red);
			ofCircle(v, 30, 10);
		},
			[]() {
			cout << "complete" << endl;
		});


		ofxXTweener::RunZeroToOne(3.0, Transition::BACK, Equation::EASE_IN_OUT,
			[](float v) {
			ofSetColor(ofColor::blue);
			ofCircle(v * 100, 50, 10);
		},
			[]() {
			cout << "complete" << endl;
		});
```
