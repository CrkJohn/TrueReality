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
* @author: Maxim Serebrennik
*/

#include <trManager/MessageBase.h>

#include <trUtil/Logging/Log.h>


namespace trManager
{
    const trUtil::RefStr MessageBase::MESSAGE_TYPE("trManager::MessageBase");

    //////////////////////////////////////////////////////////////////////////
    MessageBase::MessageBase(const trBase::UniqueId* fromActorID, const trBase::UniqueId* aboutActorID, const bool isDirect, const std::string &messageFilter)
    {
        LOG_D("Creating a message: " + mId.ToString())
        mFromActorID = fromActorID;
        mAboutActorID = aboutActorID;
        mIsDirect = isDirect;
        mMessageFilter = &messageFilter;
    }

    //////////////////////////////////////////////////////////////////////////
    MessageBase::~MessageBase()
    {
        LOG_D("Destroying a message: " + mId.ToString())
    }

    //////////////////////////////////////////////////////////////////////////
    bool MessageBase::operator==(const MessageBase& msg) const
    {
        if ((&msg) == this)
        {
            return true;
        }

        if (mFromActorID != msg.mFromActorID ||
            mAboutActorID != msg.mAboutActorID ||
            mIsDirect != msg.mIsDirect ||
            mMessageFilter != msg.mMessageFilter)
        {
            return false;
        }       

        return true;        
    }

    //////////////////////////////////////////////////////////////////////////
    const std::string& MessageBase::GetType() const
    {
        return MESSAGE_TYPE;
    }

    //////////////////////////////////////////////////////////////////////////
    const trBase::UniqueId* MessageBase::GetFromActorID() const
    {
        return mFromActorID.get();
    }

    //////////////////////////////////////////////////////////////////////////
    const trBase::UniqueId* MessageBase::GetAboutActorID() const
    {
        return mAboutActorID.get();
    }

    //////////////////////////////////////////////////////////////////////////
    const bool& MessageBase::GetIsDirect() const
    {
        return mIsDirect;
    }

    //////////////////////////////////////////////////////////////////////////
    const std::string& MessageBase::GetMessageFilter()
    {
        return *mMessageFilter;
    }
}
