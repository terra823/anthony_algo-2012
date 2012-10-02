#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	ofBackground(10, 10, 25);
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
	
	for (int i = 0; i < 70; i++) {
		
//		float radius = i^2;
//		
//		float angle = ofGetElapsedTimef() + (i);
//		
//		float x = xorig + radius * cos(angle);
//		float y = yorig + radius * -sin(angle);
//		
	//	ofSetColor( 0,255, 0, 10);
//		ofFill();		
//		ofCircle(x, y, (i-0.1));
		
		float xorig2 = ofGetWidth()/2;
		float yorig2 = ofGetHeight()/2;
		
		for (int g = 0; g < 5; g++) {
			
			float radius2 = g+i^2;
			
			float angle2 = ofGetElapsedTimef() + (i);
			
			float x2 = xorig2 + radius2 * cos(angle2);
			float y2 = yorig2 + radius2 * -sin(angle2);
			
			ofSetColor(0, 0, 255, 10);
			ofFill();		
			ofCircle(x2-90, y2-50, (g*i));
			
			
			
			ofSetColor(255, 255, 255, 10);
			ofNoFill();		
			ofCircle(x2-90, y2-50, (g*i)*1.2);
		}
	}
	

	
	
	
	
	

	float xorig3 = ofGetWidth()/2;
	float yorig3 = ofGetHeight()/2;
	
	for (int i = 0; i < 37.5; i++) {
		
		float radius3 = i^2;
		
		float angle3 = ofGetElapsedTimef() + (i);
		
		float x3 = xorig3 + radius3 * cos(angle3);
		float y3 = yorig3 + radius3 * -sin(angle3);
		
		ofSetColor(255, 0, 0, 7);
		ofFill();		
		ofCircle(x3+80, y3+50, (i-0.1));
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