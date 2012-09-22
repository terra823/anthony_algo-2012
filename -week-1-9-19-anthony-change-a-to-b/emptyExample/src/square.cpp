

#include "square.h"

//------------------------------------------------------------------

square::square(){
	
}

//------------------------------------------------------------------


void square::draw(){
	ofFill();
	ofSetColor(20, 20, 91);
	ofCircle(pos.x, pos.y, 50);
	

}

//------------------------------------------------------------------

void square::xenoToPoint(float myPct){
	pct = myPct;

	pos.x = (1-pct) * pos_a.x + (pct) * pos_b.x;
	pos.y = (1-pct) * pos_a.y + (pct) * pos_b.y;
	
	
	
	pos.x = (pct) * pos_b.x + (1-pct) * pos_a.x;
	pos.y = (pct) * pos_b.y + (1-pct) * pos_a.y;
}

//------------------------------------------------------------------


void square::mouseReleased(){


}
