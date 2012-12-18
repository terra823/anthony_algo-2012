#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofBackground(255);
	
	
	for (int i = 0; i < 100; i++){
		particle myParticle;
		myParticle.setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
		particles.push_back(myParticle);
	}
	
	VF.setupField(ofGetWidth(),ofGetWidth(),ofGetWidth(), ofGetHeight());
	VF.randomizeField(2.0);
	bParticlesRepel = true;
	bFade = false;
}

//--------------------------------------------------------------
void testApp::update(){
	
	// on every frame 
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].resetForce();
		
		// get the force from the vector field: 
		ofVec2f frc;
		frc = VF.getForceFromPos(particles[i].pos.x, particles[i].pos.y);
		particles[i].addForce(sin(frc.x), frc.y);
		
		if (bParticlesRepel == true){
			for (int j = 0; j < i; j++){
				particles[i].addRepulsionForce(particles[j], 50, 0.2);
			}
		}
		
		particles[i].addForce(0,0.4f);
		particles[i].addDampingForce();
		particles[i].update();
		
		if (particles[i].pos.y > ofGetHeight()){
			particles[i].pos.x = ofRandom(0,ofGetWidth());
			particles[i].pos.y = 0;
			
		}
	}
	
	
	if (bFade == true) VF.fadeField(0.99f);
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofEnableAlphaBlending();
	//ofSetColor(0,130,130, 200);
	
	//VF.draw();
	
	//ofSetColor(50,100,255,100);
	
	for (int i = 0; i < particles.size(); i++){
		ofSetColor(particles[i].vel.x, particles[i].vel.x, particles[i].vel.x);
		//particles[i].update();

		//particles[i].draw();
				for (int j = 0; j < i; j++){
					ofSetColor(0, 0, 0, 5);
					ofLine(particles[i].pos.x, particles[i].pos.y, particles[j].pos.x, particles[j].pos.y);
				}
		
	}
	
	//ofSetColor(0,130,130, 200);
//	ofRect(30,30,300,75);
//	ofSetColor(255,255,255, 230);
//	ofDrawBitmapString("space to clear\ntoggle fade 'f'\ntoggle repel 'r'", 50, 50);
//	
//	
//	ofSetColor(255,255,130, 230);
	
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	if (key == ' '){
		VF.clear();
	} else if (key == 'f'){
		bFade = !bFade;
	} else if (key == 'r'){
		bParticlesRepel = !bParticlesRepel;
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
	
	float diffx = x - prevMouseX;
	float diffy = y - prevMouseY;
	VF.addVectorCircle((float)x, (float)y, diffx*0.3, diffy*0.3, 60, 0.3f);
	prevMouseX = x;
	prevMouseY = y;
	
	if (button == 0) {
		VF.addOutwardCircle((float)x, (float)y, 100, 0.29f);
	} else {
		
		particles.erase(particles.begin());
		particle myParticle;
		myParticle.setInitialCondition(x,y,0,0);
		particles.push_back(myParticle);
		
		
	}
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	prevMouseX = x; 
	prevMouseY = y;
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
