#include "ofApp.h"
#include "ofUtils.h"
#include "ofMaterialColorList.h"


int color_grade = 0;
//--------------------------------------------------------------
void ofApp::setup(){
	
	//simple using
	materialStyle::Color_Catergory category = static_cast<materialStyle::Color_Catergory>(2);

	materialStyle::GetColor(category, 0);
	materialStyle::GetColor(materialStyle::BLUE, 1);
	materialStyle::GetColor(materialStyle::RED, 2);
	
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw()
{
	// sample code
	/*float width = 100;
	float height = 30;
	int row = 0;
	int each_count = 10;
	for (size_t i = 0; i < 19; i++)
	{
		materialStyle::Color_Catergory category = static_cast<materialStyle::Color_Catergory>(i);
		if (i != 0 && i % each_count == 0)
			row += 1;

		for (size_t j = 0; j < materialStyle::COLOR_LEN; j++)
		{
			float x = (i % each_count) * width ;
			float y = j * height + (row * materialStyle::COLOR_LEN * height);
			
			ofColor color = materialStyle::GetColor(category, j);
			ofSetColor(color);
			ofRect(x, y, width, height);

			ofSetColor(color.invert());
			ofDrawBitmapString(materialStyle::GetHexcode(category, j), x + (width * .25f) , y + (height * .75f) );
		}
	}*/

	materialStyle::SampleDraw();
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
