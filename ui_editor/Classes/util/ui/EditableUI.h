//
//  EditableUI.h
//  ui_editor
//
//  Created by Seungmun Kang on 2016. 10. 30..
//
//

#ifndef EditableUI_h
#define EditableUI_h

//#include "cocos2d.h"

using namespace cocos2d;

class EditableUI : public Node
{
public:
    static const std::string BORDER_TAG;
    
    static Sprite * CREATE_SPRITE(const std::string& filename);
    static void ADD_BORDER(Node * target);
    
    static void setVisibleBorder(Node * target, bool visible);
    
    
};

#endif /* EditableUI_h */

