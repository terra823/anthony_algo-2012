#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
	ofBackground(10, 10, 30);
	ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::update(){

}


//--------------------------------------------------------------
void testApp::draw(){
	float xorig = ofGetWidth()/2;
	float yorig = ofGetHeight()/2;
	
	
	
	for (int i = 0; i < 150; i++) {
	
		
		float radius = 10 + i * 2;	
		float angle = ofGetElapsedTimef() * (1 + i /75.0);
	
		
		float x = xorig + sqrt(radius*i) * -sin(angle);
		float y = yorig + -sqrt(radius*i) * cos(angle);
		

	ofNoFill();				
	ofRotate(angle, x, y, 10);
	ofSetColor(4*i, 2*i, 3*i, 75);
	ofRect(x,y,(i-0.1),(i-0.1));
	
		
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	if (key == OF_KEY_RETURN) {
		ofToggleFullscreen();
		
	}
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