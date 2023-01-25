#include "DynoPipe.h"
#include "DynoGame.h"
#include "Utils.h"

#pragma region methods
void DynoPipe::SetGapPosition(const int _gap)
{
    gapPosition = _gap;
}
void DynoPipe::SetPosition(const int _gap)
{
    position = _gap;
}
void DynoPipe::SetCanDraw(const bool _status)
{
    canDraw = _status;
}
int DynoPipe::GapPosition() const
{
    return gapPosition;;
}
int DynoPipe::Position() const
{
    return position;
}
bool DynoPipe::CanDraw() const
{
    return canDraw;
}
#pragma endregion
#pragma region override
void DynoPipe::Draw()
{
    if (!canDraw)
        return;
    for (int i = 0; i < gapPosition; i++)
    {
        Utils::SetCursorPosition(WIN_WIDTH - position, i + 1);
        std::cout << PIPE;
    }
    for (int i = gapPosition + GAP_SIZE; i < SCREEN_HEIGHT; i++)
    {
        Utils::SetCursorPosition(WIN_WIDTH - position, i);
        std::cout << PIPE;
    }
}
void DynoPipe::Erase()
{
    if (!canDraw)
        return;
    for (int i = 0; i < gapPosition; i++)
    {
        Utils::SetCursorPosition(WIN_WIDTH - position, i + 1);
        std::cout << Utils::Separator(strlen(PIPE), ' ');
    }
    for (int i = gapPosition + GAP_SIZE; i < SCREEN_HEIGHT; i++)
    {
        Utils::SetCursorPosition(WIN_WIDTH - position, i);
        std::cout << Utils::Separator(strlen(PIPE), ' ');
    }
}
void DynoPipe::Update()
{
    if (!canDraw)
        return;
    position += 2;
}
#pragma endregion
