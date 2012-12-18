#include "particle.h"
#include "ofMain.h"


//------------------------------------------------------------
particle::particle(){
	setInitialCondition(0,0,0,0);
	pos.x = ofRandomWidth()/2;
	pos.y = ofRandomHeight()/2;
	
	vel = 3;
	frc = 10;
	r = ofRandom(.5, 10);;
	color = ofRandom(0, 255);
	
	damping = .005f;
	
    maxspeed = 5;
    maxforce = 5;
	
	//particleSize = ofRandom(10, 40);

}


//------------------------------------------------------------
void particle::update(){	

	vel += frc;
	pos += vel;
	vel.x = ofClamp(vel.x, -maxspeed, maxspeed);  // Limit speed
	vel.y = ofClamp(vel.y, -maxspeed, maxspeed);  // Limit speed
	frc = 0; 
	
	
	if (pos.x < -r) pos.x = ofGetWidth()+r;
    if (pos.y < -r) pos.y = ofGetHeight()+r;
    if (pos.x > ofGetWidth()+r) pos.x = -r;
    if (pos.y > ofGetHeight()+r) pos.y = -r;
	
	
	
	
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
	
	frc += sep + ali + coh;

	sep *= 6.5;
	ali *= 6.0;
	coh *= 6.0;
	
}

//------------------------------------------------------------
void particle::addDampingForce(){
	
	// the usual way to write this is  vel *= 0.99
	// basically, subtract some part of the velocity 
	// damping is a force operating in the oposite direction of the 
	// velocity vector
	
    frc.x -= vel.x * damping;
    //frc.y -= vel.y * damping;
}

//------------------------------------------------------------
void particle::setInitialCondition(float px, float py, float vx, float vy){
    pos.set(px,py);
	vel.set(vx,vy);
}


//------------------------------------------------------------
void particle::draw(){
    //ofCircle(pos.x, pos.y, 30);
	float angle = (float)atan2(-vel.y, vel.x);
    float theta =  -1.0*angle;

	float heading2D = ofRadToDeg(theta)+90;
	ofSetColor(255, color, 255, 75);
	
	ofEnableAlphaBlending();
    //ofNoFill();
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofRotateZ(heading2D);
	ofBeginShape();
    ofVertex(0, -r*2);
    ofVertex(-r, r*2);
    ofVertex(r, r*2);
    ofEndShape(true);
    ofPopMatrix();
	ofEnableAlphaBlending();
	
	
	
}


//------------------------------------------------------------
void particle::seek(ofPoint target) {
    frc += steer(target, false);
}

//------------------------------------------------------------
void particle::arrive(ofPoint target) {
    frc += steer(target, true);
}

//------------------------------------------------------------
// A method that calculates a steering vector towards a target
// Takes a second argument, if true, it slows down as it approaches the target
ofPoint particle::steer(ofPoint target, bool slowdown) {
    ofPoint steer;  // The steering vector
    ofPoint desired = target - pos;  // A vector pointing from the location to the target
    float d = ofDist(target.x, target.y, pos.x, pos.y); // Distance from the target is the magnitude of the vector
    
	// If the distance is greater than 0, calc steering (otherwise return zero vector)
    if (d > 0) {
		
		desired /= d; // Normalize desired
		// Two options for desired vector magnitude (1 -- based on distance, 2 -- maxspeed)
		if ((slowdown) && (d < 100.0f)) {
			desired *= maxspeed * (d/100.0f); // This damping is somewhat arbitrary
		} else {
			desired *= maxspeed;
		}
		// Steering = Desired minus Velocity
		steer = desired - vel;
		steer.x = ofClamp(steer.x, -maxforce, maxforce); // Limit to maximum steering force
		steer.y = ofClamp(steer.y, -maxforce, maxforce); 
    }
    return steer;
}

//------------------------------------------------------------
void particle::flock(vector<particle*> particles) {
	
	ofPoint sep = separate(particles);
	ofPoint ali = align(particles);
	ofPoint coh = cohesion(particles);
	
	// Arbitrarily weight these forces
	sep *= 1.5;
	ali *= 1.0;
	coh *= 1.0;
	
	frc += sep + ali + coh;
	
}


//------------------------------------------------------------
// Separation
// Method checks for nearby boids and steers away
ofPoint particle::separate(vector<particle*> particles) {
    float desiredseparation = 25.0f;
    ofPoint steer;
    int count = 0;
	
    // For every boid in the system, check if it's too close
    for (int i = 0 ; i < particles.size(); i++) {
		particle* other = particles[i];
		float d = ofDist(pos.x, pos.y, other->pos.x, other->pos.y);
		// If the distance is greater than 0 and less than an arbitrary amount (0 when you are yourself)
		if ((d > 0) && (d < desiredseparation)) {
			
			// Calculate vector pointing away from neighbor
			ofPoint diff = pos - other->pos;
			diff /= d;			// normalize
			diff /= d;        // Weight by distance
			steer += diff;
			count++;            // Keep track of how many
		}
    }
    // Average -- divide by how many
    if (count > 0) {
		steer /= (float)count;
    }
	
	
    // As long as the vector is greater than 0
	float mag = sqrt(steer.x*steer.x + steer.y*steer.y);
    if (mag > 0) {
		// Implement Reynolds: Steering = Desired - Velocity
		steer /= mag;
		steer *= maxspeed;
		steer -= vel;
		steer.x = ofClamp(steer.x, -maxforce, maxforce);
		steer.y = ofClamp(steer.y, -maxforce, maxforce);
    }
    return steer;
}

// Alignment
// For every nearby boid in the system, calculate the average velocity
ofPoint particle::align(vector<particle*> particles) {
    float neighbordist = 150.0;
    ofPoint steer;
    int count = 0;
    for (int i = 0 ; i < particles.size(); i++) {
		particle* other = particles[i];
		
		float d = ofDist(pos.x, pos.y, other->pos.x, other->pos.y);
		if ((d > 0) && (d < neighbordist)) {
			steer += (other->vel);
			count++;
		}
    }
    if (count > 0) {
		steer /= (float)count;
    }
	
    // As long as the vector is greater than 0
	float mag = sqrt(steer.x*steer.x + steer.y*steer.y);
    if (mag > 0) {
		// Implement Reynolds: Steering = Desired - Velocity
		steer /= mag;
		steer *= maxspeed;
		steer -= vel;
		steer.x = ofClamp(steer.x, -maxforce, maxforce);
		steer.y = ofClamp(steer.y, -maxforce, maxforce);
    }
    return steer;
}

// Cohesion
// For the average location (i.e. center) of all nearby boids, calculate steering vector towards that location
ofPoint particle::cohesion(vector<particle*> particles) {
    float neighbordist = 150.0;
    ofPoint sum;   // Start with empty vector to accumulate all locations
    int count = 0;
    for (int i = 0 ; i < particles.size(); i++) {
		particle* other = particles[i];
		float d = ofDist(pos.x, pos.y, other->pos.x, other->pos.y);
		if ((d > 0) && (d < neighbordist)) {
			sum += other->pos; // Add location
			count++;
		}
    }
    if (count > 0) {
		sum /= (float)count;
		return steer(sum, false);  // Steer towards the location
    }
    return sum;
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
