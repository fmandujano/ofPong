#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxNetwork.h"

#define PORT 6666

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
    
    void updateServer();
    void updateClient();
    
    void drawMenu();
    void drawServer();
    void drawClient();
    
    //estados de la app
    enum EstadoApp
    {
        menu,server, client
    };
    EstadoApp estado;
    
    //variables para el gui
    ofxPanel mainMenu;
    ofxButton botonCrearPartida;
    ofxButton botonConectarPartida;
    void crearPartida();
    void conectarPartida();
    
    //variables del juego
    ofVec2f * posPelota;
    ofVec2f * velPelota;
    
    ofVec2f * posPaletaP1;
    ofVec2f * posPaletaP2;
    ofVec2f * sizePaleta;
    float rPelota;
    
    //variables para determinar el estado de las teclas
    bool w,a,s,d;
    
    //variables para red
    ofxUDPManager udpManager;
    char mensaje[100]; // para ver que mensaje llego
		
};
