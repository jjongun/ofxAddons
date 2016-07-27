#include "VLCMediaPlayer.h"

#pragma region MyRegion

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


#pragma region MyRegion
VLCMediaPlayer::VLCMediaPlayer()
{
}

VLCMediaPlayer::~VLCMediaPlayer()
{
	if (frontImage != nullptr)
	{
		delete frontImage;
	}
	libvlc_media_parse(media);
}



// utils
std::string replace_all(
	__in const std::string &message,
	__in const std::string &pattern,
	__in const std::string &replace
	) {

	std::string result = message;
	std::string::size_type pos = 0;
	std::string::size_type offset = 0;

	while ((pos = result.find(pattern, offset)) != std::string::npos)
	{
		result.replace(result.begin() + pos, result.begin() + pos + pattern.size(), replace);
		offset = pos + replace.size();
	}

	return result;
}


#pragma endregion


void VLCMediaPlayer::setup(string path)
{
	isReady = false;

	//https://wiki.videolan.org/VLC_command-line_help
	//vlc options
	char const *vlc_argv[] = {
		"--no-osd",
		//"--avcodec-threads=4096" // if you want...
	};
	
	libvlc = libvlc_new(sizeof(vlc_argv) / sizeof(*vlc_argv), vlc_argv);
	if (!libvlc)
	{
		cout << libvlc_errmsg() << endl;
		return;
	}

	if (ofFile(path).exists() == false)
	{
		cout << "Error : not exists video" << endl;
		return;
	}
	
	std::filesystem::path p(path);
	media = libvlc_media_new_path(libvlc, replace_all(p.string(), "/", "\\").c_str()); // Change to C style path string (for windows).
	mediaPlayer = libvlc_media_player_new_from_media(media);

	libvlc_media_parse(media);
	videoWidth = libvlc_video_get_width(mediaPlayer);
	videoHeight = libvlc_video_get_height(mediaPlayer);
	video_length_ms = libvlc_media_get_duration(media);
	cout << "Video: (" << videoWidth << ", " << videoHeight << ")" << endl;
	cout << "Video:length " << video_length_ms << "(ms)" << endl;

	libvlc_video_set_callbacks(mediaPlayer, lockStatic, unlockStatic, displayStatic , this);
	libvlc_video_set_format(mediaPlayer, "RV24", videoWidth, videoHeight, videoWidth * 3);

	frontImage = new ofImage();
	frontImage->allocate(videoWidth, videoHeight, ofImageType::OF_IMAGE_COLOR);

	if (frontImage->isAllocated() == false || frontImage->getWidth() < 1 || frontImage->getHeight() < 1)
	{
		cout << "Error : can't initialize ofimage" << endl;
		return;
	}

	cout << "vlcmedia : ready to play" << endl;
	libvlc_media_release(media);

	shader_BGRtoRGB.setupShaderFromSource(GL_FRAGMENT_SHADER, shaderstr);
	shader_BGRtoRGB.linkProgram();

	isReady = true;
}

void VLCMediaPlayer::draw()
{
	if (isReady && libvlc_media_player_is_playing(mediaPlayer) == true)
	{
		frontImage->update();
	}
	shader_BGRtoRGB.begin();
	frontImage->draw(0, 0);
	shader_BGRtoRGB.end();
}

void VLCMediaPlayer::play(bool isLooping)
{
	if (isLooping == true)
	{
		libvlc_media_add_option(media, "input-repeat=-1");
	}
	else 
	{
		libvlc_media_add_option(media, "input-repeat=0");
	}

	libvlc_media_player_play(mediaPlayer);
}

void VLCMediaPlayer::pause()
{
	libvlc_media_player_pause(mediaPlayer);
}

int VLCMediaPlayer::getFps()
{
	return fps_vlc.getFps();
}




#pragma region MyRegion

void *VLCMediaPlayer::lockStatic(void * data, void ** p_pixels)
{
	return ((VLCMediaPlayer*)data)->lock(p_pixels);
}

void VLCMediaPlayer::unlockStatic(void * data, void * id, void * const * p_pixels)
{
}

void VLCMediaPlayer::displayStatic(void * data, void * id)
{
}

void * VLCMediaPlayer::lock(void ** p_pixels)
{
	fps_vlc.newFrame();
	*p_pixels = frontImage->getPixels();
	return NULL;
}

void VLCMediaPlayer::unlock(void * id, void * const * p_pixels)
{
}

void VLCMediaPlayer::display(void * id)
{
}

#pragma endregion;