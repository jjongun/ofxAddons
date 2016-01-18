#pragma once
#include "ofImage.h"

class ofxIconMaker
{
private:
	ofImage image;
	
	
	ofDirectory icon_dir;
	ofFile getFileInfo(string iconName);
	const string platform = "ios";
	string image_ratio = "_3x";
	string iconName;

public:
	enum Ratio { X1 , X2 , X3 };

	ofxIconMaker(string iconName , Ratio ratio = Ratio::X3);
	~ofxIconMaker();

	ofImage GetIcon(string iconName);
	string getIconName() const;
	ofImage getImage();
};

