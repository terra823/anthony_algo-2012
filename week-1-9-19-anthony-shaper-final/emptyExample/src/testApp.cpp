#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
	ofBackground(10,10,10);
	ofSetCircleResolution(100);
	ofEnableAlphaBlending();
	for (int i=0; i<50; i++) {

		myRings[i].radiusSizeA=myRings[i].elapsedTime;

		myRings[i].interpolateByPct(pct);
		myRings[i].opacity = i*.1;
		
		myRings[i].red4 = ofRandom(0, 255)+255;
		myRings[i].green4= ofRandom(0, 255)+255;
		myRings[i].blue4 = ofRandom(0, 255)+255;
		
		myRings[i].red1 = ofRandom(0, 255)+28;
		myRings[i].green1= ofRandom(0, 255)+255;
		myRings[i].blue1 = ofRandom(0, 255)+85;
		
		myRings[i].red2 = ofRandom(0, 255)+18;
		myRings[i].green2= ofRandom(0, 255)+255;
		myRings[i].blue2 = ofRandom(0, 255)+252;
	
		myRings[i].red3 = ofRandom(0, 255)+242;
		myRings[i].green3= ofRandom(0, 255)+206;
		myRings[i].blue3 = ofRandom(0, 255)+27;
		
		myRings[i].red = ofRandom(0, 255)+232;
		myRings[i].green= ofRandom(0, 255)+44;
		myRings[i].blue = ofRandom(0, 255)+12;

		pct=0;

	}
	
}

//--------------------------------------------------------------
void testApp::update(){
	for (int i=0; i<50; i++) {
		
		pct += 0.001f;

		if (pct<0) {myRings[i].radiusSizeB=myRings[i].elapsedTime;
}
		
		myRings[i].interpolateByPct(pct);
		myRings[i].opacity = i*.1;

		
	}
}
	


//--------------------------------------------------------------
void testApp::draw(){
	
	for (int i=0; i<50; i++) {
		myRings[i].draw();
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