/*
 *  circle.cpp
 *  w1_hmwrk_fastest
 *
 *  Created by Adam Scher on 9/9/10.
 *  Copyright 2010 Adam Scher Dance and Design. All rights reserved.
 *
 */

#include "ball.h"

ball::ball(){
	
	shaper=2;
	
}

void ball::draw(){
	ofFill();
	ofSetCircleResolution(200);
	ofSetColor(red,blue,green);
	ofCircle(pos.x, pos.y, radiusSize);
}

void ball::interpolateByPct(float myPct){
	
	pct = powf(myPct, shaper);
	pos.x = (1-pct) * posa.x + (pct) * posb.x;
	pos.y = (1-pct) * posa.y + (pct) * posb.y;
}

void ball::colorByPct(float myPct){
	
	pct = powf(myPct, shaper);
	red = (1-pct) * redA + (pct) * redB;
	blue = (1-pct) * blueA + (pct) * blueB;
	green = (1-pct) * greenA + (pct) * greenB;
}

void ball::radiusByPct(float myPct){
	pct = powf(myPct, shaper);
	radiusSize = (1-pct) * radiusSizeA + (pct) * radiusSizeB;
}
