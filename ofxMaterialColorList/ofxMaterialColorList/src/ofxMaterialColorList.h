#pragma once
#include "ofColor.h"
#include "ofUtils.h"
#include <iostream>


namespace materialStyle
{
	int COLOR_LEN = 10;

	enum Color_Catergory
	{
		RED = 0 , 
		PINK = 1, 
		PURPLE = 2, 
		DEEP_PURPLE = 3, 
		INDIGO = 4, 
		BLUE = 5, 
		LIGHT_BLUE = 6, 
		CYAN = 7, 
		TEAL = 8, 
		GREEN = 9, 
		LIGHT_GREEN = 10, 
		LIME = 11, 
		YELLOW = 12, 
		AMBER = 13, 
		ORANGE = 14, 
		DEEP_ORANGE = 15, 
		BROWN = 16, 
		GREY = 17,
		BLUE_GREY = 18
	};

	string GetHexcode(Color_Catergory category, char grade)
	{
		string hexcode;
		if (category == Color_Catergory::RED)
		{
			switch (grade)
			{
			case 0: hexcode = "ffebee"; break;
			case 1: hexcode = "ffcdd2"; break;
			case 2: hexcode = "ef9a9a"; break;
			case 3: hexcode = "e57373"; break;
			case 4: hexcode = "EF5350"; break;
			case 5: hexcode = "F44336"; break;
			case 6: hexcode = "E53935"; break;
			case 7: hexcode = "D32F2F"; break;
			case 8: hexcode = "C62828"; break;
			case 9: hexcode = "B71C1C"; break;

			default: hexcode = "F44336";
				break;
			}
		}
		else if (category == Color_Catergory::PINK)
		{
			switch (grade)
			{
			case 0: hexcode = "FCE4EC"; break;
			case 1: hexcode = "F8BBD0"; break;
			case 2: hexcode = "F48FB1"; break;
			case 3: hexcode = "F06292"; break;
			case 4: hexcode = "EC407A"; break;
			case 5: hexcode = "E91E63"; break;
			case 6: hexcode = "D81B60"; break;
			case 7: hexcode = "C2185B"; break;
			case 8: hexcode = "AD1457"; break;
			case 9: hexcode = "880E4F"; break;

			default: hexcode = "E91E63";
				break;
			}
		}
		else if (category == Color_Catergory::PURPLE)
		{
			switch (grade)
			{
			case 0: hexcode = "F3E5F5"; break;
			case 1: hexcode = "E1BEE7"; break;
			case 2: hexcode = "CE93D8"; break;
			case 3: hexcode = "BA68C8"; break;
			case 4: hexcode = "AB47BC"; break;
			case 5: hexcode = "9C27B0"; break;
			case 6: hexcode = "8E24AA"; break;
			case 7: hexcode = "7B1FA2"; break;
			case 8: hexcode = "6A1B9A"; break;
			case 9: hexcode = "4A148C"; break;

			default: hexcode = "9C27B0";
				break;
			}
		}
		else if (category == Color_Catergory::DEEP_PURPLE)
		{
			switch (grade)
			{
			case 0: hexcode = "EDE7F6"; break;
			case 1: hexcode = "D1C4E9"; break;
			case 2: hexcode = "B39DDB"; break;
			case 3: hexcode = "9575CD"; break;
			case 4: hexcode = "7E57C2"; break;
			case 5: hexcode = "673AB7"; break;
			case 6: hexcode = "5E35B1"; break;
			case 7: hexcode = "512DA8"; break;
			case 8: hexcode = "4527A0"; break;
			case 9: hexcode = "311B92"; break;

			default: hexcode = "673AB7";
				break;
			}
		}
		else if (category == Color_Catergory::INDIGO)
		{
			switch (grade)
			{
			case 0: hexcode = "E8EAF6"; break;
			case 1: hexcode = "C5CAE9"; break;
			case 2: hexcode = "9FA8DA"; break;
			case 3: hexcode = "7986CB"; break;
			case 4: hexcode = "5C6BC0"; break;
			case 5: hexcode = "3F51B5"; break;
			case 6: hexcode = "3949AB"; break;
			case 7: hexcode = "303F9F"; break;
			case 8: hexcode = "283593"; break;
			case 9: hexcode = "1A237E"; break;

			default: hexcode = "3F51B5";
				break;
			}
		}
		else if (category == Color_Catergory::BLUE)
		{
			switch (grade)
			{
			case 0: hexcode = "E3F2FD"; break;
			case 1: hexcode = "BBDEFB"; break;
			case 2: hexcode = "90CAF9"; break;
			case 3: hexcode = "64B5F6"; break;
			case 4: hexcode = "42A5F5"; break;
			case 5: hexcode = "2196F3"; break;
			case 6: hexcode = "1E88E5"; break;
			case 7: hexcode = "1976D2"; break;
			case 8: hexcode = "1565C0"; break;
			case 9: hexcode = "0D47A1"; break;

			default: hexcode = "2196F3";
				break;
			}
		}
		else if (category == Color_Catergory::LIGHT_BLUE)
		{
			switch (grade)
			{
			case 0: hexcode = "E1F5FE"; break;
			case 1: hexcode = "B3E5FC"; break;
			case 2: hexcode = "81D4FA"; break;
			case 3: hexcode = "4FC3F7"; break;
			case 4: hexcode = "29B6F6"; break;
			case 5: hexcode = "03A9F4"; break;
			case 6: hexcode = "039BE5"; break;
			case 7: hexcode = "0288D1"; break;
			case 8: hexcode = "0277BD"; break;
			case 9: hexcode = "01579B"; break;

			default: hexcode = "03A9F4";
				break;
			}
		}
		else if (category == Color_Catergory::CYAN)
		{
			switch (grade)
			{
			case 0: hexcode = "E0F7FA"; break;
			case 1: hexcode = "B2EBF2"; break;
			case 2: hexcode = "80DEEA"; break;
			case 3: hexcode = "4DD0E1"; break;
			case 4: hexcode = "26C6DA"; break;
			case 5: hexcode = "00BCD4"; break;
			case 6: hexcode = "00ACC1"; break;
			case 7: hexcode = "0097A7"; break;
			case 8: hexcode = "00838F"; break;
			case 9: hexcode = "006064"; break;

			default: hexcode = "00BCD4";
				break;
			}
		}
		else if (category == Color_Catergory::TEAL)
		{
			switch (grade)
			{
			case 0: hexcode = "E0F2F1"; break;
			case 1: hexcode = "B2DFDB"; break;
			case 2: hexcode = "80CBC4"; break;
			case 3: hexcode = "4DB6AC"; break;
			case 4: hexcode = "26A69A"; break;
			case 5: hexcode = "009688"; break;
			case 6: hexcode = "00897B"; break;
			case 7: hexcode = "00796B"; break;
			case 8: hexcode = "00695C"; break;
			case 9: hexcode = "004D40"; break;

			default: hexcode = "009688";
				break;
			}
		}
		else if (category == Color_Catergory::GREEN)
		{
			switch (grade)
			{
			case 0: hexcode = "E8F5E9"; break;
			case 1: hexcode = "C8E6C9"; break;
			case 2: hexcode = "A5D6A7"; break;
			case 3: hexcode = "81C784"; break;
			case 4: hexcode = "66BB6A"; break;
			case 5: hexcode = "4CAF50"; break;
			case 6: hexcode = "43A047"; break;
			case 7: hexcode = "388E3C"; break;
			case 8: hexcode = "2E7D32"; break;
			case 9: hexcode = "1B5E20"; break;

			default: hexcode = "4CAF50";
				break;
			}
		}
		else if (category == Color_Catergory::LIGHT_GREEN)
		{
			switch (grade)
			{
			case 0: hexcode = "F1F8E9"; break;
			case 1: hexcode = "DCEDC8"; break;
			case 2: hexcode = "C5E1A5"; break;
			case 3: hexcode = "AED581"; break;
			case 4: hexcode = "9CCC65"; break;
			case 5: hexcode = "8BC34A"; break;
			case 6: hexcode = "7CB342"; break;
			case 7: hexcode = "689F38"; break;
			case 8: hexcode = "558B2F"; break;
			case 9: hexcode = "33691E"; break;

			default: hexcode = "8BC34A";
				break;
			}
		}
		else if (category == Color_Catergory::LIME)
		{
			switch (grade)
			{
			case 0: hexcode = "F9FBE7"; break;
			case 1: hexcode = "F0F4C3"; break;
			case 2: hexcode = "E6EE9C"; break;
			case 3: hexcode = "DCE775"; break;
			case 4: hexcode = "D4E157"; break;
			case 5: hexcode = "CDDC39"; break;
			case 6: hexcode = "C0CA33"; break;
			case 7: hexcode = "AFB42B"; break;
			case 8: hexcode = "9E9D24"; break;
			case 9: hexcode = "827717"; break;

			default: hexcode = "CDDC39";
				break;
			}
		}
		else if (category == Color_Catergory::YELLOW)
		{
			switch (grade)
			{
			case 0: hexcode = "FFFDE7"; break;
			case 1: hexcode = "FFF9C4"; break;
			case 2: hexcode = "FFF59D"; break;
			case 3: hexcode = "FFF176"; break;
			case 4: hexcode = "FFEE58"; break;
			case 5: hexcode = "FFEB3B"; break;
			case 6: hexcode = "FDD835"; break;
			case 7: hexcode = "FBC02D"; break;
			case 8: hexcode = "F9A825"; break;
			case 9: hexcode = "F57F17"; break;

			default: hexcode = "FFEB3B";
				break;
			}
		}
		else if (category == Color_Catergory::AMBER)
		{
			switch (grade)
			{
			case 0: hexcode = "FFF8E1"; break;
			case 1: hexcode = "FFECB3"; break;
			case 2: hexcode = "FFE082"; break;
			case 3: hexcode = "FFD54F"; break;
			case 4: hexcode = "FFCA28"; break;
			case 5: hexcode = "FFC107"; break;
			case 6: hexcode = "FFB300"; break;
			case 7: hexcode = "FFA000"; break;
			case 8: hexcode = "FF8F00"; break;
			case 9: hexcode = "FF6F00"; break;

			default: hexcode = "FFC107";
				break;
			}
		}
		else if (category == Color_Catergory::ORANGE)
		{
			switch (grade)
			{
			case 0: hexcode = "FFF3E0"; break;
			case 1: hexcode = "FFE0B2"; break;
			case 2: hexcode = "FFCC80"; break;
			case 3: hexcode = "FFB74D"; break;
			case 4: hexcode = "FFA726"; break;
			case 5: hexcode = "FF9800"; break;
			case 6: hexcode = "FB8C00"; break;
			case 7: hexcode = "F57C00"; break;
			case 8: hexcode = "EF6C00"; break;
			case 9: hexcode = "E65100"; break;

			default: hexcode = "FF9800";
				break;
			}
		}
		else if (category == Color_Catergory::DEEP_ORANGE)
		{
			switch (grade)
			{
			case 0: hexcode = "FBE9E7"; break;
			case 1: hexcode = "FFCCBC"; break;
			case 2: hexcode = "FFAB91"; break;
			case 3: hexcode = "FF8A65"; break;
			case 4: hexcode = "FF7043"; break;
			case 5: hexcode = "FF5722"; break;
			case 6: hexcode = "F4511E"; break;
			case 7: hexcode = "E64A19"; break;
			case 8: hexcode = "D84315"; break;
			case 9: hexcode = "BF360C"; break;

			default: hexcode = "FF5722";
				break;
			}
		}
		else if (category == Color_Catergory::BROWN)
		{
			switch (grade)
			{
			case 0: hexcode = "EFEBE9"; break;
			case 1: hexcode = "D7CCC8"; break;
			case 2: hexcode = "BCAAA4"; break;
			case 3: hexcode = "A1887F"; break;
			case 4: hexcode = "8D6E63"; break;
			case 5: hexcode = "795548"; break;
			case 6: hexcode = "6D4C41"; break;
			case 7: hexcode = "5D4037"; break;
			case 8: hexcode = "4E342E"; break;
			case 9: hexcode = "3E2723"; break;

			default: hexcode = "795548";
				break;
			}
		}
		else if (category == Color_Catergory::GREY)
		{
			switch (grade)
			{
			case 0: hexcode = "FAFAFA"; break;
			case 1: hexcode = "F5F5F5"; break;
			case 2: hexcode = "EEEEEE"; break;
			case 3: hexcode = "E0E0E0"; break;
			case 4: hexcode = "BDBDBD"; break;
			case 5: hexcode = "9E9E9E"; break;
			case 6: hexcode = "757575"; break;
			case 7: hexcode = "616161"; break;
			case 8: hexcode = "424242"; break;
			case 9: hexcode = "212121"; break;

			default: hexcode = "9E9E9E";
				break;
			}
		}
		else if (category == Color_Catergory::BLUE_GREY)
		{
			switch (grade)
			{
			case 0: hexcode = "ECEFF1"; break;
			case 1: hexcode = "CFD8DC"; break;
			case 2: hexcode = "B0BEC5"; break;
			case 3: hexcode = "90A4AE"; break;
			case 4: hexcode = "78909C"; break;
			case 5: hexcode = "607D8B"; break;
			case 6: hexcode = "546E7A"; break;
			case 7: hexcode = "455A64"; break;
			case 8: hexcode = "37474F"; break;
			case 9: hexcode = "263238"; break;

			default: hexcode = "607D8B";
				break;
			}
		}
		return hexcode;
	}

	ofColor GetColor(Color_Catergory category, char grade)
	{
		ofColor rColor;
		rColor.setHex(ofHexToInt(GetHexcode(category , grade)), 255.0f);
		return rColor;
	}

	void SampleDraw()
	{
		float width = 100;
		float height = 30;
		int row = 0;
		int each_count = 10;
		for (size_t i = 0; i < 19; i++)
		{
			materialStyle::Color_Catergory category = static_cast<materialStyle::Color_Catergory>(i);
			if (i != 0 && i % each_count == 0)
				row += 1;

			for (size_t j = 0; j < materialStyle::COLOR_LEN; j++)
			{
				float x = (i % each_count) * width;
				float y = j * height + (row * materialStyle::COLOR_LEN * height);

				ofColor color = materialStyle::GetColor(category, j);
				ofSetColor(color);
				ofRect(x, y, width, height);

				ofSetColor(color.invert());
				ofDrawBitmapString(materialStyle::GetHexcode(category, j), x + (width * .25f), y + (height * .75f));
			}
		}
	}

	/*
	hex문자열로 로 바꾸는 방법
	stringstream stream;
	stream << std::hex << color.getHex();
	cout << stream.str() << endl;

	*/
}


//class ofMaterialColorList
//{
//
//private:
//
//public:	
//
//};