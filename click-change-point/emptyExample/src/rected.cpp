#include "rected.h"


//------------------------------------------------------------------
rectangle::rectangle(){
	catchUpSpeed = 0.03f;
}

//------------------------------------------------------------------
void rectangle::draw() {

	
	
	ofBeginShape();
	
	ofFill();
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(198,246,55);
    ofRect(pos.x, pos.y, 90,90);
	
	ofSetColor(5, 5, 25);
    ofRect(pos.x-20,pos.y-30, 15, 15);  
    ofRect(pos.x+20,pos.y-30, 15, 15);  
	ofTriangle(pos.x-20, pos.y-15, pos.x, pos.y-5, pos.x+20, pos.y-15);
	

	ofEndShape();
	
	string phrase = " " + ofToString("where're you going?");
	ofSetColor(200,5,5);
	ofDrawBitmapString(phrase, pos.x+50, pos.y);
}

//------------------------------------------------------------------
void rectangle::xenoToPoint(float catchX, float catchY){
	pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x; 
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y; 
}


//------------------------------------------------------------------

void rectangle::mousePressed() {

}

//------------------------------------------------------------------

void rectangle::mouseReleased() {

	
}