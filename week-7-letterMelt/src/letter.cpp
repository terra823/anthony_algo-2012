

//#include <iostream>
#include "letter.h"


letter::letter() {
    startingX = ofGetWidth()/2;
	

}



void letter::setup() {
	myFont.loadFont("WhitneyHTF-BlackSC.otf", 100, true,true,true);
    testChar = myFont.getCharacterAsPoints(theLetter);
    ofPolyline line;
    for(int k = 0; k < 1; k++){
        //if( k!= 0)ofNextContour(true) ;
        for(int i = 0; i < (int)testChar.getOutline()[k].size(); i++){
            ofPoint pos;
            pos.x = testChar.getOutline()[k].getVertices()[i].x;
            pos.y = testChar.getOutline()[k].getVertices()[i].y;
            line.addVertex(pos);
        }
    }
	line.addVertex(testChar.getOutline()[0][0]);
    
    ofPolyline lineResampled = line.getResampledBySpacing(10);
    
    
    

    
    lineResampled.draw();
    for (int i = 0; i < lineResampled.getVertices().size(); i++){
        float x = startingX + lineResampled.getVertices()[i].x;
		float y = 100 + lineResampled.getVertices()[i].y;
		particle myParticle;
		myParticle.setInitialCondition(x,y,0,0);
		particles.push_back(myParticle);
    }
    
    
	
	

	
	for (int i = 0; i < particles.size(); i++){
		spring mySpring;
		float dist = (particles[i].pos - particles[(i+20)%particles.size()].pos).length();
		
		mySpring.distance		= 200;
		mySpring.springiness	= 0.3f;
		mySpring.particleA = & (particles[i  ]);
		mySpring.particleB = & (particles[(i+1) % particles.size()]);
		springs.push_back(mySpring);
	}
	
	//particles[particles.size()-1].bFixed = true;

    
}



void letter::update() {
    
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
		particles[i].addForce(0,0.08);
	    particles[i].addRepulsionForce(mouseX, mouseY, 3, 1.5);
		particles[i].bounceOffWalls();
		particles[i].addDampingForce();
		particles[i].update();

	}
    
	
	for (int i = 0; i < springs.size(); i++){
		springs[i].update();

	}
	
	
	

}



void letter::draw() {
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].draw();
	}
	
	for (int i = 0; i < springs.size(); i++){
        springs[i].draw();
	
    }
	


}





