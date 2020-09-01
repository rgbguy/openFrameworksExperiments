#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    startpoint = glm::vec2(ofGetWidth() / 2, 0);
    endpoint = startpoint + glm::vec2(0, 100);

    for (int i = 0; i < 3; i++)
    {
        AllFractalBranches.push_back(FractalBranch());
        AllFractalBranches[i].startpoint = startpoint;
        AllFractalBranches[i].endpoint = endpoint;
        startpoint = endpoint;

        glm::vec3 v3RotAxis(0.0f, 0.0f, 1.0f); // Rotate about z+
        float angleRad = 3.14/4; // Rotate of a quarter of a turn
        
        glm::quat quatRot = glm::angleAxis(angleRad, v3RotAxis);
        glm::mat4x4 matRot = glm::mat4_cast(quatRot);
        glm::vec4 v4In(startpoint.x, startpoint.y, 0.0f, 1.0f);
        glm::vec4 out = matRot * v4In;

        endpoint = glm::vec2(out.x, out.y);

    }
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
        ofDrawLine(AllFractalBranches[i].startpoint, AllFractalBranches[i].endpoint);

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
