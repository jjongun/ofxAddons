#include "ofApp.h"
#include <thread>;



using namespace std::literals;

//thread work example 
void SomeThread()
{
	thread th([]() {
	
		cout << "n thread step1 : " << std::this_thread::get_id() << endl;
		std::this_thread::sleep_for(1s);


		//dispatch to mainthread
		ofxMainThreadDispatcher::getInst()->Dispatch([]() {
			cout << "callback!!! " << std::this_thread::get_id() << endl;
		});

	});
	th.detach();
}


//--------------------------------------------------------------
void ofApp::setup() {
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	cout << "============= start test ============== : " << std::this_thread::get_id() << endl;
	SomeThread();
	SomeThread();
	SomeThread();
}


//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(ofColor::black);
	string cur_time_str = ofToString(ofGetElapsedTimef());
	ofDrawBitmapString(cur_time_str, 0, 30);
}



//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}


//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	
	
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}


//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
