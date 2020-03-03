/*------------------------------------------------------------
This file will test the functionality of the Vector3 class which
will be used in the Killer1 Engine. Most of the examples and all
of the equations are from 3D Math Primer for Graphics and Game
Development by Dunn and Parberry (awesome book for those who
wish to learn).

Uses the boost test library.

Boost Software License - Version 1.0 - August 17th, 2003

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.


Written by Maxwell Miller
-------------------------------------------------------------*/

#include <boost/test/unit_test.hpp>
#include <UnitTests/TestHelper.h>
#include <Engine/Atom.h>
#include <Engine/Event.hpp>
#include <Engine/Keys.h>
#include <Engine/EventManager.h>
#include <Engine/GameObject.h>
#include <Engine/Timer.h>

#include <iostream>

namespace TE = Tempest;
namespace TM = TempestMath;

class MockEventObj : public TE::GameObject
{
public:
    MockEventObj(void)
        : _count(0)
    {  }

    ~MockEventObj(void)
    {  }

    void v_Update(void)
    {  }

    void v_OnEvent(TE::Event event)
    {        
        if(std::strcmp(event.Type.c_str(), "add") == 0)
        {
            _count += std::any_cast<S32>(event.Data);
        }
        else if(std::strcmp(event.Type.c_str(), "sub") == 0)
        {
            _count -= std::any_cast<S32>(event.Data);
        }
    }

    S32 GetCount(void)
    {
        return _count;
    }

private:
    S32 _count;
};

BOOST_AUTO_TEST_CASE(EventCompareType)
{
    TE::Event testEvent{"INPUT"};

    BOOST_CHECK_EQUAL("INPUT", testEvent.Type);
}

BOOST_AUTO_TEST_CASE(EventAddData)
{
    TE::Event message{"INPUT", 1, 2, 450.1234, TE::Keys::ENTER};

   BOOST_CHECK_EQUAL(message.SenderID, 1);
   BOOST_CHECK_EQUAL(message.ReceiverID, 2);
   BOOST_CHECK_EQUAL(message.DispatchTime, 450.1234);
   BOOST_CHECK_EQUAL(std::any_cast<TE::Keys>(message.Data), TE::Keys::ENTER);
}

BOOST_AUTO_TEST_CASE(EventManagerWithObject)
{
    shared_ptr<MockEventObj> obj = make_shared<MockEventObj>();
    
    TE::Event addEvent{"add", 0, obj->GetID(), 0.0, 2};
    
    TE::EventManager::Instance()->AddListener(obj, "add");
    TE::EventManager::Instance()->AddListener(obj, "sub");

    TE::EventManager::Instance()->DispatchNow(addEvent);

    BOOST_CHECK_EQUAL(obj->GetCount(), 2);

    TE::Event subEvent{"sub", 0, obj->GetID(), TM::Timer::Instance()->TotalTime() + 0.5f, 3};

    TE::EventManager::Instance()->AddEvent(subEvent);

    for(int i = 0; i < 50; i++)
    {
        TM::Timer::Instance()->SingleStep();

        TE::EventManager::Instance()->Dispatch();
    }

    BOOST_CHECK_EQUAL(obj->GetCount(), -1);

    addEvent.DispatchTime = TM::Timer::Instance()->TotalTime() + 0.3;
    addEvent.Data = 11;
    subEvent.DispatchTime = TM::Timer::Instance()->TotalTime() + 1.0;
    subEvent.Data = 2;

    TE::EventManager::Instance()->AddEvent(subEvent);
    TE::EventManager::Instance()->AddEvent(addEvent);

    for(int i = 0; i < 30; i++)
    {
        TM::Timer::Instance()->SingleStep();

        TE::EventManager::Instance()->Dispatch();
    }

    BOOST_CHECK_EQUAL(obj->GetCount(), 10);

    for(int i = 0; i < 50; i++)
    {
        TM::Timer::Instance()->SingleStep();

        TE::EventManager::Instance()->Dispatch();
    }

    BOOST_CHECK_EQUAL(obj->GetCount(), 8);

    addEvent.DispatchTime = 0.0;
    addEvent.Data = 10;

    TE::EventManager::Instance()->AddEvent(addEvent);
    TE::EventManager::Instance()->Dispatch();

    BOOST_CHECK_EQUAL(obj->GetCount(), 18);
}
