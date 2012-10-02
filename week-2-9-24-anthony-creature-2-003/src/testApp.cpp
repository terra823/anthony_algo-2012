#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
	ofBackground(0,0,0);
	ofSetCircleResolution(100);
	ofEnableAlphaBlending();
	
	
	for(int i = 0; i< 10; i++){
		myNodes.push_back(node());
	}
	
	
//	
//	for (int i = 0; i < 100; i++){
//		particle myParticle;
//		float vx = ofRandom(-40,40);
//		float vy = ofRandom(-40,40);
//		myParticle.setInitialCondition(ofGetWidth()/2,ofGetHeight()/2, vx, vy);
//		// more interesting with diversity :)
//		// uncomment this: 
//		myParticle.damping = ofRandom(0.01, 0.009);
//		particles.push_back(myParticle);
//	}
//	

	
}

//--------------------------------------------------------------
void testApp::update(){
	myNodes[0].xenoToPoint(mouseX, mouseY);
	for(int i=1; i<myNodes.size(); i++){
		myNodes[i].xenoToPoint(myNodes[i-1].pos.x, myNodes[i-1].pos.y);
	}
//	for (int i = 0; i < particles.size(); i++){
//		particles[i].resetForce();
//		particles[i].addForce(0,0.04);  // gravity
//		particles[i].addDampingForce();
//		particles[i].update();
//	}
}

//--------------------------------------------------------------
void testApp::draw(){

	for(int i=0; i<myNodes.size(); i++){
		myNodes[i].draw();
	}

//	for (int i = 0; i < particles.size(); i++){
//		
//		particles[i].draw();
//		
//	}
	
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
//	for (int i = 0; i < 100; i++){
//		particle myParticle;
//		float vx = ofRandom(-10,10);
//		float vy = ofRandom(-10,10);
//		myParticle.setInitialCondition(ofGetWidth()/2,ofGetHeight()/2,vx, vy);
//		// more interesting with diversity :)
//		// uncomment this: 
//		myParticle.damping = ofRandom(0.01, 0.009);
//		particles.push_back(myParticle);
//	}
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