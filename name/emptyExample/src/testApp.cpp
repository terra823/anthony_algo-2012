#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofBackground(0,0,0);	
	ofSetFrameRate(60);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	
	
	//A//
	ofSetColor(0, 255, 127);	
	ofTriangle(30, 75, 58, 20, 86, 75);
	
	//N//
	ofTriangle(80, 75, 108, 20, 136, 75);
	ofRect(80, 20, 28, 50);
	ofRect(125, 20, 20, 55);

	//T//
	ofRect(155, 20, 20, 55);
	ofRect(135, 20, 75, 20);
	
	//H//
	ofRect(200, 20, 20, 55);
	ofRect(230, 20, 20, 55);
	ofRect(200, 40, 75, 20);

	//O//
    ofEnableSmoothing();  	
	ofCircle(285, 50, 30);
	
	//N//
	ofTriangle(340, 75, 348, 20, 376, 75);
	ofRect(320, 20, 28, 55);
	ofRect(360, 20, 18, 55);
	
	//Y//
	ofTriangle(380, 20, 405, 75, 430, 20);
	ofRect(395, 20, 20, 55);

	
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

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