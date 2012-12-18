#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	ofBackground(20, 20, 20);
	//	ofSetColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
	
	for (int i=0; i<50; i++) {
		
		myBall[i].posa.x = ofRandom(0,ofGetWidth());
		myBall[i].posa.y = ofRandom(0,ofGetHeight());
		
		myBall[i].redA=ofRandom(0, 255);
		myBall[i].greenA=ofRandom(0, 255);
		myBall[i].blueA=ofRandom(0, 255);
		
		myBall[i].radiusSizeA=ofRandom((ofGetElapsedTimef()/2), (ofGetElapsedTimef()*2));
		
		
		myBall[i].interpolateByPct(0);
		pct=0;
	}
	
	didHit=true;
	
	
}

//--------------------------------------------------------------
void testApp::update(){
	
	for (int i=0; i<50; i++) {
		
		if (didHit==true){
			myBall[i].posb.x = pointb[i].x;
			myBall[i].posb.y = pointb[i].y;
			pct += 0.001f;
		}
		
		if (didHit==false){
			myBall[i].posa.x = pointa[i].x;
			myBall[i].posa.y = pointa[i].y;
			pct -= 0.001f;
		}
		
		if (pct>1){
			pointa[i].x=ofRandom(0,ofGetWidth());
			pointa[i].y=ofRandom(0,ofGetHeight());
			myBall[i].redA=ofRandom(0, 255);
			myBall[i].greenA=ofRandom(0, 255);
			myBall[i].blueA=ofRandom(0, 255);
			myBall[i].radiusSizeA=ofRandom((ofGetElapsedTimef()/2), (ofGetElapsedTimef()*2));
			didHit=false;
		}
		
		if (pct<0) {
			pointb[i].x=ofRandom(0,ofGetWidth());
			pointb[i].y=ofRandom(0,ofGetHeight());
			myBall[i].redB=ofRandom(0, 255);
			myBall[i].greenB=ofRandom(0, 255);
			myBall[i].blueB=ofRandom(0, 255);
			myBall[i].radiusSizeB=ofRandom((ofGetElapsedTimef()/2), (ofGetElapsedTimef()*2));
			didHit=true;
		}
		
		
		myBall[i].interpolateByPct(pct);
		myBall[i].colorByPct(pct);
		myBall[i].radiusByPct(pct);
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	
	for (int i=0; i<50; i++) {
		myBall[i].draw();
	}	
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
	
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
	
}

