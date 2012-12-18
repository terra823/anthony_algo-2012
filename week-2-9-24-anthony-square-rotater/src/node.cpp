/*
 *  node.cpp
 *  emptyExample
 *
 *  Created by TERRA823 on 9/26/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "node.h"

node::node(){
	catchUpSpeed = 0.5f;
}


//------------------------------------------------------------------
void node::draw() {
	
	
	float sinOfTime = sin( ofGetElapsedTimef());
	float sinOfTimeMapped = ofMap( sinOfTime, -1, 1, 150, 90);
	
	
	float xorig = 150;
	float yorig = 130;
	float angle = ofGetElapsedTimef()/4;
	float radius = 5;
	
	
	float x = xorig + radius * cos(angle);  //for consistency, sin always has a negative (-)
	float y = yorig + radius * -sin(angle*.01);	
	
	
	ofPoint temp;
	temp.x = x;
	temp.y = y;
	
	points.push_back(temp);
	
	if(points.size() > 15){points.erase(points.begin());}
	
	
	for (int i = 0; i < points.size(); i++){
		
		ofPushMatrix();
		ofTranslate(pos.x, pos.y, 0);
//		ofRotateZ(angle * RAD_TO_DEG);

		ofRotateZ(angle*RAD_TO_DEG);
		ofSetColor(255, 255, 255, ofRandom(12, 70));
		ofRect(points[i].x,points[i].y, 100, 100);
		
		ofRotateZ(angle*RAD_TO_DEG);
		ofSetColor(sinOfTimeMapped+255, sinOfTimeMapped+0, sinOfTimeMapped+0, ofRandom(12, 70));
		ofRect(points[i].x,points[i].y, 100, 100);
		
		ofRotateZ(angle*RAD_TO_DEG);
		ofSetColor(sinOfTimeMapped+0, sinOfTimeMapped+0, sinOfTimeMapped+255, ofRandom(12, 70));
		ofRect(points[i].x,points[i].y,  100, 100);
		
		ofRotateZ(angle*RAD_TO_DEG);
		ofSetColor(sinOfTimeMapped+0, sinOfTimeMapped+255, sinOfTimeMapped+0, ofRandom(12, 70));
		ofRect(points[i].x,points[i].y, 100, 100);
		ofPopMatrix();
	
	}
	
	
	
	
}


//------------------------------------------------------------------
void node::xenoToPoint(float catchX, float catchY){
	catchUpSpeed = 0.5f;
	
	pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x; 
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y; 
}


