#pragma once

#include "ofxTrueTypeFontUC.h"
//#include <map>
//#include <iostream>
using namespace std;
typedef pair<string, int> FontInfo;
typedef map<FontInfo, ofxTrueTypeFontUC*> FontCollection;

using namespace std;
class ofxFontManager
{

private:
	static ofxFontManager* instance;
	static FontCollection fonts;
	//static map<pair<string, int>, string> fonts;

public:
	static ofxTrueTypeFontUC* Add(string fontName, int size);
	static void PrintInfo();
	static ofxTrueTypeFontUC* GetFont(string fontName, int size);

	ofxFontManager();
	virtual ~ofxFontManager();
};

