#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
	ofBackground(10, 10, 10);
	ofEnableAlphaBlending();
	ofSetCircleResolution(100);
	ofEnableSmoothing();
	

}

//--------------------------------------------------------------
void testApp::update(){
	
	//algo - 4numbers
	
	
	}

//--------------------------------------------------------------
void testApp::draw(){
//	for (int i=0; i<500; i++) {
//		myCircles[i].draw();
//	}
//	

	float xorig = ofGetWidth()/2;
	float yorig = ofGetHeight()/2;
//	float angle = ofGetElapsedTimef();
	float originalRadius = 1;
	
	float sinOfTime = cos( ofGetElapsedTimef()*.8) + -sin(ofGetElapsedTimef()*5.14)*.5;
	float sinOfTimeMapped = ofMap(sinOfTime, -3, 1, -5*sinOfTime, 400);
	




	
	circle temp;
	temp.radiusSize = sinOfTimeMapped;
	

	
	myCircles.push_back(temp);
	if(myCircles.size() > 50){myCircles.erase(myCircles.begin());}

	
	
	
	
	ofNoFill();
	ofSetColor(255, 255, 255, 45); 

	
	ofBeginShape();
	for (int i = 0; i < myCircles.size()/2; i+=3){ofCircle(xorig/2+300, yorig, myCircles[i].radiusSize-2);}
	ofEndShape();

	
	ofBeginShape();
	for (int i = 0; i < myCircles.size()/2; i+=3){ofCircle(xorig+xorig/2-300, yorig, myCircles[i].radiusSize-2);}
	ofEndShape();
	
	ofBeginShape();
	for (int i = 0; i < myCircles.size()/2; i+=3){ofCircle(xorig, yorig/2+300, myCircles[i].radiusSize-2);}
	ofEndShape();
	
	ofBeginShape();
	for (int i = 0; i < myCircles.size()/2; i+=3){ofCircle(xorig, yorig+yorig/2-300, myCircles[i].radiusSize-2);}
	ofEndShape();
	
	

	
	ofFill();
	
	ofSetColor(255+sinOfTimeMapped*.05, 255+sinOfTimeMapped*.05, 10+sinOfTimeMapped*.05, 3); 
	
	
	ofBeginShape();
	for (int i = 0; i < myCircles.size(); i+=10){ofCircle(xorig/2+300, yorig, myCircles[i].radiusSize);}
	ofEndShape();
	
	
	
	ofSetColor(30+sinOfTimeMapped*.05, 5+sinOfTimeMapped*.05, 255+sinOfTimeMapped*.05, 3); 

	ofBeginShape();
	for (int i = 0; i < myCircles.size(); i+=10){ofCircle(xorig+xorig/2-300, yorig, myCircles[i].radiusSize);}
	ofEndShape();
	
	
	
	
	ofSetColor(10+sinOfTimeMapped*.05, 255+sinOfTimeMapped*.05, sinOfTimeMapped+20*.05, 3); 

	ofBeginShape();
	for (int i = 0; i < myCircles.size(); i+=10){ofCircle(xorig, yorig/2+100, myCircles[i].radiusSize);}
	ofEndShape();
	
	
	
	
	
	ofSetColor(255+sinOfTimeMapped*.05, 5+sinOfTimeMapped*.05, 20+sinOfTimeMapped*.5, 3); 

	ofBeginShape();
	for (int i = 0; i < myCircles.size(); i+=10){ofCircle(xorig, yorig+yorig/2-100, myCircles[i].radiusSize);}
	ofEndShape();
	
	
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