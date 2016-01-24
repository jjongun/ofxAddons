#include "ofxFontManager.h"

FontCollection ofxFontManager::fonts;

ofxTrueTypeFontUC* ofxFontManager::Add(string fontName, int size)
{

	if (ofDirectory("font").exists() == false)
	{
		cout << "create font directory" << endl;
		ofDirectory("font").create();
	}

	ofFile fontfile("font/" + fontName);
	
	if (fontfile.exists() == false)
	{
		cout << "not exists font file, you should copy font file in [app/data/font/] " << endl;
		return nullptr;
	}

	ofxTrueTypeFontUC* _font;

	FontInfo info = FontInfo(fontName, size);
	int count = fonts.count(FontInfo(fontName, size));
	if (count < 1)
	{
		_font = new ofxTrueTypeFontUC();
		_font->loadFont(fontfile.path() , info.second);
		fonts[info] = _font;
		cout << "Add font : " << fontName << " : " << size << endl;
	}
	else {
		cout << "alread exists font" << endl;
	}

	return _font;
}


void ofxFontManager::PrintInfo()
{
	cout << "========= FONT MANAGER INFO =======" << endl;
	for (auto item : fonts)
	{
		cout << "fontName : " << item.first.first << ", size : " << item.first.second << endl;
	}
}

ofxTrueTypeFontUC * ofxFontManager::GetFont(string fontName , int size)
{
	ofxTrueTypeFontUC* result = nullptr;
	for (auto item : fonts)
	{
		if (item.first.first == fontName && item.first.second == size)
		{
			cout << "find font" << endl;
			result = item.second;
		}
	}

	if (result == nullptr)
	{
		return Add(fontName, size);
	}

	return result;
}

ofxFontManager::ofxFontManager()
{
}


 ofxFontManager::~ofxFontManager()
{
}
