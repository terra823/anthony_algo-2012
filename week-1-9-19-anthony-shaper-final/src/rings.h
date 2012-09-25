/*
 *  rings.h
 *  emptyExample
 *
 *  Created by TERRA823 on 9/22/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofMain.h"

class rings{
	
public:
	
	rings();
	
	void draw();
	void draw2();

	void interpolateByPct(float pctr);
	void radiusByPct(float pctr);
	void elapsedTimeByPct(float pctr);
	float radiusSize;
	float radiusSizeA;
	float radiusSizeB;
	
	float elapsedTime;
	
	float pct;
	float shaper;
	int opacity;
	
	int blue;
	int green;
	int red;	
	
	int blue1;
	int green1;
	int red1;		
	
	int blue2;
	int green2;
	int red2;	

	
	int blue3;
	int green3;
	int red3;
	
	
	int blue4;
	int green4;
	int red4;	
	
	
};