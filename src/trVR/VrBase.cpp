/*
 * True Reality Open Source Game and Simulation Engine
 * Copyright � 2018 Acid Rain Studios LLC
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation; either version 3.0 of the License, or (at your option)
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
 * @author Alexander Koufos <alexander.p.koufos@leidos.com>
 *
 * Created on July 24, 2018, 7:08 PM
 */
#include <trVR/VrBase.h>

#include <trUtil/Logging/Log.h>

namespace trVR
{
    const trUtil::RefStr VrBase::CLASS_TYPE = trUtil::RefStr("trVR::VrBase");
    
    //////////////////////////////////////////////////////////////////////////
    VrBase::VrBase(const std::string name) : BaseClass(name)
    {
    }
    
    //////////////////////////////////////////////////////////////////////////
    const std::string& VrBase::GetType() const
    {
        return CLASS_TYPE;
    }
    
    //////////////////////////////////////////////////////////////////////////
    void VrBase::Init()
    {
        vr::EVRInitError initErr = vr::VRInitError_None;
        mVrSystem = vr::VR_Init(&initErr, vr::VRApplication_Scene);
        
        if (initErr != vr::VRInitError_None)
        {
            mVrSystem = nullptr;
            LOG_E("Unable to initialize the OpenVR library. OpenVR error: "
                + std::string(vr::VR_GetVRInitErrorAsEnglishDescription(initErr)))
        }
        else
        {
            LOG_I("Connected to headset successfully!")
        }
    }
}