# ofxThreadDispatcher

```c++
//thread work example 
void SomeThread()
{
	thread th([]() {
	
		cout << "n thread step1 : " << std::this_thread::get_id() << endl;
		std::this_thread::sleep_for(1s);


		//dispatch to mainthread
		ofxMainThreadDispatcher::getInst()->Dispatch([]() {
			cout << "callback!!! " << std::this_thread::get_id() << endl;
		});

	});
	th.detach();
}
```
