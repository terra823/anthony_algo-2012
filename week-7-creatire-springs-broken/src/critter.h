/*
 *  critter.h
 *  springs
 *
 *  Created by TERRA823 on 12/3/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __muscles__critter__
#define __muscles__critter__

#include <iostream>
#include "ofMain.h"
#include "particle.h"
#include "spring.h"

class critter {
	
public:
	
	void setup(ofColor color, float size);
	void update();
	void draw();
	
	void createSpring(particle * p1, particle * p2);
	void repelMouse(float x, float y);
	
	ofPoint pos;
	float size;
	
	ofColor color;
	
	float sinOffset;
	
	vector <particle * > particles;
	vector <spring> springs;
	
	float mouseX, mouseY;
	
};

#endif /* defined(__muscles__critter__) */
