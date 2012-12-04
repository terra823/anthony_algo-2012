#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofBackground(255, 255, 255);
	
	for (int i = 0; i < 1000; i++){
		particle myParticle;
		myParticle.setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),10,10);
		particles.push_back(myParticle);
	}
	
	
	for (int i = 0; i < (particles.size()-1); i++){
		spring mySpring;
		mySpring.distance		= 25;
		mySpring.springiness	= 0.4f;
		mySpring.particleA = & (particles[i]);
		mySpring.particleB = & (particles[(i+1)%particles.size()]);
		springs.push_back(mySpring);
	}
	
	VF.setupField(60,40,ofGetWidth(), ofGetHeight());
	//VF.randomizeField(2.0);
	
	drawingStyle = 0;
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
		particles[i].addForce(frc.x, frc.y);
		particles[i].addDampingForce();
		particles[i].update();

	}
	
	
	if (bFade == true) VF.fadeField(0.99f);
	
	

}

//--------------------------------------------------------------
void testApp::draw(){
	

	
	ofEnableAlphaBlending();
	ofSetColor(0,130,130, 200);
	VF.draw();
	
	
	//This is the player
	ofSetColor(254, 4, 104);

	ofCircle(yourPos.x, yourPos.y, 3);
	VF.addInwardCircle(yourPos.x, yourPos.y, 50, 0.3f);

	
	
		
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}
	
	ofSetColor(0,130,130);
	ofRect(30,30,300,75);
	ofDrawBitmapString("space to clear\nchange drawing mode 'a'\ntoggle fade 'f'", 50, 50);
	
	
	ofSetColor(255,255,130, 50);
	switch (drawingStyle){
		case 0: ofDrawBitmapString("drawing mode: inward", 50, 90);
			break;
		case 1: ofDrawBitmapString("drawing mode: outward", 50, 90);
			break;
		case 2: ofDrawBitmapString("drawing mode: clockwise", 50, 90);
			break;
		case 3: ofDrawBitmapString("drawing mode: counter-clockwise", 50, 90); 
			break;
	}	
	
	
	
		
	
}

//--------------------------------------------------------------
void testApp::keyPressed (int key){ 
	
	if (key == ' '){
		VF.clear();
	} else if (key == 'a'){
		drawingStyle ++;
		drawingStyle %= 4;
	} else if (key == 'f'){
		bFade = !bFade;
	}
	
	switch (key){
			
			
		case '0':
		case '1':
		case '2':
			interpMethod = key - '0';
			break;
			
		case 356: // arrow left
			yourPos.x = yourPos.x - 10;
			break;
		case 358: // arrow right
			yourPos.x = yourPos.x + 10;
		
			
			break;
		case 357: // arrow up
			yourPos.y = yourPos.y - 10;
						
			break;
		case 359: // arrow down
			yourPos.y = yourPos.y + 10;
		
		
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
	if (button == 0) {
		switch (drawingStyle){
			case 0: VF.addInwardCircle((float)x, (float)y, 200, 0.3f);
				break;
			case 1: VF.addOutwardCircle((float)x, (float)y, 100, 0.3f);
				break;
			case 2: VF.addClockwiseCircle((float)x, (float)y, 100, 0.3f);
				break;
			case 3: VF.addCounterClockwiseCircle((float)x, (float)y, 100, 0.3f);
				break;
		}		
	} else {
		
		particles.erase(particles.begin());
		particle myParticle;
		myParticle.setInitialCondition(x,y,0,0);
		particles.push_back(myParticle);
		
		
	}
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
