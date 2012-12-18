#include "particle.h"
#include "ofMain.h"
bool saving = false;


float mag(ofPoint in){
	float retf = sqrt(in.x * in.x + in.y * in.y);
	return retf;
}

//------------------------------------------------------------
particle::particle(){
	setInitialCondition(0,0,0,0);
	counter = 0;
	damping = 0.1f;
	
	float randmin = -TWO_PI*20;
	float randmax = TWO_PI*20;
	
	float r = ofRandom(-TWO_PI, TWO_PI);
	float x = cos(r);
	float y = -sin(sqrt(r*2));
	
	frc = ofPoint(x / 250, y / 250);
	
	float q = ofRandom(0, 1);
	r = ofRandom(randmin, randmax);
	x = cos(r) * q;
	y = -sin(r) * q;
	
}

//------------------------------------------------------------
void particle::resetForce(){
    // we reset the forces every frame
    frc.set(0,0);
}

//------------------------------------------------------------
void particle::addForce(float x, float y){
    // add in a force in X and Y for this frame.
    frc.x = frc.x + x;
    frc.y = frc.y + y;
}


//------------------------------------------------------------
void particle::addRepulsionForce(particle &p, float radius, float scale){
	
	// ----------- (1) make a vector of where this particle p is: 
	ofVec2f posOfForce;
	posOfForce.set(p.pos.x,p.pos.y);
	
	// ----------- (2) calculate the difference & length 
	
	ofVec2f diff	= pos - posOfForce;
	float length	= diff.length();
	
	// ----------- (3) check close enough
	
	bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
	
	// ----------- (4) if so, update force
    
	if (bAmCloseEnough == true){
		float pct = 1 - (length / radius);  // stronger on the inside
		diff.normalize();
		frc.x = frc.x + diff.x * scale * pct;
        frc.y = frc.y + diff.y * scale * pct;
		p.frc.x = p.frc.x - diff.x * scale * pct;
        p.frc.y = p.frc.y - diff.y * scale * pct;
    }
}

//------------------------------------------------------------
void particle::addAttractionForce(particle & p, float radius, float scale){
	
	// ----------- (1) make a vector of where this particle p is: 
	ofVec2f posOfForce;
	posOfForce.set(p.pos.x,p.pos.y);
	
	// ----------- (2) calculate the difference & length 
	
	ofVec2f diff	= pos - posOfForce;
	float length	= diff.length();
	
	// ----------- (3) check close enough
	
	bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
	
	// ----------- (4) if so, update force
    
	if (bAmCloseEnough == true){
		float pct = 1 - (length / radius);  // stronger on the inside
		diff.normalize();
		frc.x = frc.x - diff.x * scale * pct;
        frc.y = frc.y - diff.y * scale * pct;
		p.frc.x = p.frc.x + diff.x * scale * pct;
        p.frc.y = p.frc.y + diff.y * scale * pct;
    }
	
}


//------------------------------------------------------------
void particle::addDampingForce(){
	
	// the usual way to write this is  vel *= 0.99
	// basically, subtract some part of the velocity 
	// damping is a force operating in the oposite direction of the 
	// velocity vector
	
    frc.x = frc.x - vel.x * damping;
    frc.y = frc.y - vel.y * damping;
}

//------------------------------------------------------------
void particle::setInitialCondition(float px, float py, float vx, float vy){
    pos.set(px,py);
	vel.set(vx,vy);
}

//------------------------------------------------------------
void particle::update(){	
	vel = vel + frc;
	pos = pos + vel;
	
	////////
	if (vel.length() > 0.2){
		ofPoint temp;
		temp.x = pos.x;
		temp.y = pos.y;
		pts.push_back (temp);
	} else {
		if (pts.size()  > 0) {
			pts.erase(pts.begin());
		}
	}
	if (pts.size() > 25){
		pts.erase(pts.begin());
	}
	
}

//------------------------------------------------------------
void particle::draw(){
	ofFill();
	//ofCircle(-sin(pos.x) , cos(pos.y) , sin(2 *vel.x + vel.y));
	//ofCircle(pos.x , pos.y -10 , 0.3 +  (vel.x + vel.y));
	//ofCircle(pos.x , pos.y - 2* (vel.x*vel.y) ,  vel.x + vel.y);
	
	ofNoFill();	
	ofBeginShape();
	for (int i = 0; i < pts.size(); i++){
		if (pts[i].y <= ofGetHeight() && pts[i].y>1){
			
			
			ofLine(pts[i].x, pts[i].y-i/5, pts[i].x+i/5, pts[i].y);
			ofLine(pts[i].x+25, pts[i].y-i/6, pts[i].x-i/6, pts[i].y);
		}
		
	}
	ofEndShape();
	
	
	for(int i = 0; i < counter; i++){
		ofVertex(hist[i].x, hist[i].y);
		
		
	}
	if(counter > 0) ofVertex(pos.x, pos.y);
	ofEndShape(false);


}


//------------------------------------------------------------
void particle::bounceOffWalls(){
	
	// sometimes it makes sense to damped, when we hit
	bool bDampedOnCollision = true;
	bool bDidICollide = false;
	
	// what are the walls
	float minx = 0;
	float miny = 0;
	float maxx = ofGetWidth();
	float maxy = ofGetHeight();
	
	if (pos.x > maxx){
		pos.x = maxx; // move to the edge, (important!)
		vel.x *= -1;
		bDidICollide = true;
	} else if (pos.x < minx){
		pos.x = minx; // move to the edge, (important!)
		vel.x *= -1;
		bDidICollide = true;
	}
	
	if (pos.y > maxy){
		pos.y = maxy; // move to the edge, (important!)
		vel.y *= -1;
		bDidICollide = true;
	} else if (pos.y < miny){
		pos.y = miny; // move to the edge, (important!)
		vel.y *= -1;
		bDidICollide = true;
	}
	
	if (bDidICollide == true && bDampedOnCollision == true){
		vel *= 0.3;
	}
	
}
