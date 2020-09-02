#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	ofNoFill();
	time = ofGetElapsedTimef();
	float deltatime = ofGetLastFrameTime();
#if 0
	for (int i = 0; i <= ofGetWidth(); i = i + ofGetWidth()/10)
	{
		for (int j = 0; j <= ofGetHeight(); j = j + ofGetHeight() / 10)
		{
			float radiusOdd = 80 * sin(time);
			float radiusEven = 80 * cos(time + i*3.14/2 + j*3.14/2);

			ofDrawCircle(glm::vec2(i, j), radiusEven);
			ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
		}
	}
#endif
	cout << radius << "\n";
	if (mouseButton == 0)
	{
		radius = radius + 100 * deltatime;
		DrawRipples(radius);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	radius = 0;

	mousePos.x = x;
	mousePos.y = y;
	mouseButton = button;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

void ofApp::DrawRipples(float radiusOfRipple)
{
	ofDrawCircle(mousePos, 10*sin(radiusOfRipple/20) + radiusOfRipple);
	if (radiusOfRipple > 50)
	{
		DrawRipples(radiusOfRipple - 50);
	}
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
