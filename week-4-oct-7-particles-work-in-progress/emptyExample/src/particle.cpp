/*
 *  particle.cpp
 *  emptyExample
 *
 *  Created by TERRA823 on 10/4/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "particle.h"
#include "ofMain.h"

//------------------------------------------------------------
particle::particle(){
	setInitialCondition(0, 0, 0, 0);
	damping = 0.01f;
}


//------------------------------------------------------------

void particle::resetForce(){
	frc.set(0,0);
}


//------------------------------------------------------------
void particle::addForce(float x, float y){
	frc.x = frc.x + x;
	frc.y = frc.y + y;
}


//------------------------------------------------------------
void particle::addDampingForce(){
	frc.x = frc.x - vel.x * damping;
	frc.y = frc.y - vel.y * damping;
}


//------------------------------------------------------------
void particle::setInitialCondition(float px, float py, float vx, float vy){
	pos.set(px, py);
	vel.set(vx,vy);	
}

//------------------------------------------------------------
bool particle::setParticleLifespan(float lifespanOver){

	if (lifespanOver = ofGetElapsedTimef()+420.0f) {
		return TRUE;
	}
	else {
		return FALSE;
	}
	
	
	
}


//------------------------------------------------------------
void particle::update(){
	vel = vel + frc;
	pos = pos + vel;
}


//------------------------------------------------------------
void particle::draw(){
	ofCircle(pos.x, pos.y, 3);
}