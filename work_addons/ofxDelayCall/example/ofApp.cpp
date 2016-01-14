

//http://scripter.co.kr/331
void ofApp::keyReleased(int key) {

	cout << "start" << endl;
	cout << "delay start : " << std::this_thread::get_id() << endl;
	ofxDelayCall* call = new ofxDelayCall;
	call->DelayCall(1.5, [=]() {
		cout << "complete " << std::this_thread::get_id() << endl;
		delete call; 
	});
}
