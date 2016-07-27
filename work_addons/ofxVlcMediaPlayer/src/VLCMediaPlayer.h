#pragma once

#include "ofMain.h"
#include <vlc/vlc.h>

class VLCMediaPlayer
{

private:
	bool isReady;
	ofShader shader_BGRtoRGB;
	ofImage *frontImage;
	ofFpsCounter fps_vlc;
	
	libvlc_instance_t *libvlc;
	libvlc_media_t *media;
	libvlc_media_player_t *mediaPlayer;
	libvlc_event_manager_t *eventManager;

	int videoWidth, videoHeight;
	libvlc_time_t video_length_ms;
public:
	VLCMediaPlayer();
	~VLCMediaPlayer();


	void setup(string path);
	void draw();
	
	void play(bool isLooping = false);
	void pause();

	int getFps();
	
private:
	static void *lockStatic(void *data, void **p_pixels);
	static void unlockStatic(void *data, void *id, void *const *p_pixels);
	static void displayStatic(void *data, void *id);

	void *lock(void **p_pixels);
	void unlock(void *id, void *const *p_pixels);
	void display(void *id);
	
};

