#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    image.load("apj.jpg");
    pixels = image.getPixels();

    image1.load("ind.jpg");
    pixels1 = image1.getPixels();
    image1.getHeight();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    //image.draw(0, 0);
    //ofNoFill();
    //ofColor c = pixels.getColor(mouseX, mouseY);
    for (int i = 0; i < ofGetWidth(); i=i+10)
    {
        for (int j = 0; j < ofGetHeight(); j=j+10)
        {
            ofDrawCircle(glm::vec2(i, j), 30* sin(i/10 + ofGetElapsedTimef()));
            if (ofGetElapsedTimef()<5)
            {
                ofSetColor(pixels.getColor(i, j));

            }
            if (ofGetElapsedTimef() > 5 && ofGetElapsedTimef() < 10)
            {
                ofSetColor(pixels1.getColor(i, j));

            }
            if (ofGetElapsedTimef() > 10)
            {
                ofSetColor(pixels1.getColor(i, j) * pixels.getColor(i, j));

            }
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
