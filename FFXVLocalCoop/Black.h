#pragma once

enum MouseCursorVisibleState
{
	MOUSECURSOR_VISIBLE = 0,
	MOUSECURSOR_INVISIBLE_TRIGGERED = 1,
	MOUSECURSOR_INVISIBLE = 2
};


struct BlackMain
{
	char other[0xD08B];
	MouseCursorVisibleState mouseCursorVisibleState_;
	char rest[0x26];
};