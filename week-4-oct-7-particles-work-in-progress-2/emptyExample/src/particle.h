/*
 *  particle.h
 *  emptyExample
 *
 *  Created by TERRA823 on 10/4/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */


#include "ofMain.h"

class particle{

	public:
	ofVec2f pos;
	ofVec2f vel;
	ofVec2f frc;
    
//	float lifespanOver;

	particle();
	virtual ~particle(){};

	void resetForce();
	void addForce(float x, float y);
	void addDampingForce();
	void setInitialCondition(float px, float py, float vx, float vy);
	void addSpin(float x, float y);
	
	
//	bool setParticleLifespan(float lifespanOver);

	
	void update();
	void draw();

	float damping;

	protected:
	private:
};

