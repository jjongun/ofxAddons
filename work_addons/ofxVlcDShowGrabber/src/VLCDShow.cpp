#include "vlcdshow.h"

//
// autor : supersc
// inspired from : jnakanojp's ofxVLCVideoPlayer
//

#pragma region Shader for BGR to RGB

#define STRINGIFY(A) #A
string shaderstr = STRINGIFY(
	uniform sampler2DRect iChannel0;
void main()
{
	vec2 uv = gl_TexCoord[0].st;
	vec4 color = texture2DRect(iChannel0, uv);
	gl_FragColor = vec4(color.b, color.g, color.r, 1.0);
}
);
#pragma endregion

VLCDShow::VLCDShow()
{
}


VLCDShow::~VLCDShow()
{
	libvlc_media_parse(media);
}


const char* stringToCharPtr( string src )
{
	char* output = new char[src.size() + 1];
	copy(src.begin(), src.end(), output);
	output[src.size()] = '\0';
	return output;
}

void VLCDShow::setup(string deviceName, int width, int height)
{
	//https://wiki.videolan.org/vlc_command-line_help
	char const *vlc_argv[] = {
		"--no-osd",
		//"--avcodec-threads=4096",
	};

	libvlc = libvlc_new(sizeof(vlc_argv) / sizeof(*vlc_argv), vlc_argv);
	if (!libvlc)
	{
		cout << libvlc_errmsg() << endl;
		return;
	}

	string mrl = "dshow://";
	media = libvlc_media_new_location(libvlc, mrl.c_str());
	mediaPlayer = libvlc_media_player_new_from_media(media);

	videoWidth = width;
	videoHeight = height;

	stringstream dshowsizestr;
	dshowsizestr << ":dshow-size=" << ofToString(videoWidth) << "x" << ofToString(videoHeight);
	const char* dshowSizeStr_CStr = stringToCharPtr(dshowsizestr.str());
	const char* dshowDeviceName_CStr = stringToCharPtr(":dshow-vdev=" + deviceName);
	libvlc_media_add_option(media, dshowSizeStr_CStr);
	libvlc_media_add_option(media, dshowDeviceName_CStr);
	libvlc_media_add_option(media, ":dshow-adev=none");
	libvlc_media_add_option(media, ":live-caching=0");
	//libvlc_media_add_option(media, ":dshow-fps=30");

	delete[] dshowSizeStr_CStr;
	delete[] dshowDeviceName_CStr;
	
	video_length_ms = libvlc_media_get_duration(media);
	cout << "capture: (" << videoWidth << ", " << videoHeight << ")" << endl;

	libvlc_video_set_callbacks(mediaPlayer, lockStatic, unlockStatic, displayStatic, this);
	libvlc_video_set_format(mediaPlayer, "RV24", videoWidth, videoHeight, videoWidth * 3);
	//I420 ,  YV12 , YUY2 , UYUY , RV32 , RV24 , RV16 , RV15

	frontImage = new ofImage();
	frontImage->allocate(videoWidth, videoHeight, ofImageType::OF_IMAGE_COLOR);

	cout << "complete" << endl;
}


void VLCDShow::draw()
{
	if (frontImage != nullptr && frontImage->isAllocated())
	{
		frontImage->update();
		shader_BGRtoRGB.begin();
		frontImage->draw(0, 0);
		shader_BGRtoRGB.end();
	}
}

void VLCDShow::play()
{
	libvlc_media_player_play(mediaPlayer);
}

void VLCDShow::stop()
{
	
	libvlc_media_player_stop(mediaPlayer);
	libvlc_media_player_release(mediaPlayer);
}

int VLCDShow::getFps()
{
	return fps_vlc.getFps();
}




#pragma region myregion

void *VLCDShow::lockStatic(void * data, void ** p_pixels)
{
	return ((VLCDShow*)data)->lock(p_pixels);
}

void VLCDShow::unlockStatic(void * data, void * id, void * const * p_pixels)
{
}

void VLCDShow::displayStatic(void * data, void * id)
{
}


void * VLCDShow::lock(void ** p_pixels)
{
	fps_vlc.newFrame();
	*p_pixels = frontImage->getPixels();
	return NULL;
}

void VLCDShow::unlock(void * id, void * const * p_pixels)
{
}

void VLCDShow::display(void * id)
{
}

