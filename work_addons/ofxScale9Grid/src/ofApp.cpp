//
// Created by supersc on 2016. 7. 3..
//

#include "ofApp.h"

void ofApp::setup() {
    ofBaseApp::setup();

    image.load("scale9grid_sample.png");
    setupShader();
    gui.setup();

    gui.add(slider_drawingWidth.setup("drawingWidth-1" , 512 , 2, 1024));
    gui.add(slider_drawingHeight.setup("drawingHeight", 512, 2, 1024));
    gui.setPosition(0 , ofGetHeight() - gui.getHeight());
}

void ofApp::setupShader() {

    cout << "Reload shader" << endl;
    rectMask.setupShaderFromFile(GL_FRAGMENT_SHADER, "shader/RectMask.glsl");
    rectMask.linkProgram();
}

void ofApp::update() {
    ofBaseApp::update();

    ofSetWindowTitle(ofToString(int(ofGetFrameRate())));
}

void ofApp::draw() {
    ofBaseApp::draw();

    ofRectangle def_rect(150,150,image.getWidth()-250 , image.getHeight()-250);

    ofRectangle def_TL(0,0,def_rect.x,def_rect.y);
    ofRectangle def_TR(def_rect.x + def_rect.width,0,image.getWidth() - (def_rect.x + def_rect.width),def_rect.y);
    ofRectangle def_BL(0,def_rect.y + def_rect.height ,def_TL.width,image.getHeight() - (def_rect.y + def_rect.height));
    ofRectangle def_BR(def_TR.x,def_BL.y,def_TR.width,def_BL.height);


    ofRectangle def_T(def_TL.width, 0 , def_rect.width , def_TL.height);
    ofRectangle def_B(def_T.x, def_BL.y , def_T.width , def_BL.height);
    ofRectangle def_L(0,def_TL.height,def_TL.width,def_rect.height);
    ofRectangle def_R(def_TR.x,def_TR.height,def_TR.width,def_rect.height);
    //ofRectangle def_rect(def_rect.x,def_rect.y,def_rect.width, def_rect.height);


    ofVec2f textureSize(image.getWidth(), image.getHeight());
    ofVec2f drawingSize(slider_drawingWidth, slider_drawingHeight);
    ofVec2f centerPos(100,200);

    ofVec2f size_rect_T(drawingSize.x - 200 , image.getHeight());

    float ratio_width = drawingSize.x / textureSize.x;
    float ratio_height = drawingSize.y / textureSize.y;
    ofPushMatrix();
    ofTranslate(def_TL.width,def_TL.height);


    //
    //C
    //
    rectMask.begin();
    rectMask.setUniform4f("iMaskRect" , def_rect.x , def_rect.y , def_rect.width , def_rect.height);
    image.draw(centerPos.x , centerPos.y , drawingSize.x , drawingSize.y);
    rectMask.end();

    //
    // T
    //
    rectMask.begin();
    rectMask.setUniform4f("iMaskRect" , def_T.x , def_T.y , def_T.width , def_T.height);
    image.draw(centerPos.x , centerPos.y - def_T.height , drawingSize.x , image.getHeight());
    rectMask.end();

    //
    // TL
    //
    rectMask.begin();
    rectMask.setUniform4f("iMaskRect" , def_TL.x , def_TL.y , def_TL.width , def_TL.height);
    image.draw(centerPos.x - def_TL.width, centerPos.y - def_TL.height , image.getWidth() , image.getHeight());
    rectMask.end();

    //
    // TR
    //
    rectMask.begin();
    rectMask.setUniform4f("iMaskRect" , def_TR.x , def_TR.y , def_TR.width , def_TR.height);
    image.draw(centerPos.x + drawingSize.x - ((def_TL.width + def_TR.width) * ratio_width), centerPos.y - def_TR.height , image.getWidth() , image.getHeight());
    rectMask.end();

    //
    // L
    //
    rectMask.begin();
    rectMask.setUniform4f("iMaskRect" , def_L.x , def_L.y , def_L.width , def_L.height);
    image.draw(centerPos.x - def_L.width, centerPos.y , image.getWidth() ,  drawingSize.y);
    rectMask.end();

    //
    // R
    //
    rectMask.begin();
    rectMask.setUniform4f("iMaskRect" , def_R.x , def_R.y , def_R.width , def_R.height);
    image.draw(centerPos.x + drawingSize.x - ((def_L.width + def_R.width) * ratio_width), centerPos.y , image.getWidth() ,  drawingSize.y);
    rectMask.end();

    //
    // B
    //
    rectMask.begin();
    rectMask.setUniform4f("iMaskRect" , def_B.x , def_B.y , def_B.width , def_B.height);
    image.draw(centerPos.x , centerPos.y + drawingSize.y - ((def_B.height + def_T.height) * ratio_height) , drawingSize.x , image.getHeight());
    rectMask.end();

    //
    // BR
    //
    rectMask.begin();
    rectMask.setUniform4f("iMaskRect" , def_BR.x , def_BR.y , def_BR.width , def_BR.height);
    image.draw(
            centerPos.x + drawingSize.x - ((def_BL.width + def_BR.width) * ratio_width),
            centerPos.y + drawingSize.y - ((def_TR.height + def_BR.height) * ratio_height) ,
            image.getWidth() , image.getHeight());
    rectMask.end();

    //
    // BL
    //
    rectMask.begin();
    rectMask.setUniform4f("iMaskRect" , def_BL.x , def_BL.y , def_BL.width , def_BL.height);
    image.draw(
            centerPos.x - def_BL.width ,
            centerPos.y + drawingSize.y - ((def_TL.height + def_BL.height) * ratio_height) ,
            image.getWidth() , image.getHeight());
    rectMask.end();

    ofPopMatrix();
    gui.draw();
}

void ofApp::drawingRectMask(ofRectangle rect) {

}



void ofApp::keyReleased(int key) {
    ofBaseApp::keyReleased(key);

    if (key == ' ')
    {
        setupShader();
    }
    if (key == 'a')
    {
        slider_drawingWidth = slider_drawingHeight = 512;
    }
    if(key == 's')
    {
        slider_drawingWidth = 768;
    }
    if(key == 'd')
    {
        slider_drawingWidth = 256;
    }
}











