/*
 *  flock.h
 *  vectorField_wParticles
 *
 *  Created by TERRA823 on 10/30/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef FLOCK_H
#define FLOCK_H

#include "ofMain.h"
#include "particle.h"

class flock {
public:
	flock();
	void update();
	void draw();
	void addParticle();
	
	vector<particle*> particles;
};

#endif