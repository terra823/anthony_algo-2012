/*
 *  circle.h
 *  w1_hmwrk_fastest
 *
 *  Created by Adam Scher on 9/9/10.
 *  Copyright 2010 Adam Scher Dance and Design. All rights reserved.
 *
 */

#ifndef BALL_H
#define BALL_H

#include "ofMain.h"

class ball{
	
public:
	
	ball();
	
	void interpolateByPct(float myPct);
	void colorByPct(float myPct);
	void radiusByPct(float myPct);
	
	void draw();
	
	ofPoint pos;
	
	ofPoint posa;
	ofPoint posb;
	
	float pct;
	
	float shaper;
	
	float red;
	float green;
	float blue;
	
	float redA;
	float greenA;
	float blueA;
	
	float redB;
	float greenB;
	float blueB;
	
	float radiusSize;
	float radiusSizeA;
	float radiusSizeB;
	
};

#endif // BALL_H