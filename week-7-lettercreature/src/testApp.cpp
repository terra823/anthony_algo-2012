#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
									  // U S U A L  S E T U P //
	
    ofBackground(0);
	ofSetVerticalSync(TRUE);
	//ofSetFrameRate(100);
    ofEnableAlphaBlending();
	//ofHideCursor();
	ofEnableSmoothing();
	

	color = ofRandom(0, 255);
	
    myLetterObject.theLetter = 'N';
    myLetterObject.startingX = 100;
    myLetters.push_back(myLetterObject);

    myLetterObject.theLetter = 'O';
    myLetterObject.startingX = 200;
    myLetters.push_back(myLetterObject);
    
	
    myLetterObject.theLetter = 'T';
    myLetterObject.startingX = 400;
    myLetters.push_back(myLetterObject);
    
	myLetterObject.theLetter = 'O';
    myLetterObject.startingX = 500;
    myLetters.push_back(myLetterObject);
	
    myLetterObject.theLetter = 'U';
    myLetterObject.startingX = 600;
    myLetters.push_back(myLetterObject);
    
    myLetterObject.theLetter = 'C';
    myLetterObject.startingX = 700;
    myLetters.push_back(myLetterObject);
    
	myLetterObject.theLetter = 'H';
    myLetterObject.startingX = 800;
    myLetters.push_back(myLetterObject);
	
    for(int i = 0; i < myLetters.size(); i++){
        myLetters[i].setup();
    }
    	
}

//--------------------------------------------------------------
void testApp::update(){


    
    for(int i = 0; i < myLetters.size(); i++){
        myLetters[i].mouseX = mouseX;
        myLetters[i].mouseY = mouseY;  
        myLetters[i].update();
    }	
}

//--------------------------------------------------------------
void testApp::draw(){

    
    for(int i = 0; i < myLetters.size(); i++){
		ofSetColor(255);	

        myLetters[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	
	
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	myLetters[whichLetterToMove].particles[0].pos.set(mouseX, mouseY);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	myLetters[whichLetterToMove].particles[0].bFixed = true;
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
	myLetters[whichLetterToMove].particles[0].bFixed = false;
}

