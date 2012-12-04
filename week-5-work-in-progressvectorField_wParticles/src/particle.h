#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h"

class particle
{
    public:
        ofVec2f pos;
        ofVec2f vel;
        ofVec2f frc;   // frc is also know as acceleration (newton says "f=ma")
		ofPoint steer(ofPoint target, bool slowdown);
		ofPoint separate(vector<particle*> particles);
		ofPoint align(vector<particle*> particles);
		ofPoint cohesion(vector<particle*> particles);
	
	
	
		ofPoint sep;
		ofPoint ali;
		ofPoint coh;
	
		
		vector < ofPoint > trail;

	
        particle();
		virtual ~particle(){};
	
		void seek(ofPoint target);
		void arrive(ofPoint target);
        void resetForce();
        void addForce(float x, float y);
        void addDampingForce();
        void setInitialCondition(float px, float py, float vx, float vy);
        void update();
        void draw();
	
		void bounceOffWalls();
	
		void flock(vector<particle*> particles);
	
	
		float maxforce, maxspeed, r, damping, particleSize, color;
		float bounce;  // How "elastic" is the object

    protected:
    private:
};

#endif // PARTICLE_H
