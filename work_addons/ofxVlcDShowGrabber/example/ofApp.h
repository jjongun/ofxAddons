#pragma once

#include "ofMain.h"
#include "VLCDShow.h"
#include "ofxXmlSettings.h"

class ofApp : public ofBaseApp{

	public:
		VLCDShow dShow;

		void setup();
		void update();
		void draw();

		string printCaptureDevice();
		void readXml(string& out_deviceName , int& width , int& height );

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void exit();
};
