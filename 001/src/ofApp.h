#pragma once

#include "ofMain.h"
#include <glm/gtx/matrix_decompose.hpp>

class Ball {
public:
	glm::vec2 initialPos;
	glm::vec2 velocity;
	glm::vec3 color;
	Ball() {
		initialPos = glm::vec2(ofRandom(ofGetWidth() / 2), ofRandom(ofGetHeight() / 2));
		velocity = glm::vec2(ofRandom(-10, 10), ofRandom(-10,10));
		color = glm::vec3(ofRandom(255), ofRandom(255), ofRandom(255));
	};
	void UpdateBall();
};

class FractalBranch {
public:
	glm::vec2 startpoint;
	glm::vec2 endpoint;
	void FindNextPoint(glm::vec2 startpoint, glm::vec2 endpoint, float angleInDegrees, int maxBranches);
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		vector<FractalBranch> AllFractalBranches;
		vector<Ball> AllBalls;

		glm::vec2 startpoint;
		glm::vec2 endpoint;
};

