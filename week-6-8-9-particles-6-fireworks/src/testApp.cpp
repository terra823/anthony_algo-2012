#include "testApp.h"



//--------------------------------------------------------------
void testApp::setup(){
	
	bool explode = false;
	
	ofSetVerticalSync(TRUE);
	ofSetFrameRate(30);
	ofEnableAlphaBlending();
	ofEnableSmoothing();
	ofSetCircleResolution(100);
	
	t = ofGetHeight();

		
	//Styles
	ofBackground(12, 151, 244);

	for (int i = 0; i < 500; i++){
		Particles theParticles;
		vx = ofRandom(-4,4);
		vy = ofRandom(-4,4);
		theParticles.setInitialCondition(ofGetWidth()/2,ofGetHeight()/2,vx, vy, vz);
		theParticles.damping = ofRandom(0.01, 0.03);
		particleVector.push_back(theParticles);

	
		}
	

	
	
	
	if(t > 10 -  ofGetHeight()/2){
		
		bool explode = true;  } else { bool explode = false; 
			
		}
	
}





//--------------------------------------------------------------
void testApp::update(){
		
	if (t > ofGetHeight()/2) {t--;}

	
	for (int i = 0; i < particleVector.size(); i++){
		particleVector[i].resetForce();
		particleVector[i].addForce(0,0.4);  // gravity
		particleVector[i].setDampingForce();
		particleVector[i].setBurstRadius(vx, vy, vz);

		
		particleVector[i].update();
		
		
	}
	
	
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofSetColor(255, 255, 255);
//	ofCircle(ofGetWidth()/2, t, 3);
	
	if (bool explode = true) {

	for (int i = 0; i < particleVector.size(); i++){
		particleVector[i].draw();
	}
	
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
	for (int i = 0; i < particleVector.size(); i++){
		float vx = ofRandom(-4,4);
		float vy = ofRandom(-4,4);
		particleVector[i].setInitialCondition(mouseX,mouseY,vx, vy, vz);

	}

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