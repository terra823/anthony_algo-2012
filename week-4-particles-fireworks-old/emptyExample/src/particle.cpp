/*
 *  particle.cpp
 *  emptyExample
 *
 *  Created by TERRA823 on 10/7/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */


#include "particle.h"
#include "ofMain.h"


//------------------------------------------------------------
particle::particle(){

	
	setInitialCondition(0,0,0,0);
	float randmin = -HALF_PI;
	float randmax = 0;
	
	damping = 0.01f;
	float r = ofRandom(0, TWO_PI);
	float x = cos(r);
	float y = sin(r);
	
	float q = ofRandom(0, 1);
	r = ofRandom(randmin, randmax);
	x = cos(r) * q;
	y = sin(r) * q;
	
	vel = ofPoint(x, y);
	
	frc = ofPoint(x / 250, y / 250);
}

//------------------------------------------------------------
void particle::resetForce(){
    // we reset the forces every frame
    frc.set(0,0);
}

//------------------------------------------------------------
void particle::addForce(float x, float y){
    // add in a force in X and Y for this frame.
    frc.x = frc.x + x;
    frc.y = frc.y + y;
}

//------------------------------------------------------------
void particle::addDampingForce(){
	
	// the usual way to write this is  vel *= 0.99
	// basically, subtract some part of the velocity 
	// damping is a force operating in the oposite direction of the 
	// velocity vector
	
    frc.x = frc.x - vel.x * damping;
    frc.y = frc.y - vel.y * damping;
}

//------------------------------------------------------------
void particle::setInitialCondition(float px, float py, float vx, float vy){
    pos.set(px,py);
	vel.set(vx,vy);
}



//------------------------------------------------------------
void particle::update(){	
	vel += frc;
	pos += vel;
}

//------------------------------------------------------------
void particle::draw(){


	initialSize = sqrt((vel.x + vel.y)/2 * (vel.x + vel.y)/2);	
	ofSetColor(255, 255, 200 + (frc.x + frc.y)*-2);
	ofCircle(pos.x, pos.y, initialSize);
	
}
			
