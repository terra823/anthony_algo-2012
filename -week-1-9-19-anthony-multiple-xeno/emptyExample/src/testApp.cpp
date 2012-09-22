#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
	ofBackground(50, 50, 50);
	ofEnableAlphaBlending();
	
	for (int i=0; i<100; i++) {
		
		squared[i].pos.x = ofGetWidth()/2;
		squared[i].pos.y = ofGetHeight()*2;
		
		squared[i].radiusSize = 100+i;
		
		squared[i].red = ofRandom(0, 255)+23;
		squared[i].green= ofRandom(0, 255)+255;
		squared[i].blue = ofRandom(0, 255)+0;
		


		squared[i].opacity = i;

		squared[i].catchUpSpeed = .2f;
	}
	
}

//--------------------------------------------------------------
void testApp::update(){
	squared[0].xenoToPoint(mouseX, mouseY);
	
	for (int i=1; i<50; i++) {
		squared[i].xenoToPoint(squared[i-1].pos.x, squared[i-1].pos.y);
	}
	
	
	
	//for (red1=0;red1<23;red1++)  
	//		for (green1=0;green1<55;green1++)  
	//		{  
	//			colorArray[red1][green1]=(red1+1)*(green1+1);  
	//		}  
	//	
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	for (int i=0; i<500; i++) {
		squared[i].draw();
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

	
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}


