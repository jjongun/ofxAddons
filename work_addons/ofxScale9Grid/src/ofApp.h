//
// Created by supersc on 2016. 7. 3..
//

#ifndef SCALE9GRID_OFAPP_H
#define SCALE9GRID_OFAPP_H

#include "ofMain.h"
#include "ofxGui.h"
class ofApp : public ofBaseApp{

public:
    ofImage image;
    ofShader rectMask;
    ofxPanel gui;
    ofxFloatSlider slider_drawingWidth , slider_drawingHeight;

public:
    void setup();
    void setupShader();
    void update();
    void draw();
    void drawingRectMask(ofRectangle rect);

    void keyReleased(int key);
    
};


#endif //SCALE9GRID_OFAPP_H
