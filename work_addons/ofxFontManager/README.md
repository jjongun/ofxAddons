# ofxFontManager
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

##Key point
GetFont(...) : if exists font and size , it will get you ofxTrueTypeFontUC* object. if not exists font file , it will create font object and get you ofxTrueTypeFontUC* object.


##Need font file
You should copy font file in " app/data/font " .



## Already including addon source code
ofxTrueTypeFontUC (https://github.com/hironishihara/ofxTrueTypeFontUC) 
