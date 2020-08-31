#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < AllBalls.size(); i++)
    {
        AllBalls[i].UpdateBall();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        AllBalls.push_back(Ball()); // do something else
    }
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

void Ball::UpdateBall()
{
    glm::vec2 MousePosition = glm::vec2(ofGetMouseX(), ofGetMouseY());
    if (glm::length(MousePosition - initialPos) < 200)
    {
        velocity = -10 *glm::normalize(MousePosition - initialPos);
    }
    ofDrawCircle(initialPos, 10);
    if (initialPos.x >= ofGetWidth() || initialPos.x <= 0)
    {
        velocity.x = velocity.x * -1;
    }
    if (initialPos.y >= ofGetHeight() || initialPos.y <= 0)
    {
        velocity.y = velocity.y * -1;
    }
    initialPos += velocity;

    ofSetColor(color.x, color.y, color.z);
}
