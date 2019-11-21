/*------------------------------------------------------------
A Integration test for the ForceRegistry system

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
#include <Engine/Atom.h>
#include <Engine/ForceRegistry.h>
#include <Engine/GravityForce.h>
#include <Engine/RigidBody2D.h>
#include <Engine/RigidBody3D.h>
#include <Engine/Vector4.h>
#include <Engine/EngineFactory.h>
#include <Engine/PhysicsFactory.h>

namespace KP = KillerPhysics;
namespace KM = KillerMath;

/*

Disabled until game object can be smarter

class ForceRegObject : public KE::GameObject
{
public:
	ForceRegObject(void)
	: p_body2D(nullptr), p_body3D(nullptr)
	{
		GameObject::SetOrientation(1.0f);
	}

	~ForceRegObject(void)
	{
		p_body2D.reset();
		p_body3D.reset();
	}

	void v_Update(void) final
	{  }

	void SetBody2D(void)
	{
		p_body2D = KE::EngineFactory::Instance()->MakeRigidBody2D();
		p_body2D->SetObject(this);
	}

	void SetBody3D(void)
	{
		p_body3D = KE::EngineFactory::Instance()->MakeRigidBody3D();
		p_body3D->SetObject(this);
	}

	KP::p_RigidBody2D p_body2D;
	KP::p_RigidBody3D p_body3D;
};

BOOST_AUTO_TEST_CASE(ForceRegistryRigidBody2DGravity)
{
	KP::ForceRegistry registry { };
	ForceRegObject obj { };
	obj.SetPosition(0.0f, 20.0f, 0.0f);
	obj.SetBody2D();

	KP::p_GravityForce p_gravity = KP::PhysicsFactory::Instance()->MakeGravityForce();

	registry.Add(obj.p_body2D, p_gravity);

	for(int i = 0; i < 50; ++i)
	{
		registry.UpdateForces();
		obj.p_body2D->Integrate();
	}

	BOOST_CHECK_EQUAL(obj.GetPosition()[x], 0.0f);
	BOOST_CHECK_LT(obj.GetPosition()[y], 20.0f);
	BOOST_CHECK_EQUAL(obj.GetPosition()[z], 0.0f);
	BOOST_CHECK_EQUAL(obj.GetPosition()[w], 1.0f);

	obj.SetPosition(20.0f, 0.0f, 0.0f);
	obj.p_body2D->SetVelocity(0.0f, 0.0f, 0.0f);
	p_gravity->Set(1.0f, 0.0f, 1.0f);

	for(int i = 0; i < 50; ++i)
	{
		registry.UpdateForces();
		obj.p_body2D->Integrate();
	}

	BOOST_CHECK_GT(obj.GetPosition()[x], 20.0f);
	BOOST_CHECK_EQUAL(obj.GetPosition()[y], 0.0f);
	BOOST_CHECK_EQUAL(obj.GetPosition()[z], 0.0f);
	BOOST_CHECK_EQUAL(obj.GetPosition()[w], 1.0f);
}

BOOST_AUTO_TEST_CASE(ForceRegistryRigidBody3DGravity)
{
	KP::ForceRegistry registry { };
	ForceRegObject obj { };
	obj.SetPosition(0.0f, 20.0f, 0.0f);
	obj.SetBody3D();

	KP::p_GravityForce p_gravity = KP::PhysicsFactory::Instance()->MakeGravityForce();

	registry.Add(obj.p_body3D, p_gravity);

	for(int i = 0; i < 50; ++i)
	{
		registry.UpdateForces();
		obj.p_body3D->Integrate();
	}

	BOOST_CHECK_EQUAL(obj.GetPosition()[x], 0.0f);
	BOOST_CHECK_LT(obj.GetPosition()[y], 20.0f);
	BOOST_CHECK_EQUAL(obj.GetPosition()[z], 0.0f);
	BOOST_CHECK_EQUAL(obj.GetPosition()[w], 1.0f);

	obj.SetPosition(20.0f, 0.0f, 0.0f);
	obj.p_body3D->SetVelocity(0.0f, 0.0f, 0.0f);
	p_gravity->Set(1.0f, 0.0f, 1.0f);

	for(int i = 0; i < 50; ++i)
	{
		registry.UpdateForces();
		obj.p_body3D->Integrate();
	}

	BOOST_CHECK_GT(obj.GetPosition()[x], 20.0f);
	BOOST_CHECK_EQUAL(obj.GetPosition()[y], 0.0f);
	BOOST_CHECK_GT(obj.GetPosition()[z], 0.0f);
	BOOST_CHECK_EQUAL(obj.GetPosition()[w], 1.0f);
}

*/