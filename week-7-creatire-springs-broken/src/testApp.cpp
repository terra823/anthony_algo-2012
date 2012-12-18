#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofBackground(0,0,0);
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	
	
	
	particle myParticle;
	myParticle.setInitialCondition(100,200,0,0);
	particles.push_back(myParticle);
	
	myParticle.setInitialCondition(200,300,0,0);
	particles.push_back(myParticle);
	
	myParticle.setInitialCondition(300,400,0,0);
	particles.push_back(myParticle);
	
	myParticle.setInitialCondition(400,500,0,0);
	particles.push_back(myParticle);
	
	myParticle.setInitialCondition(500,600,0,0);
	particles.push_back(myParticle);
	
	myParticle.setInitialCondition(600,700,0,0);
	particles.push_back(myParticle);
	
	
	
	spring mySpring;
	
	for (int i = 0; i < particles.size(); i++){
		
		mySpring.distance		= 200;
		mySpring.springiness	= 0.3f;
		mySpring.particleA = & (particles[i  ]);
		mySpring.particleB = & (particles[(i+1) % particles.size()]);
		springs.push_back(mySpring);
		
		mySpring.distance		= (particles[0].pos-particles[1].pos).length();
		mySpring.springiness	= 0.02f;
		mySpring.particleA = & (particles[0]);
		mySpring.particleB = & (particles[1]);
		springs.push_back(mySpring);
		
		mySpring.distance		= (particles[2].pos-particles[3].pos).length();
		mySpring.springiness	= 0.02f;
		mySpring.particleA = & (particles[2]);
		mySpring.particleB = & (particles[3]);
		springs.push_back(mySpring);
		
		mySpring.distance		= (particles[4].pos-particles[5].pos).length();
		mySpring.springiness	= 0.02f;
		mySpring.particleA = & (particles[4]);
		mySpring.particleB = & (particles[5]);
		springs.push_back(mySpring);
		
	
		
	}
	
	

	
	
	
	
	
}

//--------------------------------------------------------------
void testApp::update(){

	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
	springs[0].distance = 100 + 50 * -sin(ofGetElapsedTimef()*8);
	springs[1].distance = 100 + 50 * cos(ofGetElapsedTimef()*8 + HALF_PI);
	springs[2].distance = 100 + 50 * cos(ofGetElapsedTimef()*8 + PI);
	springs[3].distance = 100 + 50 * cos(ofGetElapsedTimef()*8 + TWO_PI);
	
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
	}
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].addForce(0,0.1f);
		particles[i].addRepulsionForce(mouseX, mouseY, 300, 0.7f);
	}
	
	for (int i = 0; i < springs.size(); i++){
		springs[i].update();
	}
	
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].bounceOffWalls();
		particles[i].addDampingForce();
		particles[i].update();
	}
	
}

//--------------------------------------------------------------
void testApp::draw(){
	

	
	
	ofSetColor(0xffffff);
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}
	
	for (int i = 0; i < springs.size(); i++){
		springs[i].draw();
	}
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	switch (key){
			
		case ' ':
			// reposition everything: 
			for (int i = 0; i < particles.size(); i++){
				particles[i].setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
			}
			break;
	}
	
	
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	particles[0].pos.set(mouseX, mouseY);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	particles[0].bFixed = true;
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
	particles[0].bFixed = false;
}

