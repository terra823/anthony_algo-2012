#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(TRUE);
	ofSetFrameRate(30);
	
	for (int i = 0; i < 10000; i++){
		particle myParticle;
		float vx = ofRandom(-4, 4);
		float vy = ofRandom(-4, 4);
		
		myParticle.setInitialCondition(300, 300, vx, vy);
		particles.push_back(myParticle);
		
	}
	
		
}

//--------------------------------------------------------------
void testApp::update(){
	for( int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
		particles[i].addDampingForce();
		particles[i].update();
		
	
	if (particles[i].setParticleLifespan(420.0f) == TRUE)

		particles.erase(particles.begin());
	}
}


//--------------------------------------------------------------
void testApp::draw(){
	ofSetColor(0x000000);
	
	for (int i = 0; i < particles.size(); i++) {
		particles[i].draw();
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
	for (int x; x < particles.size(); x++) {
		float vx = ofRandom(-4, 4);
		float vy = ofRandom(-4, 4);
		particles[x].setInitialCondition(mouseX, mouseY, vx, vy);
	}
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