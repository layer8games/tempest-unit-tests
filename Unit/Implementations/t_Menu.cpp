/*------------------------------------------------------------
The AABB is a Bounding Volume used 
in the Killer Collision engine. 

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
#include <Engine/Menu.h>
#include <Engine/Point.h>
#include <Engine/Text.h>

namespace TE = Tempest;
namespace TM = TempestMath;

/*

Disabled until gameobject can be smarter

class MenuSelector : public TE::GameObject
{
public:
	MenuSelector(void)
	{  }

	~MenuSelector(void)
	{  }

	void v_Update(void)
	{  }
};

BOOST_AUTO_TEST_CASE(MenuConstructorAndAccessors)
{
	TE::Menu menu{ };

	menu.SetPosition(TM::Point(50.0f, 100.0f));

	BOOST_CHECK_EQUAL(menu.GetPosition()[x], 50.0f);
	BOOST_CHECK_EQUAL(menu.GetPosition()[y], 100.0f);

	menu.SetItemOffset(TM::Point(0.0f, 25.0f));
	
	BOOST_CHECK_EQUAL(menu.GetItemOffset()[x], 0.0f);
	BOOST_CHECK_EQUAL(menu.GetItemOffset()[y], 25.0f);	

	menu.SetTitleOffset(TM::Point(0.0f, 50.0f));

	BOOST_CHECK_EQUAL(menu.GetTitleOffset()[x], 0.0f);
	BOOST_CHECK_EQUAL(menu.GetTitleOffset()[y], 50.0f);
}

bool menuItem1ActionStatus = false;

void MenuItem1Action(void)
{
	menuItem1ActionStatus = !menuItem1ActionStatus;
}

BOOST_AUTO_TEST_CASE(MenuItemAddRemove)
{
	TE::Menu menu { };

	menu.SetPosition(0.0f, -100.0f);
	menu.SetItemOffset(10.0f, -25.0f);
	menu.SetSelectorOffset(-10.0f, 0.0f);
	
	TE::MenuItem item1 { };
	item1.text = shared_ptr<TE::Text>(new TE::Text("Item1"));

	//Test that items are added and positions are correct.
	menu.AddItem(item1);

	BOOST_CHECK_EQUAL(menu.GetTotalItems(), 1);

	TE::MenuItem item2 { };
	item2.text = shared_ptr<TE::Text>(new TE::Text("Item2"));

	menu.AddItem(item2);

	std::vector<TE::MenuItem> list = menu.GetItemList();

	BOOST_CHECK_EQUAL(menu.GetTotalItems(), 2);

	BOOST_CHECK_EQUAL(list[0].pos[x], 0.0f);
	BOOST_CHECK_EQUAL(list[0].pos[y], -100.0f);

	BOOST_CHECK_EQUAL(list[1].pos[x], 10.0f);
	BOOST_CHECK_EQUAL(list[1].pos[y], -125.0f);

	menu.RemoveItem(1);

	BOOST_CHECK_EQUAL(menu.GetTotalItems(), 1);

	menu.RemoveItem(1);

	BOOST_CHECK_EQUAL(menu.GetTotalItems(), 1);

	menu.RemoveItem(0);

	BOOST_CHECK_EQUAL(menu.GetTotalItems(), 0);

	//Check that positions are updating if an index above is removed. 
	menu.AddItem(item1);
	menu.AddItem(item2);
	menu.RemoveItem(0);

	list = menu.GetItemList();

	BOOST_CHECK_EQUAL(list[0].pos[x], 0.0f);
	BOOST_CHECK_EQUAL(list[0].pos[y], -100.0f);	
}

BOOST_AUTO_TEST_CASE(MenuItemSelector)
{
	TE::Menu menu { };

	menu.SetPosition(0.0f, -100.0f);
	menu.SetItemOffset(0.0f, -25.0f);
	menu.SetTitleOffset(0.0f, -50.0f);
	menu.SetSelectorOffset(-10.0f, 0.0f);
	
	TE::MenuItem item1 { };
	item1.text = shared_ptr<TE::Text>(new TE::Text("Item1"));
	item1.Action = &MenuItem1Action;

	TE::MenuItem item2 { };
	item2.text = shared_ptr<TE::Text>(new TE::Text("Item2"));

	menu.AddItem(item1);
	menu.AddItem(item2);

	shared_ptr<MenuSelector> selector = make_shared<MenuSelector>();
	selector->SetActive(false);

	menu.SetSelector(selector);

	BOOST_CHECK_EQUAL(selector->GetPosition()[x], -10.0f);
	BOOST_CHECK_EQUAL(selector->GetPosition()[y], -150.0f);

	menu.MoveSelectorDown();

	BOOST_CHECK_EQUAL(selector->GetPosition()[x], -10.0f);
	BOOST_CHECK_EQUAL(selector->GetPosition()[y], -175.0f);

	menu.MoveSelectorUp();

	BOOST_CHECK_EQUAL(selector->GetPosition()[x], -10.0f);
	BOOST_CHECK_EQUAL(selector->GetPosition()[y], -150.0f);

	menu.SetSelectorPosition(1);

	BOOST_CHECK_EQUAL(selector->GetPosition()[x], -10.0f);
	BOOST_CHECK_EQUAL(selector->GetPosition()[y], -175.0f);

	menu.SetSelectorPosition(0);
	menu.CallSelectedAction();
	BOOST_CHECK_EQUAL(menuItem1ActionStatus, true);

	menu.CallSelectedAction();
	BOOST_CHECK_EQUAL(menuItem1ActionStatus, false);
}

*/