/*
* True Reality Open Source Game and Simulation Engine
* Copyright � 2017 Acid Rain Studios LLC
*
* This library is free software; you can redistribute it and/or modify it under
* the terms of the GNU Lesser General Public License as published by the Free
* Software Foundation; either version 2.1 of the License, or (at your option)
* any later version.
*
* This library is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
* FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
* details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this library; if not, write to the Free Software Foundation, Inc.,
* 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*
* Author: Maxim Serebrennik
*/

#ifndef ConfigParser_CPP
#define ConfigParser_CPP 1

#include <trUtil\ConfigParser.h>

#include <iostream>

#include <dtUtil/datapathutils.h>
#include <dtUtil/log.h>

namespace trUtil
{
	// Ctor
	ConfigParser::ConfigParser(const std::string& configFileName)
	{
		SetConfigFileName(configFileName);	
	}

	// Sets the Config File Name
	void ConfigParser::SetConfigFileName(const std::string& configFileName)
	{
		mConfigFileName = configFileName;
		SetConfigFilePath(dtUtil::GetDeltaRootPath() + "/Bin/" + mConfigFileName);	
	}

	// Sets the Full Config File Name and Path
	void ConfigParser::SetConfigFilePath(const std::string &configFilePath)
	{
		mConfigFilePath = configFilePath;
		#ifdef _DEBUG
			LOG_INFO("VRSim Config File: " + mConfigFilePath + '\n');
		#endif
	}

}

#endif // ConfigParser_CPP