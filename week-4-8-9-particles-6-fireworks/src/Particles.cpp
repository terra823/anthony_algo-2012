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
	vel = ofPoint(x, y);	// velocity 
	burstRadius = 8.0;
	
	//pasPos = ;				// past position 
	//currPos = ;				// current position	
	
	time = 150.0;			// timer for lifetime	
	damping = 5.0f;		// adds back lost velocity

	randmin = -HALF_PI;
	randmax = 0;
	
	radius = ofRandom(-TWO_PI, TWO_PI);
	x = cos(radius);
	y = -sin(radius);
	
	radius = ofRandom(randmin, randmax);
	q = ofRandom(-1, 1);
	x = cos(radius) * q;
	y = sin(radius) * q;
	
	r = 255;
	g = 255;
	b = 255;
	a = 100;
	
	counter = 0;
	

	setInitialCondition(0,0,0,0,0);

}

//--------------------------------------------------------------
void Particles::draw(){

	ofSetColor(r, g, b, a);
    ofCircle(initPos.x, initPos.y, vel.x*.2 + vel.y*.2);
	
	ofBeginShape();
	ofNoFill();
	
	ofBeginShape();
	for (int i = 0; i < happyTrails.size(); i++){
		ofVertex(happyTrails[i].x, happyTrails[i].y);
	}
	ofEndShape();
	
}


//--------------------------------------------------------------
void Particles::setBurstRadius(float vx, float vy, float vz){
	 frc.set(ofRandom(-1, 1), ofRandom(-1, 1));
	 frc *= vel * (1.0 + ofRandom(-1, 0));
	
	
}

//--------------------------------------------------------------
void Particles::update(){
	vel += frc;
	initPos += vel;
	time -= 0.5;
	
	Particles myHappyTrails;
	myHappyTrails.x = initPos.x;
	myHappyTrails.y = initPos.y;
	happyTrails.push_back(myHappyTrails);
	
	
	if(happyTrails.size() > 10){
		happyTrails.erase(happyTrails.begin());
		}	
}

//------------------------------------------------------------
void Particles::addForce(float x, float y){
    // add in a force in X and Y for this frame.
    frc.x = frc.x + initPos.x;
    frc.y = frc.y + initPos.y;
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
void Particles::setInitialCondition(float px, float py, float vx, float vy, float vz){
	initPos.set(px, py);
	vel.set(vx, vy, vz);
}

//--------------------------------------------------------------
bool Particles::lifeTime(){
	if(time <= 0.0){ return TRUE; 
			} else {
					 return FALSE;
	}
}