

#ifndef square_H
#define square_H

#include "ofMain.h"

class square{
	
public:
	
	square();
	void draw();
	void mouseReleased();

	void xenoToPoint(float myPct);
	
	ofPoint pos;
	
	ofPoint pos_a;
	ofPoint pos_b;
	
	
	
	float pct;	
	bool clicked;
};

#endif // square_H