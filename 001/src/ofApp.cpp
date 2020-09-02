#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    startpoint = glm::vec2(ofGetWidth() / 2, 0);
    endpoint = startpoint + glm::vec2(0, 100);

     AllFractalBranches.push_back(FractalBranch());

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



    for (int i = 0; i < AllFractalBranches.size(); i++)
    {
        AllFractalBranches[i].FindNextPoint(startpoint, endpoint, 60, 100);
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        //AllBalls.push_back(Ball()); // do something else
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

void FractalBranch::FindNextPoint(glm::vec2 startpoint, glm::vec2 endpoint, float angleInDegrees, int maxbranches)
{
    float angleInRadians = RAD_TO_DEG * angleInDegrees;
    glm::vec2 differenceVector = endpoint - startpoint;

    glm::mat4 rotationMat(1);
    rotationMat = glm::rotate(rotationMat, angleInRadians, glm::vec3(1.0, 0.0, 1.0));
    glm::vec3 vec = glm::vec3(rotationMat * glm::vec4(differenceVector, 0.0f, 1.0f));

    ofDrawLine(startpoint, endpoint);
    ofDrawLine(endpoint, endpoint + vec);
    if (maxbranches == 0)
    {
        return;
    }
    maxbranches--;
    FindNextPoint(endpoint, endpoint + vec, angleInDegrees, maxbranches);
    //FindNextPoint(endpoint, endpoint + vec, angleInDegrees, maxbranches);

}
