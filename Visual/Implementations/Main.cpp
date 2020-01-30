/*------------------------------------------------------------
This file will test the functionality of the Vector4 class which
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
//==========================================================================================================================
//
//Required file. Simply here to get the test framework set up.
//
//==========================================================================================================================
#if DEBUG
	#pragma comment(lib, "Tempest_Win32_Debug.lib")
#else
	#pragma comment(lib, "Tempest_Win32_Release.lib")
#endif

//=====Engine Includes=====
#include <Engine/Atom.h>
#include <Engine/ErrorManager.h>
#include <Engine/Timer.h>
#include <Engine/LevelManager.h>
#include <Engine/Controller.h>
#include <Engine/GameWindow.h>
#include <Engine/TextureManager.h>
#include <Engine/FontManager.h>
#include <Engine/Engine.h>
#include <Engine/Color.h>
#include <Engine/Shader.h>
#include <Engine/AudioManager.h>
#include <Engine/AudioSource.h>
#include <Engine/AudioClip.h>

namespace TE = Tempest;

//=====Game Includes=====
#include <Boxes/MainMenu.h>
#include <Boxes/SplashScreen.h>
#include <Boxes/MovingBoxes.h>
#include <Boxes/Ballistics.h>
#include <Boxes/Demo3D.h>
#include <Boxes/Box.h>
#include <Boxes/TiledTest.h>

using namespace Boxes;


int main(void)
{
//=====Window Parameter Constants=====
	const S32    wndWidth  	   = 1024;
	const S32    wndHeight 	   = 768;
	const string wndTitle	   = "Killer Engine UI Tests v0.1";
	const S32    wndFullScreen = false;


	TE::Engine::Instance()->Init(wndWidth, wndHeight, wndTitle, wndFullScreen);

	TE::AudioManager::Instance();
	TE::ErrorManager::Instance()->DisplayErrors();

//=====Pre-Load Assets=====	
	TE::TextureManager::Instance()->LoadTexture(100, "./Assets/Textures/Boxes/red_box_32_32.png");
	TE::TextureManager::Instance()->LoadTexture(101, "./Assets/Textures/Boxes/green_box_32_32.png");
	TE::TextureManager::Instance()->LoadTexture(102, "./Assets/Textures/Boxes/blue_box_32_32.png");
	TE::TextureManager::Instance()->LoadTexture(300, "./Assets/Textures/Ballistics/cannon.png");
	TE::TextureManager::Instance()->LoadTexture(301, "./Assets/Textures/Ballistics/bullet_v2.png");
	TE::TextureManager::Instance()->LoadTexture(302, "./Assets/Textures/Ballistics/artillery_v1.png");
	TE::TextureManager::Instance()->LoadTexture(303, "./Assets/Textures/Ballistics/missile_v1.png");
	TE::TextureManager::Instance()->LoadTexture(304, "./Assets/Textures/Ballistics/fireball_v1.png");
	TE::TextureManager::Instance()->LoadTexture(305, "./Assets/Textures/Ballistics/lazer_v1.png");
	TE::TextureManager::Instance()->LoadTexture(306, "./Assets/Textures/Ballistics/grenade_v1.png");
	TE::TextureManager::Instance()->LoadTexture(500, "./Assets/Textures/Course/crate.jpg");
	TE::TextureManager::Instance()->LoadTexture(501, "./Assets/Textures/Course/woodcrate_diffuse.jpg");
	TE::TextureManager::Instance()->LoadTexture(502, "./Assets/Textures/Course/robot_diffuse.jpg");
	TE::TextureManager::Instance()->LoadTexture(503, "./Assets/Textures/Course/bunny_diffuse.jpg");
	TE::TextureManager::Instance()->LoadTexture(504, "./Assets/Textures/Course/tile_floor.jpg");

	TE::ErrorManager::Instance()->DisplayErrors();

	TE::FontManager::Instance()->LoadFont(100, "ariel", "./Assets/Fonts/arial.ttf", 18);
	TE::FontManager::Instance()->LoadFont(101, "bank_gothic", "./Assets/Fonts/bank_gothic.ttf", 18);

	TE::ErrorManager::Instance()->DisplayErrors();

	TE::AudioManager::Instance()->SetListener();

	
	
	shared_ptr<TE::AudioClip> skate = make_shared<TE::AudioClip>();
	skate->LoadWAV2("./Assets/Audio/Komiku_04_Skate.wav");

	TE::ErrorManager::Instance()->DisplayErrors();

	shared_ptr<TE::AudioClip> battle = make_shared<TE::AudioClip>();
	battle->LoadWAV2("./Assets/Audio/Komiku_07_Battle_of_Pogs.wav");
	
	shared_ptr<TE::AudioSource> background = make_shared<TE::AudioSource>();
	background->AddClip(skate);
	
	shared_ptr<TE::AudioSource> movingBoxesBackground = make_shared<TE::AudioSource>();
	movingBoxesBackground->AddClip(battle);

	TE::ErrorManager::Instance()->DisplayErrors();

	TE::AudioManager::Instance()->AddClip(1, skate);
	TE::AudioManager::Instance()->AddClip(2, battle);
	TE::AudioManager::Instance()->AddSource(1, background);
	TE::AudioManager::Instance()->AddSource(2, movingBoxesBackground);

	//TE::AudioManager::Instance()->LoadClip(1, "./Assets/Audio/Komiku_04_Skate.wav");
	//TE::AudioManager::Instance()->LoadClip(2, "./Assets/Audio/Komiku_07_Battle_of_Pogs.wav");
	//TE::AudioManager::Instance()->LoadSource(1);
	//TE::AudioManager::Instance()->AddClipToSource(1, 1);
	
	//continue adding textures for glfw tests

	TE::ErrorManager::Instance()->DisplayErrors();


	//=====Add Levels=====
	
	//shared_ptr<SplashScreen> splashScreen = make_shared<SplashScreen>();
	//TE::Engine::Instance()->SetActiveLevel(splashScreen);
	
	/*shared_ptr<MainMenu> mainMenu = make_shared<MainMenu>();
	mainMenu->v_Init();
	TE::LevelManager::Instance()->Add(mainMenu);

	p_SplashScreen splashScreen = make_shared<SplashScreen>();
	splashScreen->v_Init();
	TE::Engine::Instance()->SetActiveLevel(splashScreen);*/

	p_TiledTest level = make_shared<TiledTest>();
	level->v_Init();
	TE::Engine::Instance()->SetActiveLevel(level);
	
	if(TE::ErrorManager::Instance()->DisplayErrors())
	{
		TE::Engine::Instance()->End();
	}

	while (TE::Engine::Instance()->Running()) 
	{
		TE::Engine::Instance()->Update();
		TE::Engine::Instance()->Render();
		
		if(TE::ErrorManager::Instance()->DisplayErrors())
		{
			TE::Engine::Instance()->End();
		}

		TE::GameWindow::Instance()->DisplayFPS();
	}
}
