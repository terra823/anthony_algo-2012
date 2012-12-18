/*
 *  flocking.h
 *  vectorField_wParticles
 *
 *  Created by TERRA823 on 10/30/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef FLOCKING_H
#define FLOCKING_H

#include "ofMain.h"
#include "particle.h"
#include "vectorField.h"


class flocking {
public:
	flocking();
	void update();
	void draw();
	void addParticle();
	
	vector<particle*> particles;
};

#endif