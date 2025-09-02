#pragma once

#include "ofMain.h"
#include "rope/rope.hpp"

class ofApp : public ofBaseApp{

	public:
		Rope *r = r->get_instance();
		void setup() override;
		void update() override;
		void draw() override;
		void exit() override;

		void keyPressed(int key) override;
		void keyReleased(int key) override;
		void mouseMoved(int x, int y ) override;
		void mouseDragged(int x, int y, int button) override;
		void mousePressed(int x, int y, int button) override;
		void mouseReleased(int x, int y, int button) override;
		void mouseScrolled(int x, int y, float scrollX, float scrollY) override;
		void mouseEntered(int x, int y) override;
		void mouseExited(int x, int y) override;
		void windowResized(int w, int h) override;
		void dragEvent(ofDragInfo dragInfo) override;
		void gotMessage(ofMessage msg) override;
		
		
		// void setup() ;
		// void update() ;
		// void draw() ;
		// void exit() ;

		// void keyPressed(int key) ;
		// void keyReleased(int key) ;
		// void mouseMoved(int x, int y ) ;
		// void mouseDragged(int x, int y, int button) ;
		// void mousePressed(int x, int y, int button) ;
		// void mouseReleased(int x, int y, int button) ;
		// void mouseScrolled(int x, int y, float scrollX, float scrollY) ;
		// void mouseEntered(int x, int y) ;
		// void mouseExited(int x, int y) ;
		// void windowResized(int w, int h) ;
		// void dragEvent(ofDragInfo dragInfo) ;
		// void gotMessage(ofMessage msg) ;
		
};
