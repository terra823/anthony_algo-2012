#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
	ofSetFrameRate(30);
	ofEnableAlphaBlending();
	
	//Styles
	ofBackground(12, 151, 244);

	
	for (int i = 0; i < 500; i++){
		Particles theParticles;
		vx = ofRandom(-4,4);
		vy = ofRandom(-4,4);
		
		theParticles.setInitialCondition(ofGetWidth()/2,ofGetHeight()/2,vx, vy);
		theParticles.damping = ofRandom(0.01, 0.03);
		particleVector.push_back(theParticles);
	}
	
	ofEnableSmoothing();
	ofSetCircleResolution(100);
}

//--------------------------------------------------------------
void testApp::update(){
	for (int i = 0; i < particleVector.size(); i++){
		particleVector[i].resetForce();
		//particleVector[i].addForce(0,0.04);  // gravity
		particleVector[i].setDampingForce();
		particleVector[i].update();
		
		
		
		
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	
	for (int i = 0; i < particleVector.size(); i++){
		particleVector[i].draw();
	}
	
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