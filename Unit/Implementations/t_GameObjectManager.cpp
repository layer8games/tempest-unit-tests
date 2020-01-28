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
#include <Engine/GameObjectManager.h>
#include <Engine/ErrorManager.h>

namespace TE = Tempest;

class DefinedObject : public TE::GameObject
{
public:
	DefinedObject(void)
	{  }

	~DefinedObject(void)
	{  }

	void v_Update(void)
	{  }
};

BOOST_AUTO_TEST_CASE(GameObjectManagerConstructor)
{
	BOOST_CHECK_NE(TE::GameObjectManager::Instance(), nullptr);
}

BOOST_AUTO_TEST_CASE(GameObjectManagerAddRemoveGetGameObject)
{
	shared_ptr<DefinedObject> obj1 = make_shared<DefinedObject>();
	U32 id_1 = obj1->GetID();

	shared_ptr<DefinedObject> obj2 = make_shared<DefinedObject>();
	U32 id_2 = obj2->GetID();

	shared_ptr<DefinedObject> obj3 = make_shared<DefinedObject>();
	U32 id_3 = obj3->GetID();

	BOOST_CHECK_EQUAL(TE::GameObjectManager::Instance()->Count(), 0);
	
	TE::GameObjectManager::Instance()->Add(obj1);
	TE::GameObjectManager::Instance()->Add(obj2);
	TE::GameObjectManager::Instance()->Add(obj3);
	
	BOOST_CHECK_EQUAL(TE::GameObjectManager::Instance()->Count(), 3);

	TE::p_GameObject gotObj = TE::GameObjectManager::Instance()->GetGameObject(id_1);

	BOOST_CHECK_EQUAL(gotObj->GetID(), id_1);
	
	TE::GameObjectManager::Instance()->Remove(id_2);
	TE::GameObjectManager::Instance()->Remove(id_3);

	BOOST_CHECK_EQUAL(TE::GameObjectManager::Instance()->Count(), 1);
}