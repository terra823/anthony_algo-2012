/*
 *  square.cpp
 *  emptyExample
 *
 *  Created by TERRA823 on 9/22/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */


#include "square.h"

square::square(){
	
	catchUpSpeed = 0.1f;
	
}

void square::draw(){
	ofFill();
	ofSetColor(red, green, blue, opacity); 
	ofRect(pos.x, pos.y, radiusSize, radiusSize);
	
	

}


void square::xenoToPoint(float catchX, float catchY){
	pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x; 
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y; 

}


