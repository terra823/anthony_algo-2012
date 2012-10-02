/*
 *  circles.cpp
 *  emptyExample
 *
 *  Created by TERRA823 on 9/30/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "circles.h"

void circles::draw(){

ofPushMatrix();
ofTranslate(pos.x, pos.y, 0);
ofRotateZ(angle * RAD_TO_DEG);

ofSetColor(255, 255, 255, sinOfTimeMapped-45);
ofCircle(points[i].x,points[i].y, g*50);

ofSetColor(sinOfTimeMapped+0, sinOfTimeMapped+80, sinOfTimeMapped+255, sinOfTimeMapped+0);
ofCircle(points[i].x,points[i].y, g*30);

ofSetColor(sinOfTimeMapped, sinOfTimeMapped+0, sinOfTimeMapped+255, sinOfTimeMapped-30);
ofCircle(points[i].x,points[i].y, g*10);

ofSetColor(sinOfTimeMapped+0, sinOfTimeMapped+0, sinOfTimeMapped+0, sinOfTimeMapped+0);
ofCircle(points[i].x,points[i].y, g*5);
ofPopMatrix();

}