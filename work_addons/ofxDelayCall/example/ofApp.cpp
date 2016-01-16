

//http://scripter.co.kr/331
void ofApp::keyReleased(int key) {

	cout << "start" << endl;
	cout << "delay start : " << std::this_thread::get_id() << endl;
	ofxDelayCall::DelayCall(1.5, []() {
		cout << "ok" << std::this_thread::get_id() << endl;
	});
}
