#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofBackground(10, 10, 50);
	
	for (int i = 0; i < 5000; i++){
		particle myParticle;
		float vx = ofRandom(-5,5);
		float vy = ofRandom(-5,5);
		
		myParticle.setInitialCondition(ofGetWidth()/2, ofGetHeight()/2,vx, vy);
		myParticle.damping = ofRandom(0.01, 0.05);
		particles.push_back(myParticle);
	}
	
}

//--------------------------------------------------------------
void testApp::update(){
	
	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
		// particles[i].addForce(0,-0.04);  // gravity
		particles[i].addDampingForce();
		particles[i].update();
	}
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}
	
}

//------------------------------------------------------------
bool testApp::extinct() {
	if(particles.size() == 0) {
		return true;
	} else {
		return false;
	}
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	for (int i = 0; i < particles.size(); i++){
		float vx = ofRandom(-5,5);
		float vy = ofRandom(-5,5);
		particles[i].setInitialCondition(mouseX,mouseY,vx, vy);	
		
	}
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
