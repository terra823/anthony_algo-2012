/*
 *  Particles.cpp
 *  emptyExample
 *
 *  Created by TERRA823 on 10/8/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "Particles.h"
#include "ofMain.h" 


Particles::Particles(){
	//Every Particle needs the following
	
	frc = 0;		// force or acceleration 
	vel = ofPoint(x, y);

	initSize = .9;			// an initial size 
	mass = 1.0;				// a mass	
	time = 200.0;			// timer for lifetime	
	damping = 0.05f;		// adds back lost velocity

	randmin = -HALF_PI;
	randmax = 0;
	
	radius = ofRandom(-TWO_PI, TWO_PI);
	x = cos(radius);
	y = -sin(radius);
	
	radius = ofRandom(randmin, randmax);
	q = ofRandom(-1, 1);
	x = cos(radius) * q;
	y = sin(radius) * q;
	
	r = 250;
	g = 250;
	b = 250;
	a = time;
	
	counter = 0;

	setInitialCondition(0,0,0,0);

}

//--------------------------------------------------------------
void Particles::draw(){

	ofSetColor(r, g, b, a);
    ofCircle(initPos.x, initPos.y, vel.x*10 + vel.y*10);
	
	

}


//--------------------------------------------------------------
void Particles::update(){

	vel += frc;
	initPos += vel;
	
	
	time -= 0.5;
	

}

//------------------------------------------------------------
void Particles::resetForce(){
    // we reset the forces every frame
    frc.set(0,0);
	

}

//--------------------------------------------------------------
void Particles::setDampingForce(){
	frc.x = frc.x - vel.x * damping;
	frc.y = frc.y - vel.y * damping;
}


//--------------------------------------------------------------
void Particles::setInitialCondition(float px, float py, float vx, float vy){
	initPos.set(px, py);
	vel.set(vx, vy);
}

//--------------------------------------------------------------
bool Particles::lifeTime(){
	if(time <= 0.0){ return TRUE; 
			} else {
					 return FALSE;
	}
}