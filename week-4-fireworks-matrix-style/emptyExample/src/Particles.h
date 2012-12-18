/*
 *  Particles.h
 *  emptyExample
 *
 *  Created by TERRA823 on 10/8/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef PARTICLES_H
#define PARTICLES_H

#include "ofMain.h"

class Particles{
	public:
		
	Particles();
	virtual ~Particles(){};

	void draw();
	void update();
	void setInitialCondition(float px, float py, float vx, float vy);
	void setDampingForce();
	void resetForce();

	bool lifeTime();
	
	ofVec2f initPos;
	ofVec2f vel;
	ofVec2f frc;
	
	ofPoint *hist;

	float time, maxspeed, mass, init, initSize, damping;
	
	float radius, q, x, y;
	
	float randmin, randmax;

	float a;

	int r, g, b;
	
	int counter;
};

#endif // PARTICLES_H