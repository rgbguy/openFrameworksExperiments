#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	beat.load("song2.mp3");
	beat.play();
	fftSmooth  = new float[8192];
	for (int i = 0; i < 8192; i++)
	{
		fftSmooth[i] = 0;
	}

	bands = 64;
	beat.setLoop(TRUE);
	//beat.ofBaseSoundPlayer::setVolume(1.0);


}

//--------------------------------------------------------------
void ofApp::update(){
	ofSoundUpdate();
	float* value = ofSoundGetSpectrum(bands);
	for (int i = 0; i < bands; i++)
	{
		fftSmooth[i] *= 0.9f;
		if (fftSmooth[i]< value[i])
		{
			fftSmooth[i] = value[i];

		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
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

#if 0
	cout << radius << "\n";
	if (mouseButton == 0)
	{
		radius = radius + 100 * deltatime;
		DrawRipples(radius);
	}
#endif

	ofSetRectMode(OF_RECTMODE_CENTER);
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	for (int i = 0; i < bands; i++)
	{
		//ofDrawRectangle(glm::vec2(0, 0), 10*i, 10*i);
		ofSetCircleResolution(100*fftSmooth[i]);
		if (100*fftSmooth[i] > 3)
		{
			ofDrawEllipse(glm::vec2(0, 0), 10 * i, i * 10);
			ofRotateDeg(10 * fftSmooth[i]);

		}
		cout << 1000*fftSmooth[i] << "\n";
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

	mousePos.x = x;
	mousePos.y = y;
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