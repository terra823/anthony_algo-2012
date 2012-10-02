/*
 *  node.h
 *  emptyExample
 *
 *  Created by TERRA823 on 9/26/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef NODE_H
#define NODE_H

#include "ofMain.h"

class node {
public:
	
	node();
	void draw();
	void xenoToPoint(float catchX, float catchY);
	
	vector <ofPoint> points;
	ofPoint		pos;
	
	int   interpMethod; 
	float catchUpSpeed;			
	
};

#endif 
