#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    posPelota = new ofVec2f( ofGetWidth()/2, ofGetHeight()/2);
    velPelota = new ofVec2f(120,-120);
    
    sizePaleta = new ofVec2f( 25, 100);
    posPaletaP1 = new ofVec2f( 15, ofGetHeight()/2 - sizePaleta->y/2);
    posPaletaP2 = new ofVec2f( ofGetWidth()-sizePaleta->x - 15, ofGetHeight()/2 - sizePaleta->y/2);
    
    //regla: jugador uno aparece a la izquierda y es el servidor
    // jugarod 2 aparce a la derecha y es el cliente
    
    //configurar el menu principal
    mainMenu.setup();
    mainMenu.add(botonCrearPartida.setup("crear partida (servidor)"));
    mainMenu.add(botonConectarPartida.setup("Conectar partida (cliente)"));
    mainMenu.ofxBaseGui::setPosition( ofGetWidth()/2 - mainMenu.getWidth()/2   , ofGetHeight()/2- mainMenu.getHeight()/2);
    botonConectarPartida.addListener(this, &ofApp::conectarPartida);
    botonCrearPartida.addListener( this, &ofApp::crearPartida);
    
    
}

void ofApp::crearPartida()
{
    estado = EstadoApp::server;
}
void ofApp::conectarPartida()
{
    estado = EstadoApp::client;
}

void ofApp::update()
{
    if(estado == EstadoApp::client)
        updateClient();
    if(estado == EstadoApp::server)
        updateServer();
}

void ofApp::updateClient()
{
    if( w )
    {
        posPaletaP2 -> y -= 10;
    }
    if( s)
        posPaletaP2 -> y += 10;
    
    if( posPaletaP1->y < 0 ) posPaletaP1->y =1;
    if( posPaletaP1->y >(ofGetHeight() - sizePaleta->y) ) posPaletaP1->y =ofGetHeight() - sizePaleta->y;
    
}

//--------------------------------------------------------------
void ofApp::updateServer()
{
    //movimiento de la pelota
    posPelota->x += velPelota->x * ofGetLastFrameTime();
    posPelota->y += velPelota->y * ofGetLastFrameTime();
    
    //movimiento de las paletas
    if( w )
    {
        posPaletaP1 -> y -= 10;
    }
    if( s)
        posPaletaP1 -> y += 10;
    
    if( posPaletaP1->y < 0 ) posPaletaP1->y =1;
    if( posPaletaP1->y >(ofGetHeight() - sizePaleta->y) ) posPaletaP1->y =ofGetHeight() - sizePaleta->y;
    
    
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

void ofApp::draw()
{
    if(estado == EstadoApp::menu)
        drawMenu();
    if(estado == EstadoApp::client)
        drawClient();
    if(estado == EstadoApp::server)
        drawServer();
}

void ofApp::drawMenu()
{
    mainMenu.draw();
}

//--------------------------------------------------------------
void ofApp::drawClient()
{
    ofSetColor(0, 0, 0);
    ofDrawBitmapString("CONECTADO COMO CLIENTE", 5, 15);
    
    ofSetColor(255, 0, 0);
    ofDrawCircle( posPelota->x, posPelota->y, 20);
    
    ofSetColor(0, 0, 255);
    ofDrawRectangle(posPaletaP1->x, posPaletaP1->y, sizePaleta->x, sizePaleta->y);
    ofDrawRectangle(posPaletaP2->x, posPaletaP2->y, sizePaleta->x, sizePaleta->y);
    
}
void ofApp::drawServer()
{
    ofSetColor(0, 0, 0);
    ofDrawBitmapString("HOSTING AS SERVER", 5, 15);
    
    ofSetColor(255, 0, 0);
    ofDrawCircle( posPelota->x, posPelota->y, 20);
    
    ofSetColor(0, 0, 255);
    ofDrawRectangle(posPaletaP1->x, posPaletaP1->y, sizePaleta->x, sizePaleta->y);
    ofDrawRectangle(posPaletaP2->x, posPaletaP2->y, sizePaleta->x, sizePaleta->y);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if(key=='w') w =true;
    if(key=='a') a =true;
    if(key=='s') s =true;
    if(key=='d') d =true;
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
    if(key=='w') w =false;
    if(key=='a') a =false;
    if(key=='s') s =false;
    if(key=='d') d =false;
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
