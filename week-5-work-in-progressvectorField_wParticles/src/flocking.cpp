/*
 *  flocking.cpp
 *  vectorField_wParticles
 *
 *  Created by TERRA823 on 10/30/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "flocking.h"

flocking::flocking() {
	
}

void flocking::update() {
	for(int i=0; i<particles.size(); i++) {
	}
}

void flocking::draw() {
	ofSetColor(0, 0, 0);
	for(int i=0; i<particles.size(); i++) {
		particles[i]->draw();
	}
}

void flocking::addParticle() {
	particles.push_back( new particle() );
}