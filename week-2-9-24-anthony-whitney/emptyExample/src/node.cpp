/*
 *  node.cpp
 *  emptyExample
 *
 *  Created by TERRA823 on 9/24/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "node.h"


node::node(){
	catchUpSpeed = 0.1f;

}

void node::draw(){
	ofFill();
	ofSetColor(255, 255, 255);
	ofCircle(pos.x, pos.y, 3);
	ofLine(pos.x, pos.y, pos.x+500, pos.y+500);
}


void node::xenoToPoint(float catchX, float catchY){
	pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x; 
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y; 
	
}

