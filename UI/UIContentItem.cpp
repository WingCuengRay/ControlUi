#include "UIContentItem.h"
#include"DebugTool.h"

UIContentItem::UIContentItem()
{

}

UIContentItem::~UIContentItem()
{

}

void UIContentItem::show(const SizeBox)
{
    DebugTool *debugTool = DebugTool::getSingleton();
    debugTool->outputString("UIContentItem::show output one line\n");
}

