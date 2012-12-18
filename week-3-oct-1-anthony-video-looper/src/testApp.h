#pragma once

#include "ofMain.h"
#include "timePoint.h"
#include "timePointRecorder.h"


class testApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		void videoSettings();
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
		ofPoint		getPosition( float time);
		ofPoint		getSpeed( float time);
		ofVideoPlayer mov;
    
		int x,y;
		int	getCurrentFrame;
		int getTotalNumFrames;
		
		float playbackStartTime;
		float getDuration;
	
		bool isFrameNew;
		
		float timetoCheck;
	
		timePointRecorder TPR;



	
	

};

