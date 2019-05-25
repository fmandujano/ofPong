#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    posPelota = new ofVec2f( ofGetWidth()/2, ofGetHeight()/2);
    velPelota = new ofVec2f(120,-120);
    
    sizePaleta = new ofVec2f( 25, 100);
    posPaletaP1 = new ofVec2f( 15, ofGetHeight()/2 - sizePaleta->y/2);
    posPaletaP2 = new ofVec2f( ofGetWidth() - 20, ofGetHeight()/2 - sizePaleta->y/2);
}

//--------------------------------------------------------------
void ofApp::update()
{
    posPelota->x += velPelota->x * ofGetLastFrameTime();
    posPelota->y += velPelota->y * ofGetLastFrameTime();
    
    //rebote
    if( posPelota->x < 0)
    {
        posPelota->x = 1;
        velPelota->x *= -1;
    }
    if( posPelota->x >  ofGetWidth())
    {
        posPelota->x = ofGetWidth() ;
        velPelota->x *= -1;
    }
    if( posPelota->y < 0 )
    {
        posPelota->y = 1;
        velPelota->y *= -1;
    }
       
    if(posPelota->y >  ofGetHeight())
    {
        posPelota->y = ofGetHeight();
        velPelota->y *= -1;
    }
    
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofSetColor(23, 23,  129);
    ofDrawCircle( posPelota->x, posPelota->y, 20);
    
    ofDrawRectangle(posPaletaP1->x, posPaletaP1->y, sizePaleta->x, sizePaleta->y);
    ofDrawRectangle(posPaletaP2->x, posPaletaP2->y, sizePaleta->x, sizePaleta->y);
    
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
