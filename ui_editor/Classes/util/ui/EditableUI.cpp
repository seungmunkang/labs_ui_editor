//
//  EditableUI.cpp
//  ui_editor
//
//  Created by Seungmun Kang on 2016. 10. 30..
//
//

#include <stdio.h>
#include "EditableUI.h"

USING_NS_CC;

const std::string EditableUI::BORDER_TAG = "BORDER";

Sprite * EditableUI::CREATE_SPRITE(const std::string& filename)
{
    Sprite * _retval = Sprite::create(filename);
    
    return _retval;
}

void EditableUI::ADD_BORDER(Node * target)
{
    Size _size = target->getContentSize();
    Point _verts[4] = {Point(0, 0), Point(_size.width, 0), Point(_size.width, _size.height), Point(0, _size.height)};
    
    DrawNode * _border = DrawNode::create();
    
    _border->setName(EditableUI::BORDER_TAG);
    _border->setContentSize(_size);
    _border->setColor(Color3B::BLUE);
    
    _border->drawPolygon(_verts, 4, Color4F(0, 0, 0, 0), 4.0f, Color4F::BLUE);
    
    target->addChild(_border, 0);
}

void EditableUI::ADD_MENU(Node * target, const ccMenuCallback & callback)
{
    if (target != nullptr && callback != nullptr)
    {
        Size _size = target->getContentSize();
        
        Menu * _menu = Menu::create();
        _menu->setPosition(0, 0);
        target->addChild(_menu);
        
        MenuItem * _menuitem = MenuItem::create();
        _menuitem->setContentSize(_size);
        _menuitem->setCallback(callback);
        _menuitem->setAnchorPoint(Point(0, 0));
        _menuitem->setPosition(0, 0);
        _menu->addChild(_menuitem);
    }
}

void EditableUI::CONVERT_BORDER(Node * target)
{
    if (target != nullptr)
    {
        Node * _border = target->getChildByName(EditableUI::BORDER_TAG);
        if (_border != nullptr)
        {
            
            _border->setVisible(!_border->isVisible());
        }
        else
        {
            ADD_BORDER(target);
        }
    }
}
