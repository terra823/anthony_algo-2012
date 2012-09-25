#include "testApp.h"


int recieverX;
int recieverY;

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	ofBackground(255, 255, 255);
	ofSetColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
	
	clicked=false;
	
	squared.pos_a.x = 0;
	squared.pos_a.y = 0;
	squared.pos_b.x = 0;
	squared.pos_b.y = 0;
	squared.xenoToPoint(0);
	pct=0;
	
	
	
}

//--------------------------------------------------------------
void testApp::update(){
	
	pct += 0.01f;
	if (pct > 1) {
		pct = 0;
	}
	squared.xenoToPoint(pct);
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	squared.draw();
	
	
	
	

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

	if (clicked==true) {
		squared.pos_a.x=mouseX;
		squared.pos_a.y=mouseY;
		
		clicked=false;
		ofSetColor(150, 55, 111);
		ofCircle(mouseX, mouseY, 40);
	}
	else {
		squared.pos_b.x=mouseX;
		squared.pos_b.y=mouseY;
		clicked=true;
	}
	
	
	mouseX = x;
	mouseY = y;
	
	
	

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
	
}

