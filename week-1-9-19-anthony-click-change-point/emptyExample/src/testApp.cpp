#include "testApp.h"
#include "ofMain.h"

///This sketch was compiling janky. if it loads all white, compile again...



//--------------------------------------------------------------
void testApp::setup(){
	
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	
	ofSetVerticalSync(true);
	
	// set background: 
	
	ofEnableAlphaBlending();
	ofBackground(255,255,255);
	
	
	// set the position of the rectangle:
	
	rected.pos.x = 100;
	rected.pos.y = 50;
		
}

//--------------------------------------------------------------
void testApp::update(){
	rected.xenoToPoint(food_x, food_y);

	}

//--------------------------------------------------------------
void testApp::draw(){
	rected.draw();

	
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
	food_x = x;
	food_y = y;

	rected.mouseReleased();

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