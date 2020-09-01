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
	float time = ofGetElapsedTimef();
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

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
