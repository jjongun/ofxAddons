# ofxDelayCall



simple using 

``` c++
ofxIconMaker* icon1;
void ofApp::setup(){
	

	//you can download "https://design.google.com/icons/"
	//and extract to bin/icon folder.
	//you should check example bin folder in git.


	//create icon width icon folder name

	icon1 = new ofxIconMaker("ic_account_circle_white_24dp" );
	
	//choose resolustion X1 , X2 , defalut X3
	//icon1 = new ofxIconMaker("ic_account_circle_white_24dp", ofxIconMaker::X1);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(ofColor::blue);
	icon1->getImage().draw(0, 0);
	icon1->getImage().draw(0, 100, 200, 200);
}
```
