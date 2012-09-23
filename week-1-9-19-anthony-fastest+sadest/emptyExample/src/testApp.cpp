#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	//move pos of ofPoint along x axis
	
	squarePusher.pos.x = 1.0f;  
	
	//Set Frame Rate

    ofSetFrameRate(60); 
	
	ofBackground(48, 48, 48); 
	
}

//--------------------------------------------------------------
void testApp::update(){
	squarePusher.update();

	
   }

//--------------------------------------------------------------
void testApp::draw(){
	

	squarePusher.draw();

	
	
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