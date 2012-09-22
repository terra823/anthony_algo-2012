/*
 *  square.h
 *  emptyExample
 *
 *  Created by TERRA823 on 9/22/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef SQUARE_H
#define SQUARE_H
#define colorArray 15;

#include "ofMain.h"

class square{
	
public:
	
	square();
	
	void draw();
	void	xenoToPoint(float catchX, float catchY);
	
	ofPoint pos;
	float catchUpSpeed;
	float radiusSize;
	//colorArray [23][55][0][117][255][161][135][255][227][84][250][247][2][242][242];
//	int red1, blue1, green1, red2, blue2, green2, red3, blue3, green3, red4, blue4, green4, red5, blue5, green5;
	int blue;
	int green;
	int red;	

	
	int colors; 
	int colorIndex;


	int opacity;
	
	
};

#endif // BALL_H