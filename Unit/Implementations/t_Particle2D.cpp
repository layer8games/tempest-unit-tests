/*------------------------------------------------------------
This file will test the functionality of the Vector class which
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
#include <UnitTests/t_Main.h>
#include <Engine/Atom.h>
#include <Engine/Particle2D.h>
#include <Engine/Vector2.h>
#include <Engine/Timer.h>

namespace KP = KillerPhysics;
namespace KM = KillerMath;

BOOST_AUTO_TEST_CASE(Particle2D_Constructor)
{
	KP::Particle2D p {  };

	BOOST_CHECK_GT(p.GetID(), 1);
}

BOOST_AUTO_TEST_CASE(Particle2D_Damping_Accessor)
{
	KP::Particle2D p {  };
	p.SetDamping(1.0f);

	BOOST_CHECK_EQUAL(p.GetDamping(), 1.0f);
}

BOOST_AUTO_TEST_CASE(Particle2D_Velocity_Accessor)
{
	KP::Particle2D p {  };
	p.SetVelocity(KM::Vector2(1.0f, 2.0f));

	BOOST_CHECK_EQUAL(p.GetVelocity().GetX(), 1.0f);
	BOOST_CHECK_EQUAL(p.GetVelocity().GetY(), 2.0f);

	p.SetVelocity(5.0f, 6.0f);
	
	BOOST_CHECK_EQUAL(p.GetVelocity().GetX(), 5.0f);
	BOOST_CHECK_EQUAL(p.GetVelocity().GetY(), 6.0f);	
}

BOOST_AUTO_TEST_CASE(Particle2D_ScaleVelocity)
{
	KP::Particle2D p {  };
	p.SetVelocity(5.0f, 1.0f);

	p.AddScaledVelocity(KM::Vector2(3.0f, 4.0f), 5.0f);

	BOOST_CHECK_EQUAL(p.GetVelocity().GetX(), 20.0f);
	BOOST_CHECK_EQUAL(p.GetVelocity().GetY(), 21.0f);
}

BOOST_AUTO_TEST_CASE(Particle2D_Acceleration_Accessor)
{
	KP::Particle2D p {  };

	p.SetAcceleration(KM::Vector2(3.0f, 4.0f));

	BOOST_CHECK_EQUAL(p.GetAcceleration().GetX(), 3.0f);
	BOOST_CHECK_EQUAL(p.GetAcceleration().GetY(), 4.0f);
}

BOOST_AUTO_TEST_CASE(Particle2D_ScaleAcceleration)
{
	KP::Particle2D p {  };

	p.SetAcceleration(KM::Vector2(10.0f, 5.0f));

	p.AddScaledAcceleration(KM::Vector2(15.f, 25.0f), 2.0f);
	
	BOOST_CHECK_EQUAL(p.GetAcceleration().GetX(), 40.0f);
	BOOST_CHECK_EQUAL(p.GetAcceleration().GetY(), 55.0f);	
}

BOOST_AUTO_TEST_CASE(Particle2D_Inverse_Mass_Accessors)
{
	KP::Particle2D p {  };

	p.SetInverseMass(10.0f);

	BOOST_CHECK_EQUAL(p.GetInverseMass(), 10.0f);
}

BOOST_AUTO_TEST_CASE(Particle2D_Mass_Accessor)
{
	KP::Particle2D p {  };

	p.SetMass(5.0f);

	BOOST_CHECK_EQUAL(p.GetMass(), 5.0f);
}

BOOST_AUTO_TEST_CASE(Particle2D_Infinite_Mass)
{
	KP::Particle2D p {  };

	p.SetInverseMass(0.0f);

	BOOST_CHECK_EQUAL(p.GetMass(), REAL_MAX);
	BOOST_CHECK_EQUAL(p.HasFiniteMass(), true);

	p.SetInverseMass(-1.0f);

	BOOST_CHECK_EQUAL(p.HasFiniteMass(), false);
}

BOOST_AUTO_TEST_CASE(Particle2D_Integrate_Update)
{
	KP::Particle2D p {  };

	p.SetPosition(0.0f, 0.0f);
	p.SetAcceleration(100.0f, -100.0f);
	p.SetMass(1.0f);
	p.SetDamping(0.999f);

	//Make sure the delta time is large enough
	KM::Timer::Instance()->SetTimeScale(100.0f);
	KM::Timer::Instance()->Update();

	//RUn 2 updates to get a good enough change.
	p.v_Update();
	p.v_Update();

	BOOST_CHECK_GT(p.GetVelocity().GetX(), 0.0f);
	BOOST_CHECK_LT(p.GetVelocity().GetY(), 0.0f);
	BOOST_CHECK_GT(p.GetPosition().GetX(), 0.0f);
	BOOST_CHECK_LT(p.GetPosition().GetY(), 0.0f);
}

//Force clearing functions here, once added in particle