/*
 *  spring.h
 *  vectorField_wParticles
 *
 *  Created by TERRA823 on 11/9/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SPRING_H
#define SPRING_H

#include "ofMain.h"

#include "particle.h"

class spring {
	
public:
	
	spring();
	
	particle * particleA;
	particle * particleB;
	
	float distance;
	float springiness;	 // this is the k, springiness constant
	
	void update();
	void draw();
	
	
};


#endif