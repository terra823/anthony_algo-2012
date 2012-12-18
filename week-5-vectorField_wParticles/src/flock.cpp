/*
 *  flock.cpp
 *  vectorField_wParticles
 *
 *  Created by TERRA823 on 10/30/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "flock.h"

flock::flock() {
	
}

void flock::update() {
	for(int i=0; i<particles.size(); i++) {
		particles[i]->update(particles);
	}
}

void flock::draw() {
	ofSetColor(0, 0, 0);
	for(int i=0; i<particles.size(); i++) {
		particles[i]->draw();
	}
}

void flock::addParticles() {
	particles.push_back( new particles() );
}


