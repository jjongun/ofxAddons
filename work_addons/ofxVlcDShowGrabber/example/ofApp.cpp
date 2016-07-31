#include "ofApp.h"
#include "ofVideoGrabber.h"


//
// autor : supersc
// inspired from : jnakanojp's ofxVLCVideoPlayer
//




//--------------------------------------------------------------
void ofApp::setup(){

	printCaptureDevice();

	string dev_name;
	int screen_width, screen_height;
	readXml(dev_name , screen_width , screen_height);
	cout << "out : " << dev_name << "," << screen_width << "," << screen_height << endl;
	
	dShow.setup(dev_name, screen_width, screen_height); // put your device name and set size for your deivce as your device can.

}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){

	dShow.draw();
	shader.end();

	ofDrawBitmapStringHighlight("system fps : " + ofToString(ofGetFrameRate()), 30, 20);
	ofDrawBitmapStringHighlight("vlc fps : " + ofToString(dShow.getFps()), 30, 40);
}

string ofApp::printCaptureDevice()
{
	
	ofVideoGrabber grab;
	vector<ofVideoDevice> list = grab.listDevices();
	stringstream ss;
	for (int i = 0; i < list.size(); i++)
	{
		ss << list[i].id << " : " << list[i].deviceName << "\r\n";
	}
	ss << " - end - " << "\r\n";
	cout << ss << "\r\n";
	ofFile file("deviceList.txt" , ofFile::WriteOnly);
	if (file.exists() == false)
	{
		file.create();
	}
	file << ss.str() << "\r\n";
	file.close();

	return ss.str();
}

void ofApp::readXml(string& out_deviceName , int& width, int& height)
{
	ofxXmlSettings settings("setting.xml");
	cout << "deviceName : " << settings.getValue("deviceName" , "null") << endl;
	out_deviceName = settings.getValue("deviceName", "null");
	width = ofToInt(settings.getValue("screenWidth", "320"));
	height = ofToInt(settings.getValue("screenHeight", "240"));
}

void ofApp::exit()
{
	dShow.stop();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (key == 'a')
	{
		dShow.play();
	}
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
