#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(60);
	ofEnableSmoothing();
	ofBackground(93,46,140,30);
	ofGetElapsedTimef();
	ofEnableAlphaBlending();
	
	brickWidth = 10;
	brickHeight = 10;
	cols = 20;
	rows = 20;
	columnOffset = 60;
	rowOffset = 60;
	rotationIncrement = 15;
	r = ofRandom(cos(-PI*20), -sin(PI*20));
	float counter = ofGetElapsedTimef() * .2;
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackgroundGradient(ofColor(3,166,136), ofColor(201,217,78), OF_GRADIENT_LINEAR);

	ofTranslate(30, 30, 30);
	for(int i = 0; i < cols; i++){
		ofPushMatrix();
		ofTranslate(i * columnOffset, 0, 0);
		int dir = 1;
		for(int j = 0; j < rows; j++){
			ofPushMatrix();
			
			ofTranslate(0, rowOffset * j, 0);
			ofRotate(ofRadToDeg(r), 0, 0, 1);
			
			ofNoFill();
			ofSetColor(255);
			ofCircle(-brickWidth/2, -brickHeight/2, 5*cos(ofGetElapsedTimef()*.2));
			
			
			ofNoFill();
			ofSetColor(255);
			ofCircle(-brickWidth/2, -brickHeight/2, 15*cos(ofGetElapsedTimef()*.4));

			
			ofNoFill();
			ofSetColor(255);
			ofCircle(-brickWidth/2, -brickHeight/2, 30*cos(ofGetElapsedTimef()*.6));
			
		
			
			ofFill();
			ofSetColor(255, 255, 255, 60);
			ofCircle(-brickWidth/2, -brickHeight/2, 50*cos(ofGetElapsedTimef()*.8));
			
			
			ofPopMatrix();
		}
		ofPopMatrix();
	}
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
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