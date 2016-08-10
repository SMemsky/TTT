#include "Widget.h"

#include <cassert>

Widget::Widget() :
	m_parent(nullptr),
	m_widgets()
{}

Widget::~Widget()
{
	if (m_parent != nullptr)
	{
		m_parent->removeChild(this);
	}
}

void Widget::addChild(Widget* child)
{
	assert(child != nullptr);

	m_widgets.push_back(child);

	child->setParent(this);
}

void Widget::removeChild(Widget* child)
{
	assert(child != nullptr);

	unsigned end = m_widgets.size();
	for (unsigned i = 0; i < end; ++i)
	{
		if (m_widgets[i] == child)
		{
			m_widgets[i]->setParent(nullptr);
			m_widgets.erase(m_widgets.begin() + i);
		}
	}
}

void Widget::setParent(Widget* parent)
{
	// TODO
	if (parent == nullptr)
	{
		m_parent = parent;
	}
	else
	{
		assert(m_parent == nullptr);
		m_parent = parent;
	}
}
