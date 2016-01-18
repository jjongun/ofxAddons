#include "ofxIconMaker.h"
#include "ofGraphics.h"





ofxIconMaker::ofxIconMaker(string iconName , Ratio ratio )
{
	icon_dir = ofDirectory("icon");
	if (icon_dir.exists() == false)
	{
		cout << "not exist icon folder" << endl;
		icon_dir.create();
	}

	if (ratio == Ratio::X1)
		image_ratio = "";
	else if (ratio == Ratio::X2)
		image_ratio = "_2x";

	GetIcon(iconName);
	//getFileInfo(iconName);
}

ofxIconMaker::~ofxIconMaker()
{

}

ofFile ofxIconMaker::getFileInfo(string iconName)
{
	this->iconName;
	auto files = icon_dir.getFiles();
	for (size_t i = 0; i < files.size(); i++)
	{
		cout << files[i].getFileName() << endl;
		if (files[i].getFileName().find(iconName) != string::npos)
		{
			if (files[i].isDirectory() == true)
			{
				string iconName = files[i].getFileName();
				iconName.substr(3, iconName.size() - 3);
				auto splited = ofSplitString(iconName, "_");
				string str_image_depth = splited[splited.size() - 1];
				iconName = iconName.substr(0, iconName.size() - str_image_depth.size() - 1);

				string targetFile = "icon/";
				targetFile.append(files[i].getFileName()).append("/");
				targetFile.append(platform ).append("/");
				targetFile.append(iconName).append(".imageset").append("/");
				targetFile.append(iconName).append(image_ratio).append(".png");
				
				return ofFile(targetFile);
			}
			break;
		}
	}
}

ofImage ofxIconMaker::GetIcon(string iconName)
{
	bool r = image.load(getFileInfo(iconName));
	if (r == false)
		return nullptr;
	return image;
}

string ofxIconMaker::getIconName() const
{
	return iconName;
}


ofImage ofxIconMaker::getImage()
{
	return image;
}
