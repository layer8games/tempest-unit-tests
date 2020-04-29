#pragma once

//=====Engine Includes=====
#include "stdafx.h"
#include <Engine/Atom.h>
#include <Engine/PhysicsFactory.h>

namespace TP = TempestPhysics;

//===== Boxes Includes =====
#include <Boxes/Box.h>
#include <Boxes/Cannon.h>
#include <Boxes/Projectile.h>
#include <Boxes/Cube.h>

namespace Boxes
{
    class ProjectFactory
    {
    public:
//==========================================================================================================================
//
//Destructor	 	
//
//==========================================================================================================================
        ~ProjectFactory(void);

//==========================================================================================================================
//
//Creator Functions
//
//==========================================================================================================================
        inline p_Box MakeBox(void)
        {
            return p_Box(new Box());
        }

        inline p_Cannon MakeCannon(void)
        {
            return p_Cannon(new Cannon());
        }

        inline p_Projectile MakeProjectile(void)
        {
            return p_Projectile(new Projectile());
        }

        inline p_Cube MakeCube(void)
        {
            return p_Cube(new Cube());
        }

//==========================================================================================================================
//
//Singleton Functions
//
//==========================================================================================================================
        static shared_ptr<ProjectFactory> Instance(void);

//==========================================================================================================================
//
//Constructor
//
//==========================================================================================================================
        protected:
        ProjectFactory(void);

    private:
        static shared_ptr<ProjectFactory> _instance;

    };//end Class
    typedef shared_ptr<ProjectFactory> p_ProjectFactory;
}//end Namespace
