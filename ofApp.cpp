#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	auto span = 144;
	auto radius = 65;
	auto deg_span = 20;
	ofColor color;
	for (auto x = span * 0.5; x < ofGetWidth(); x += span) {

		for (auto y = span * 0.5; y < ofGetHeight(); y += span) {

			ofPushMatrix();
			ofTranslate(x, y);

			for (auto deg = 0; deg < 360; deg += deg_span) {

				auto noise_radius = ofNoise(ofRandom(1000), ofGetFrameNum() * 0.01) * radius;
				vector<glm::vec2> vertices;
				vector<glm::vec2> noise_vertices;
				for (auto tmp_deg = deg; tmp_deg <= deg + deg_span; tmp_deg++) {

					vertices.push_back(glm::vec2(radius * cos(tmp_deg * DEG_TO_RAD), radius * sin(tmp_deg * DEG_TO_RAD)));
					if (tmp_deg > deg + 2 && tmp_deg < deg + deg_span - 2) {

						noise_vertices.push_back(glm::vec2(noise_radius * cos(tmp_deg * DEG_TO_RAD), noise_radius * sin(tmp_deg * DEG_TO_RAD)));
					}
				}

				vertices.push_back(glm::vec2());
				noise_vertices.push_back(glm::vec2());

				ofBeginShape();
				ofVertices(noise_vertices);
				ofEndShape(true);
			}

			ofPopMatrix();
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}