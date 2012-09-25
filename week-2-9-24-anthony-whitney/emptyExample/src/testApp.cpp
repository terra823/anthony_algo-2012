#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	ofBackground(10, 10, 30);
	ofSetCircleResolution(100);
	ofEnableAlphaBlending();

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

	float xorig = ofGetWidth()/2;
	float yorig = ofGetHeight()/2;
	
	for (int i = 0; i < 137.5; i++) {
		
		float radius = 10 + i * 2;
		
		float angle = ofGetElapsedTimef() * (1 + i /50.0);
		
		float x = xorig + radius * cos(angle);
		float y = yorig + radius * sin(angle);
		
		ofSetColor(ofRandom(0,255)+255, ofRandom(0,255)+0,ofRandom(0,255)+0, 20);
		ofFill();		
		ofCircle(x, y, (i-0.1));
	}
	

	
	
	float xorig2 = ofGetWidth()/2;
	float yorig2 = ofGetHeight()/2;;
	
	for (int i = 0; i < 137.5; i++){
		
		float radius2 = 10 + i * 2;
		float angle2 = ofGetElapsedTimef() * (1 + i /50.0);
		float x2 = xorig2 + radius2 * -cos(angle2);
		float y2 = yorig2 + radius2 * sin(angle2);
		

		ofSetColor(ofRandom(0,255)+35, ofRandom(0,255)+255,ofRandom(0,255)+95, 20);
		ofFill();
		ofCircle(x2,y2,(i-0.1));
		
	}	
	
	
	float xorig3 = ofGetWidth()/2;
	float yorig3 = ofGetHeight()/2;
	
	for (int i = 0; i < 137.5; i++) {
		
		float radius3 = 10 + i * 2.2;
		
		float angle3 = ofGetElapsedTimef() * (1 + i /50.0);
		
		float x3 = xorig3 + radius3 * cos(angle3);
		float y3 = yorig3 + radius3 * sin(angle3);
		
		ofSetColor(255, 255, 255, 70);
		ofNoFill();
		ofCircle(x3, y3, (i-0.1));

	}

	float xorig4 = ofGetWidth()/2;
	float yorig4 = ofGetHeight()/2;;
	
	for (int i = 0; i < 137.5; i++){
		
		float radius4 = 10 + i * 2.2;
		float angle4 = ofGetElapsedTimef() * (1 + i /50.0);
		float x4 = xorig4 + radius4 * -cos(angle4);
		float y4 = yorig4 + radius4 * sin(angle4);
		
		
		ofSetColor(255, 255, 255, 70);
		ofNoFill();
		ofCircle(x4, y4, (i-0.1));
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