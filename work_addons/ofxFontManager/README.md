# ofxDelayCall
simple using 

```c++
#include "ofxTrueTypeFontUC.h"
#include "ofxFontManager.h"


ofxTrueTypeFontUC* font1;
//--------------------------------------------------------------
void ofApp::setup(){
	font1 = ofxFontManager::GetFont("MSNeoGothic.ttf", 30);
}

//--------------------------------------------------------------
void ofApp::draw() {
	if (font1 != nullptr)
		font1->drawString("ABCD 한글", 0, 30);
}
```


# Including addon
ofxTrueTypeFontUC (https://github.com/hironishihara/ofxTrueTypeFontUC)
