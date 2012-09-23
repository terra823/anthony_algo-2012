/*
 *  rings.cpp
 *  emptyExample
 *
 *  Created by TERRA823 on 9/22/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */



#include "rings.h"


rings::rings(){
	shaper=2;
}


void rings::draw(){
	ofFill();	
	
	ofSetColor(red, green, blue, opacity); 
	ofCircle(ofGetWidth()/4, ofGetHeight()/4, radiusSize);
	
	ofFill();
	ofSetColor(red1, green1, blue1, opacity); 
	ofCircle(ofGetWidth()/4+ofGetWidth()/2, ofGetHeight()/4, radiusSize);
	
	ofFill();
	ofSetColor(red2, green2, blue2, opacity); 
	ofCircle(ofGetWidth()/4, ofGetHeight()/4+ofGetHeight()/2, radiusSize);
	
	ofFill();
	ofSetColor(red3, green3, blue3, opacity); 
	ofCircle(ofGetWidth()/4+ofGetWidth()/2, ofGetHeight()/4+ofGetHeight()/2, radiusSize);
	
	ofFill();
	ofSetColor(red4, green4, blue4, opacity); 
	ofCircle(ofGetWidth()/2, ofGetHeight()/2, radiusSize);
}




void rings::interpolateByPct(float pctr){
	pct = powf(pctr, shaper);
	radiusSize = (1-pct) * radiusSizeA + (pct) * radiusSizeB;
	
}


void rings::elapsedTimeByPct(float myPct){
	pct = powf(pct, shaper);
	elapsedTime = (1-pct) * ofGetElapsedTimef()*0 + (pct) * ofGetElapsedTimef();
}

