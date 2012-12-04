#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
	
    
    VF.setupField(100,80,ofGetWidth(), ofGetHeight());
    VF.noiseField();
}

//--------------------------------------------------------------
void testApp::update(){
   
    VF.propagate();
    VF.fadeField(0.99);
    
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(10, 10, 30);
    
    ofSetColor(0,130,130,0);
    VF.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
   
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	float diffx = x - prevMouseX;
	float diffy = y - prevMouseY;
	
	VF.addVectorCircle((float)x, (float)y, diffx*.03, diffy*.03, 60, 3.0f);
    
	prevMouseX = x;
	prevMouseY = y;
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    prevMouseX = x;
	prevMouseY = y;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}