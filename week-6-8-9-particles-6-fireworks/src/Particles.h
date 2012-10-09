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
	void setInitialCondition(float px, float py, float vx, float vy, float vz);
	void setDampingForce();
	void addForce(float x, float y);
	void resetForce();
	void setBurstRadius(float vx, float vy, float vz);
	
	ofVec3f initPos;
	ofVec3f vel;
	ofVec3f frc;
	
	
	bool lifeTime();
	bool hasExploded;
	
	
	float burstRadius;
	
	float time, maxspeed, mass, init, initSize, damping;
	float radius, q, x, y;
	float randmin, randmax;
	float a;

	int r, g, b;
	int counter;
	
	vector < Particles > happyTrails;

};

#endif // PARTICLES_H