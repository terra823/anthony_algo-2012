/*
 *  particle.cpp
 *  emptyExample
 *
 *  Created by TERRA823 on 9/26/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */



#include "particle.h"
#include "ofMain.h"


//------------------------------------------------------------
particle::particle(){
	setInitialCondition(0,0,0,0);
	damping = ofGetElapsedTimef()/2;
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
	vel = vel + frc;
	pos = pos + vel;
}

//------------------------------------------------------------
void particle::draw(){
	
	int alpha = ofRandom(30,100);
	ofSetColor(255, 205, 200, alpha);
    ofCircle(pos.x, pos.y, 1.5);
}

