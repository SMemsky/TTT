#pragma once

#include <vector>

// Base class for all widgets
class Widget
{
	friend class Interface;
public:
	Widget();
	~Widget();

	void addChild(Widget* child);
	void removeChild(Widget* child);
private:
	void setParent(Widget* parent);
private:
	Widget* m_parent;

	std::vector<Widget*> m_widgets;
};
