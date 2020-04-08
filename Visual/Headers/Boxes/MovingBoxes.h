/*-------------------------------------------------------------------
MovingBoxes is the whole of phase one for Killer Wave Entertainment.
MovingBoxes will move, and will be able to be toggled active. That is 
pretty much it.

This is not free to use, and cannot be used without the express permission
of Layer8Games? I don't know my own name these days. 

Written by Maxwell Miller
---------------------------------------------------------------------*/
#pragma once

//Killer1 Includes
#include <Engine/Atom.h>
#include <Engine/ErrorManager.h>
#include <Engine/LevelManager.h>
#include <Engine/Engine.h>
#include <Engine/Level.h>
#include <Engine/Controller.h>
#include <Engine/TextureManager.h>
#include <Engine/FontManager.h>
#include <Engine/Text.h>
#include <Engine/Color.h>
#include <Engine/Timer.h>
#include <Engine/AudioManager.h>

#include <Boxes/Box.h>
#include <Boxes/DataBases.h>
#include <Boxes/ProjectFactory.h>

#include <iostream>

namespace TE = Tempest;
namespace TM = TempestMath;

namespace Boxes 
{
    class MovingBoxes : public TE::Level 
    {
    public:
//==========================================================================================================================
//
//Constructors
//
//==========================================================================================================================
        MovingBoxes(void);
        
        ~MovingBoxes(void) final;

//==========================================================================================================================
//
//Virtual functions
//
//==========================================================================================================================
        void v_Init(void);
        
        void v_Update(void);

//==========================================================================================================================
//
//MovingBoxes functions
//
//==========================================================================================================================		
        void CheckBoxEdge(p_Box b);

        void CheckCollisions(void);

    private:
//==========================================================================================================================
//
//Members
//
//==========================================================================================================================		
        F32 	 _left;
        F32 	 _right;
        F32 	 _bottom;
        F32 	 _top;
        p_Box 	 _redbox;
        p_Box 	 _bluebox;
        p_Box 	 _greenbox;
        TE::Text _levelTitle;
        TE::Text _updateText;
        string   _message1;
        string   _message2;
        p_Box 	 _activeBox;
    };
    typedef shared_ptr<MovingBoxes> p_MovingBoxes;
}//End namespace