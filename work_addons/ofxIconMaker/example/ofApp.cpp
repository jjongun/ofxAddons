#include "ofApp.h"
#include "ofxIconMaker.h"

//--------------------------------------------------------------
ofxIconMaker* icon1;

void ofApp::setup(){
	

	//you can download "https://design.google.com/icons/"
	//and extract to bin/data/icon folder.


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
void ofApp::mouseReleased(int x, int y, int button){

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
