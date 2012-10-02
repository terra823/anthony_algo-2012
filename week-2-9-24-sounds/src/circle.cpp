/*
 *  circle.cpp
 *  emptyExample
 *
 *  Created by TERRA823 on 9/28/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */



#include "circle.h"


//------------------------------------------------------------------
circle::circle(){
	
	catchUpSpeed = 0.1f;

}


//--------------------------------------------------------------
void circle::draw(float xorig, float yorig, float originalRadius, float radiusSize, float sinOfTime, float sinOfTimeMapped){
	//	for (int i=0; i<500; i++) {
	//		myCircles[i].draw();
	//	}
	//	
	
	 xorig = ofGetWidth()/2;
	 yorig = ofGetHeight()/2;
	
	//	float angle = ofGetElapsedTimef();
	 originalRadius = 1;
	
		
	
	
		
	
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
	for (int i = 0; i < myCircles.size(); i+=5){ofCircle(xorig/2+300, yorig, myCircles[i].radiusSize);}
	ofEndShape();
	
	
	
	ofSetColor(30+sinOfTimeMapped*.05, 5+sinOfTimeMapped*.05, 255+sinOfTimeMapped*.05, 3); 
	
	ofBeginShape();
	for (int i = 0; i < myCircles.size(); i+=5){ofCircle(xorig+xorig/2-300, yorig, myCircles[i].radiusSize);}
	ofEndShape();
	
	
	
	
	ofSetColor(10+sinOfTimeMapped*.05, 255+sinOfTimeMapped*.05, sinOfTimeMapped+20*.05, 3); 
	
	ofBeginShape();
	for (int i = 0; i < myCircles.size(); i+=5){ofCircle(xorig, yorig/2+100, myCircles[i].radiusSize);}
	ofEndShape();
	
	
	
	
	
	ofSetColor(255+sinOfTimeMapped*.05, 5+sinOfTimeMapped*.05, 20+sinOfTimeMapped*.5, 3); 
	
	ofBeginShape();
	for (int i = 0; i < myCircles.size(); i+=5){ofCircle(xorig, yorig+yorig/2-100, myCircles[i].radiusSize);}
	ofEndShape();
	
	
}





//------------------------------------------------------------------
void circle::xenoToPoint(float radiusSize){
	radiusSize = catchUpSpeed * radiusSize + (1-catchUpSpeed) * radiusSize; 
	
}