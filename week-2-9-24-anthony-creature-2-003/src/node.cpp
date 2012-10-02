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
	
	
	float sinOfTime = sin( ofGetElapsedTimef() * 2 );
	float sinOfTimeMapped = ofMap( sinOfTime, -1, 1, 50, 80);
	
	
	float xorig = 150;
	float yorig = 130;
	float angle = ofGetElapsedTimef();
	float radius = 10;
	
	
	float x = xorig + radius * cos(angle*5);  //for consistency, sin always has a negative (-)
	float y = yorig + radius * -sin(angle);	
	
	
	ofPoint temp;
	temp.x = x;
	temp.y = y;
	
	points.push_back(temp);
	
	if(points.size() > 15){points.erase(points.begin());}
	
	
	for (int i = 0; i < points.size(); i++){
		for (int g=0; g<3; g++){

		ofPushMatrix();
		ofTranslate(pos.x, pos.y, 0);
		ofRotateZ(angle * RAD_TO_DEG);

		ofSetColor(255, 255, 255, sinOfTimeMapped-45);
		ofCircle(points[i].x,points[i].y, g*50);
		
		ofSetColor(sinOfTimeMapped+0, sinOfTimeMapped+80, sinOfTimeMapped+255, sinOfTimeMapped+0);
		ofCircle(points[i].x,points[i].y, g*30);
		
		ofSetColor(sinOfTimeMapped, sinOfTimeMapped+0, sinOfTimeMapped+255, sinOfTimeMapped-30);
		ofCircle(points[i].x,points[i].y, g*10);
		
		ofSetColor(sinOfTimeMapped+0, sinOfTimeMapped+0, sinOfTimeMapped+0, sinOfTimeMapped+0);
		ofCircle(points[i].x,points[i].y, g*5);
		ofPopMatrix();
	
	}
	
	}
	
	
}


//------------------------------------------------------------------
void node::xenoToPoint(float catchX, float catchY){
	catchUpSpeed = 0.5f;
	
	pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x; 
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y; 
}


