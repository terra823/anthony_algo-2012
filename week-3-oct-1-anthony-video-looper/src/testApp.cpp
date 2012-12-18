#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	mov.loadMovie("pai.mp4");

   ofSetBackgroundAuto(false);
   ofSetFrameRate(30);
    x = 0;
    y = 0;
	
	
	ofSetVerticalSync(true);
	TPR.setup();
	playbackStartTime = 0;
}

//--------------------------------------------------------------
void testApp::update(){
    mov.update();

}

//--------------------------------------------------------------
void testApp::draw(){
	
	
	TPR.draw();

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
		
			mov.setPosition(timeToCheck);
			mov.setSpeed(angle);

		
		
		
		//	
//			ofFill();
//			
//			ofSetRectMode(OF_RECTMODE_CENTER);
//			
//			ofPushMatrix();
//			ofTranslate(pos.x, pos.y, 0);
//			ofRotateZ(angle * RAD_TO_DEG);
//			//ofRect(0,0,50,50);
//			ofRect(0,0,50 + lengthVel/2.0,50);			// this does some stretching based on velocity.
//			ofPopMatrix();
			
		
		mov.draw(x,y);
		
		//if (mov.isFrameNew()) {
//			pos.x = pos.x + mov.getWidth();
//			
//			if (pos.x>ofGetWidth()) {
//				pos.x = 0;
//				pos.y = pos.y + mov.getHeight();
//			}
//			
//			if (pos.y>ofGetHeight()) {
//				pos.x = 0;
//				pos.y = 0;
//			}
//			
//				}
		

		
				
	}
	
}


//--------------------------------------------------------------

void testApp::videoSettings(){
	
	
	
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
	TPR.addPoint(x,y);


}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	TPR.endDrawing();
	playbackStartTime = ofGetElapsedTimef();


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