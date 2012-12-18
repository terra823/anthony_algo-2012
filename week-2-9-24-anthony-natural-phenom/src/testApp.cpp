#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofSetVerticalSync(true);
	ofBackground(10, 10, 50);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	
//CIRCLE FUNCTION 
	float xorig = 150;
	float yorig = 130;
	float angle = ofGetElapsedTimef()*3.5;
	float radius = 50;
	
	ofDrawBitmapString("This is a circle", 250,140);
	float x = xorig + radius * cos(angle);
	float y = yorig + radius * -sin(angle);	//for consistency, sin always has a negative (-)

	ofSetColor(255,255,255);
	
	ofPoint temp;
	temp.x = x;
	temp.y = y;
	
	
	points.push_back(temp);
	if(points.size() > 105){points.erase(points.begin());}
	
	ofNoFill();
	
	ofBeginShape();
	for (int i = 0; i < points.size(); i++){ofVertex(points[i].x, points[i].y);}
	for (int i = 0; i < points.size()+10; i++){ofVertex(xorig, yorig);}

	ofEndShape();
	
	
	
//HORIZONTAL WAVE FUNCTION 
	float xorig2 = 150;
	float yorig2 = 330;
	float angle2 = ofGetElapsedTimef()*3.5;
	float radius2 = 45;
	
	ofDrawBitmapString("This is a horizontal wave", 250,340);
	float x2 = xorig2 + radius2 * cos(angle2*5);  //for consistency, sin always has a negative (-)
	float y2 = yorig2 + radius2 * -sin(angle2);	
	
	ofSetColor(255,255,255);
	
	ofPoint temp2;
	temp2.x = x2;
	temp2.y = y2;
	
	
	points2.push_back(temp2);
	if(points2.size() > 50){points2.erase(points2.begin());}
	
	ofNoFill();
	
	ofBeginShape();
	for (int i = 0; i < points2.size(); i++){ofVertex(points2[i].x, points2[i].y);}
	for (int i = 0; i < points2.size()+10; i++){ofVertex(xorig2, yorig2);}

	ofEndShape();
	
	
	
//VERTICAL WAVE FUNCTION 
	float xorig3 = 630;
	float yorig3 = 330;
	float angle3 = ofGetElapsedTimef()*3.5;
	float radius3 = 45;
	
	ofDrawBitmapString("This is a vertical wave", 750,340);
	float x3 = xorig3 + radius3 * cos(angle3);  //for consistency, sin always has a negative (-)
	float y3 = yorig3 + radius3 * -sin(angle3*5);	
	
	ofSetColor(255,255,255);
	
	ofPoint temp3;
	temp3.x = x3;
	temp3.y = y3;
	
	
	points3.push_back(temp3);
	if(points3.size() > 50){points3.erase(points3.begin());}
	
	ofNoFill();
	
	ofBeginShape();
	for (int i = 0; i < points3.size(); i++){ofVertex(points3[i].x, points3[i].y);}
	for (int i = 0; i < points3.size()+10; i++){ofVertex(xorig3, yorig3);}

	ofEndShape();
	
	
//HORIZONTAL WAVE FUNCTION 
	float xorig4 = 150;
	float yorig4 = 630;

	float angle4 = ofGetElapsedTimef();
	float radius4 = 60;
	
	ofDrawBitmapString("This is a liquid wave", 250,840);
	float x4 = xorig4 + radius4 * cos(angle4*5);  //for consistency, sin always has a negative (-)
	float y4 = yorig4 + radius4 * atan(angle4);	
//	float z4 = zorig4 + radius4 * 	
	
	ofSetColor(255,255,255);
	
	ofPoint temp4;
	temp4.x = x4;
	temp4.y = y4;
	
	
	points4.push_back(temp4);
	if(points4.size() > 25){points4.erase(points4.begin());}

		
	ofNoFill();
	
	ofBeginShape();
	for (int i = 0; i < points4.size(); i++){ofVertex(points4[i].x, points4[i].y);}
	for (int i = 0; i < points4.size()+10; i++){ofVertex(xorig4, yorig4);}

	//Divide by 2 eases 
	ofEndShape();
	
	
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

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}