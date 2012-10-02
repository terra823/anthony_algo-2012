#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofSetVerticalSync(true);

	ofBackground(0, 0, 0);
	TPR.setup();
	playbackStartTime = 0;
	
	mov.loadMovie("pai.mp4");
	
	ofSetFrameRate(30);

}


//--------------------------------------------------------------
void testApp::update(){
    mov.update();

}

//--------------------------------------------------------------
void testApp::draw(){



	// -------------------------- draw the line
	TPR.draw();
	
	
	// -------------------------- draw the point at the current time
	if (TPR.bHaveADrawing()){			// if we have a drawing to work with
		
		// figure out what time we are at, and make sure we playback cyclically (!)
		// use the duration here and make sure our timeToCheck is in the range of 0 - duration
		float timeToCheck = ofGetElapsedTimef() - playbackStartTime;
		while (timeToCheck > TPR.getDuration() && TPR.getDuration() > 0){
			timeToCheck -= TPR.getDuration();
		}
		
		// get the position and velocity at timeToCheck
		ofPoint pos = TPR.getPositionForTime(timeToCheck);
		ofPoint vel = TPR.getVelocityForTime(timeToCheck);
		
		float angle = atan2(vel.y, vel.x);
		float lengthVel = ofDist(0,0,vel.x, vel.y);
		
		
		
		mov.play();		
		mov.setPosition(timeToCheck*.02);
		mov.setSpeed(angle);
		mov.draw(ofGetWidth()/2,ofGetHeight()/2);


		
		
		
		
//		ofSetRectMode(OF_RECTMODE_CENTER);
		
		ofPushMatrix();
			ofFill();
			ofTranslate(pos.x, pos.y, 0);
			ofRotateZ(angle * RAD_TO_DEG);
			//ofRect(0,0,50,50);
			ofCircle(0,0,lengthVel/2.0);			// this does some stretching based on velocity.
		ofPopMatrix();
	
	
		
		
	}
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	TPR.addPoint(x,y);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	TPR.startDrawing(x,y);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	TPR.endDrawing();
	playbackStartTime = ofGetElapsedTimef();
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}



