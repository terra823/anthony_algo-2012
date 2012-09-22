#include "squarePusher.h"


//------------------------------------------------------------------
rectangle::rectangle(){
	
}

void rectangle::update(){

	
	pos.x = 30.0f/(1.0f/ofGetLastFrameTime());   


	
	
	
}

//------------------------------------------------------------------
void rectangle::draw() {
	
	int postionStart = 90;
	static float fastest = 0.0f;  
    static float slowest = 0.0f;  
	float i = 0;
	
	
	
    //Fastest  
	ofBeginShape();
	
	ofFill();
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
	ofEnableAlphaBlending();
	ofSetColor(217,4,121, 150);
    ofRect(postionStart+fastest,ofGetHeight()/2-40, 90, 90);  
	
	ofSetColor(255, 255, 255);
    ofRect(postionStart+fastest-20,ofGetHeight()/2-50, 15, 15);  
    ofRect(postionStart+fastest+20,ofGetHeight()/2-50, 15, 15);  
	ofTriangle(postionStart+fastest-20, ofGetHeight()/2-25, postionStart+fastest, ofGetHeight()/2-5, postionStart+fastest+20, ofGetHeight()/2-25);
	
	ofEndShape();
	
	
	

    //Slowest  
	ofBeginShape();

	ofFill();
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
	ofEnableAlphaBlending();
	ofSetColor(2,11,38, 200);
    ofRect(postionStart+slowest,ofGetHeight()/2-40, 90, 90); 
	
	ofSetColor(255, 255, 255);
    ofRect(postionStart+slowest-20,ofGetHeight()/2-50, 15, 15);  
    ofRect(postionStart+slowest+20,ofGetHeight()/2-50, 15, 15);  
	ofTriangle(postionStart+slowest-20, ofGetHeight()/2-10, postionStart+slowest, ofGetHeight()/2-25, postionStart+slowest+20, ofGetHeight()/2-10);
	
	ofEndShape();

	
	//Fastest Mover 
    fastest += pos.x*300;  
	
	
    //Slowest Mover  
    slowest += pos.x*.03;  
	
	
	

	
	
	
	
	//Reset

	if (fastest > ofGetWidth()) {
		fastest = 0;
//		i++;
		
	}
	
	
	if (postionStart+fastest > 0 && postionStart+fastest < 205) {ofFill(); ofSetColor(217, 4, 221); ofRect(postionStart, 0, ofGetWidth()/5, ofGetHeight()-190); }
	if (postionStart+fastest > 205 && postionStart+fastest < 410) {ofFill(); ofSetColor(217, 35, 153); ofRect(postionStart+205, 0, ofGetWidth()/5, ofGetHeight()-190); }
	if (postionStart+fastest > 410 && postionStart+fastest < 615) {ofFill(); ofSetColor(205, 163, 217); ofRect(postionStart+410, 0, ofGetWidth()/5, ofGetHeight()-190); }
	if (postionStart+fastest > 615 && postionStart+fastest < 820) {ofFill(); ofSetColor(2, 11, 38); ofRect(postionStart+615, 0, ofGetWidth()/5, ofGetHeight()-190); }
	if (postionStart+fastest > 820 && postionStart+fastest < 1025) {ofFill(); ofSetColor(187, 226, 242); ofRect(postionStart+820, 0, ofGetWidth()/5, ofGetHeight()-190); }
	if (postionStart+fastest > 1025 && postionStart+fastest < 2000) {ofFill(); ofSetColor(187, 226, 242); ofRect(postionStart+1025, 0, ofGetWidth()/5, ofGetHeight()-190); }
		
	
	
	
	if (postionStart+slowest > 0 && postionStart+slowest < 205) {ofFill(); ofSetColor(217, 4, 221); ofRect(postionStart, ofGetHeight()/2+300, ofGetWidth()/5, ofGetHeight()-190); }
	if (postionStart+slowest > 205 && postionStart+slowest < 410) {ofFill(); ofSetColor(217, 35, 153); ofRect(postionStart+205, ofGetHeight()/2+300, ofGetWidth()/5, ofGetHeight()-190); }
	if (postionStart+slowest > 410 && postionStart+slowest < 615) {ofFill(); ofSetColor(205, 163, 217); ofRect(postionStart+410, ofGetHeight()/2+300, ofGetWidth()/5, ofGetHeight()-190); }
	if (postionStart+slowest > 615 && postionStart+slowest < 820) {ofFill(); ofSetColor(2, 11, 38); ofRect(postionStart+615, ofGetHeight()/2+300, ofGetWidth()/5, ofGetHeight()-190); }
	if (postionStart+slowest > 820 && postionStart+slowest < 1025) {ofFill(); ofSetColor(187, 226, 242); ofRect(postionStart+820, ofGetHeight()/2+300, ofGetWidth()/5, ofGetHeight()-190); }
	if (postionStart+slowest > 1025 && postionStart+slowest < 2000) {ofFill(); ofSetColor(187, 226, 242); ofRect(postionStart+1025, ofGetHeight()/2+300, ofGetWidth()/5, ofGetHeight()-190); }
	
//	ofSetColor(255, 255, 255);
//	string info = "fps: " + ofToString(ofGetFrameRate(),2) 
//	+ "\nfastest: " + ofToString(fastest)
//	+ "\ncounter: " + ofToString(i);
//	ofDrawBitmapString(info, 10, ofGetHeight()-40);
//	
//	
//	if (slowest > ofGetWidth()) {
//		slowest = 0;
//	}
//	
//	
	
	
	
}




