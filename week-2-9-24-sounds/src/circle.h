/*
 *  circle.h
 *  emptyExample
 *
 *  Created by TERRA823 on 9/28/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef CIRCLE_H
#define CIRCLE_H

#include "ofMain.h"

class circle{	
public:
	
	circle();
	void draw(float xorig, float yorig, float originalRadius, float radiusSize, float sinOfTime, float sinOfTimeMapped);
	void xenoToPoint(float radiusSize);
	
	ofPoint pos;
	float catchUpSpeed;
	float radiusSize;
	

	
	
	vector < circle > myCircles;



};

#endif 