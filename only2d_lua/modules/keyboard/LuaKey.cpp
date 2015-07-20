//
// Created by leafnsand on 2015/7/20.
//

#include "LuaKey.h"

#include "modules/keyboard/Keyboard.h"

namespace only2d
{
	void LuaKey::openEnum(lua_State* L)
	{
		Lua::beginEnum(L);
		Lua::pushEnum<Key>(L, Key::RETURN);
		Lua::setField(L, -2, "RETURN");
		Lua::pushEnum<Key>(L, Key::ESCAPE);
		Lua::setField(L, -2, "ESCAPE");
		Lua::pushEnum<Key>(L, Key::BACKSPACE);
		Lua::setField(L, -2, "BACKSPACE");
		Lua::pushEnum<Key>(L, Key::TAB);
		Lua::setField(L, -2, "TAB");
		Lua::pushEnum<Key>(L, Key::SPACE);
		Lua::setField(L, -2, "SPACE");
		Lua::pushEnum<Key>(L, Key::EXCLAIM);
		Lua::setField(L, -2, "EXCLAIM");
		Lua::pushEnum<Key>(L, Key::QUOTEDBL);
		Lua::setField(L, -2, "QUOTEDBL");
		Lua::pushEnum<Key>(L, Key::HASH);
		Lua::setField(L, -2, "HASH");
		Lua::pushEnum<Key>(L, Key::PERCENT);
		Lua::setField(L, -2, "PERCENT");
		Lua::pushEnum<Key>(L, Key::DOLLAR);
		Lua::setField(L, -2, "DOLLAR");
		Lua::pushEnum<Key>(L, Key::AMPERSAND);
		Lua::setField(L, -2, "AMPERSAND");
		Lua::pushEnum<Key>(L, Key::QUOTE);
		Lua::setField(L, -2, "QUOTE");
		Lua::pushEnum<Key>(L, Key::LEFTPAREN);
		Lua::setField(L, -2, "LEFTPAREN");
		Lua::pushEnum<Key>(L, Key::RIGHTPAREN);
		Lua::setField(L, -2, "RIGHTPAREN");
		Lua::pushEnum<Key>(L, Key::ASTERISK);
		Lua::setField(L, -2, "ASTERISK");
		Lua::pushEnum<Key>(L, Key::PLUS);
		Lua::setField(L, -2, "PLUS");
		Lua::pushEnum<Key>(L, Key::COMMA);
		Lua::setField(L, -2, "COMMA");
		Lua::pushEnum<Key>(L, Key::MINUS);
		Lua::setField(L, -2, "MINUS");
		Lua::pushEnum<Key>(L, Key::PERIOD);
		Lua::setField(L, -2, "PERIOD");
		Lua::pushEnum<Key>(L, Key::SLASH);
		Lua::setField(L, -2, "SLASH");
		Lua::pushEnum<Key>(L, Key::NUM_0);
		Lua::setField(L, -2, "NUM_0");
		Lua::pushEnum<Key>(L, Key::NUM_1);
		Lua::setField(L, -2, "NUM_1");
		Lua::pushEnum<Key>(L, Key::NUM_2);
		Lua::setField(L, -2, "NUM_2");
		Lua::pushEnum<Key>(L, Key::NUM_3);
		Lua::setField(L, -2, "NUM_3");
		Lua::pushEnum<Key>(L, Key::NUM_4);
		Lua::setField(L, -2, "NUM_4");
		Lua::pushEnum<Key>(L, Key::NUM_5);
		Lua::setField(L, -2, "NUM_5");
		Lua::pushEnum<Key>(L, Key::NUM_6);
		Lua::setField(L, -2, "NUM_6");
		Lua::pushEnum<Key>(L, Key::NUM_7);
		Lua::setField(L, -2, "NUM_7");
		Lua::pushEnum<Key>(L, Key::NUM_8);
		Lua::setField(L, -2, "NUM_8");
		Lua::pushEnum<Key>(L, Key::NUM_9);
		Lua::setField(L, -2, "NUM_9");
		Lua::pushEnum<Key>(L, Key::COLON);
		Lua::setField(L, -2, "COLON");
		Lua::pushEnum<Key>(L, Key::SEMICOLON);
		Lua::setField(L, -2, "SEMICOLON");
		Lua::pushEnum<Key>(L, Key::LESS);
		Lua::setField(L, -2, "LESS");
		Lua::pushEnum<Key>(L, Key::EQUALS);
		Lua::setField(L, -2, "EQUALS");
		Lua::pushEnum<Key>(L, Key::GREATER);
		Lua::setField(L, -2, "GREATER");
		Lua::pushEnum<Key>(L, Key::QUESTION);
		Lua::setField(L, -2, "QUESTION");
		Lua::pushEnum<Key>(L, Key::AT);
		Lua::setField(L, -2, "AT");
		Lua::pushEnum<Key>(L, Key::LEFTBRACKET);
		Lua::setField(L, -2, "LEFTBRACKET");
		Lua::pushEnum<Key>(L, Key::BACKSLASH);
		Lua::setField(L, -2, "BACKSLASH");
		Lua::pushEnum<Key>(L, Key::RIGHTBRACKET);
		Lua::setField(L, -2, "RIGHTBRACKET");
		Lua::pushEnum<Key>(L, Key::CARET);
		Lua::setField(L, -2, "CARET");
		Lua::pushEnum<Key>(L, Key::UNDERSCORE);
		Lua::setField(L, -2, "UNDERSCORE");
		Lua::pushEnum<Key>(L, Key::BACKQUOTE);
		Lua::setField(L, -2, "BACKQUOTE");
		Lua::pushEnum<Key>(L, Key::A);
		Lua::setField(L, -2, "A");
		Lua::pushEnum<Key>(L, Key::B);
		Lua::setField(L, -2, "B");
		Lua::pushEnum<Key>(L, Key::C);
		Lua::setField(L, -2, "C");
		Lua::pushEnum<Key>(L, Key::D);
		Lua::setField(L, -2, "D");
		Lua::pushEnum<Key>(L, Key::E);
		Lua::setField(L, -2, "E");
		Lua::pushEnum<Key>(L, Key::F);
		Lua::setField(L, -2, "F");
		Lua::pushEnum<Key>(L, Key::G);
		Lua::setField(L, -2, "G");
		Lua::pushEnum<Key>(L, Key::H);
		Lua::setField(L, -2, "H");
		Lua::pushEnum<Key>(L, Key::I);
		Lua::setField(L, -2, "I");
		Lua::pushEnum<Key>(L, Key::J);
		Lua::setField(L, -2, "J");
		Lua::pushEnum<Key>(L, Key::K);
		Lua::setField(L, -2, "K");
		Lua::pushEnum<Key>(L, Key::L);
		Lua::setField(L, -2, "L");
		Lua::pushEnum<Key>(L, Key::M);
		Lua::setField(L, -2, "M");
		Lua::pushEnum<Key>(L, Key::N);
		Lua::setField(L, -2, "N");
		Lua::pushEnum<Key>(L, Key::O);
		Lua::setField(L, -2, "O");
		Lua::pushEnum<Key>(L, Key::P);
		Lua::setField(L, -2, "P");
		Lua::pushEnum<Key>(L, Key::Q);
		Lua::setField(L, -2, "Q");
		Lua::pushEnum<Key>(L, Key::R);
		Lua::setField(L, -2, "R");
		Lua::pushEnum<Key>(L, Key::S);
		Lua::setField(L, -2, "S");
		Lua::pushEnum<Key>(L, Key::T);
		Lua::setField(L, -2, "T");
		Lua::pushEnum<Key>(L, Key::U);
		Lua::setField(L, -2, "U");
		Lua::pushEnum<Key>(L, Key::V);
		Lua::setField(L, -2, "V");
		Lua::pushEnum<Key>(L, Key::W);
		Lua::setField(L, -2, "W");
		Lua::pushEnum<Key>(L, Key::X);
		Lua::setField(L, -2, "X");
		Lua::pushEnum<Key>(L, Key::Y);
		Lua::setField(L, -2, "Y");
		Lua::pushEnum<Key>(L, Key::Z);
		Lua::setField(L, -2, "Z");
		Lua::pushEnum<Key>(L, Key::CAPSLOCK);
		Lua::setField(L, -2, "CAPSLOCK");
		Lua::pushEnum<Key>(L, Key::F1);
		Lua::setField(L, -2, "F1");
		Lua::pushEnum<Key>(L, Key::F2);
		Lua::setField(L, -2, "F2");
		Lua::pushEnum<Key>(L, Key::F3);
		Lua::setField(L, -2, "F3");
		Lua::pushEnum<Key>(L, Key::F4);
		Lua::setField(L, -2, "F4");
		Lua::pushEnum<Key>(L, Key::F5);
		Lua::setField(L, -2, "F5");
		Lua::pushEnum<Key>(L, Key::F6);
		Lua::setField(L, -2, "F6");
		Lua::pushEnum<Key>(L, Key::F7);
		Lua::setField(L, -2, "F7");
		Lua::pushEnum<Key>(L, Key::F8);
		Lua::setField(L, -2, "F8");
		Lua::pushEnum<Key>(L, Key::F9);
		Lua::setField(L, -2, "F9");
		Lua::pushEnum<Key>(L, Key::F10);
		Lua::setField(L, -2, "F10");
		Lua::pushEnum<Key>(L, Key::F11);
		Lua::setField(L, -2, "F11");
		Lua::pushEnum<Key>(L, Key::F12);
		Lua::setField(L, -2, "F12");
		Lua::pushEnum<Key>(L, Key::PRINTSCREEN);
		Lua::setField(L, -2, "PRINTSCREEN");
		Lua::pushEnum<Key>(L, Key::SCROLLLOCK);
		Lua::setField(L, -2, "SCROLLLOCK");
		Lua::pushEnum<Key>(L, Key::PAUSE);
		Lua::setField(L, -2, "PAUSE");
		Lua::pushEnum<Key>(L, Key::INSERT);
		Lua::setField(L, -2, "INSERT");
		Lua::pushEnum<Key>(L, Key::HOME);
		Lua::setField(L, -2, "HOME");
		Lua::pushEnum<Key>(L, Key::PAGEUP);
		Lua::setField(L, -2, "PAGEUP");
		Lua::pushEnum<Key>(L, Key::DEL);
		Lua::setField(L, -2, "DEL");
		Lua::pushEnum<Key>(L, Key::END);
		Lua::setField(L, -2, "END");
		Lua::pushEnum<Key>(L, Key::PAGEDOWN);
		Lua::setField(L, -2, "PAGEDOWN");
		Lua::pushEnum<Key>(L, Key::RIGHT);
		Lua::setField(L, -2, "RIGHT");
		Lua::pushEnum<Key>(L, Key::LEFT);
		Lua::setField(L, -2, "LEFT");
		Lua::pushEnum<Key>(L, Key::DOWN);
		Lua::setField(L, -2, "DOWN");
		Lua::pushEnum<Key>(L, Key::UP);
		Lua::setField(L, -2, "UP");
		Lua::pushEnum<Key>(L, Key::NUMLOCKCLEAR);
		Lua::setField(L, -2, "NUMLOCKCLEAR");
		Lua::pushEnum<Key>(L, Key::KP_DIVIDE);
		Lua::setField(L, -2, "KP_DIVIDE");
		Lua::pushEnum<Key>(L, Key::KP_MULTIPLY);
		Lua::setField(L, -2, "KP_MULTIPLY");
		Lua::pushEnum<Key>(L, Key::KP_MINUS);
		Lua::setField(L, -2, "KP_MINUS");
		Lua::pushEnum<Key>(L, Key::KP_PLUS);
		Lua::setField(L, -2, "KP_PLUS");
		Lua::pushEnum<Key>(L, Key::KP_ENTER);
		Lua::setField(L, -2, "KP_ENTER");
		Lua::pushEnum<Key>(L, Key::KP_1);
		Lua::setField(L, -2, "KP_1");
		Lua::pushEnum<Key>(L, Key::KP_2);
		Lua::setField(L, -2, "KP_2");
		Lua::pushEnum<Key>(L, Key::KP_3);
		Lua::setField(L, -2, "KP_3");
		Lua::pushEnum<Key>(L, Key::KP_4);
		Lua::setField(L, -2, "KP_4");
		Lua::pushEnum<Key>(L, Key::KP_5);
		Lua::setField(L, -2, "KP_5");
		Lua::pushEnum<Key>(L, Key::KP_6);
		Lua::setField(L, -2, "KP_6");
		Lua::pushEnum<Key>(L, Key::KP_7);
		Lua::setField(L, -2, "KP_7");
		Lua::pushEnum<Key>(L, Key::KP_8);
		Lua::setField(L, -2, "KP_8");
		Lua::pushEnum<Key>(L, Key::KP_9);
		Lua::setField(L, -2, "KP_9");
		Lua::pushEnum<Key>(L, Key::KP_0);
		Lua::setField(L, -2, "KP_0");
		Lua::pushEnum<Key>(L, Key::KP_PERIOD);
		Lua::setField(L, -2, "KP_PERIOD");
		Lua::pushEnum<Key>(L, Key::APPLICATION);
		Lua::setField(L, -2, "APPLICATION");
		Lua::pushEnum<Key>(L, Key::POWER);
		Lua::setField(L, -2, "POWER");
		Lua::pushEnum<Key>(L, Key::KP_EQUALS);
		Lua::setField(L, -2, "KP_EQUALS");
		Lua::pushEnum<Key>(L, Key::F13);
		Lua::setField(L, -2, "F13");
		Lua::pushEnum<Key>(L, Key::F14);
		Lua::setField(L, -2, "F14");
		Lua::pushEnum<Key>(L, Key::F15);
		Lua::setField(L, -2, "F15");
		Lua::pushEnum<Key>(L, Key::F16);
		Lua::setField(L, -2, "F16");
		Lua::pushEnum<Key>(L, Key::F17);
		Lua::setField(L, -2, "F17");
		Lua::pushEnum<Key>(L, Key::F18);
		Lua::setField(L, -2, "F18");
		Lua::pushEnum<Key>(L, Key::F19);
		Lua::setField(L, -2, "F19");
		Lua::pushEnum<Key>(L, Key::F20);
		Lua::setField(L, -2, "F20");
		Lua::pushEnum<Key>(L, Key::F21);
		Lua::setField(L, -2, "F21");
		Lua::pushEnum<Key>(L, Key::F22);
		Lua::setField(L, -2, "F22");
		Lua::pushEnum<Key>(L, Key::F23);
		Lua::setField(L, -2, "F23");
		Lua::pushEnum<Key>(L, Key::F24);
		Lua::setField(L, -2, "F24");
		Lua::pushEnum<Key>(L, Key::EXECUTE);
		Lua::setField(L, -2, "EXECUTE");
		Lua::pushEnum<Key>(L, Key::HELP);
		Lua::setField(L, -2, "HELP");
		Lua::pushEnum<Key>(L, Key::MENU);
		Lua::setField(L, -2, "MENU");
		Lua::pushEnum<Key>(L, Key::SELECT);
		Lua::setField(L, -2, "SELECT");
		Lua::pushEnum<Key>(L, Key::STOP);
		Lua::setField(L, -2, "STOP");
		Lua::pushEnum<Key>(L, Key::AGAIN);
		Lua::setField(L, -2, "AGAIN");
		Lua::pushEnum<Key>(L, Key::UNDO);
		Lua::setField(L, -2, "UNDO");
		Lua::pushEnum<Key>(L, Key::CUT);
		Lua::setField(L, -2, "CUT");
		Lua::pushEnum<Key>(L, Key::COPY);
		Lua::setField(L, -2, "COPY");
		Lua::pushEnum<Key>(L, Key::PASTE);
		Lua::setField(L, -2, "PASTE");
		Lua::pushEnum<Key>(L, Key::FIND);
		Lua::setField(L, -2, "FIND");
		Lua::pushEnum<Key>(L, Key::MUTE);
		Lua::setField(L, -2, "MUTE");
		Lua::pushEnum<Key>(L, Key::VOLUMEUP);
		Lua::setField(L, -2, "VOLUMEUP");
		Lua::pushEnum<Key>(L, Key::VOLUMEDOWN);
		Lua::setField(L, -2, "VOLUMEDOWN");
		Lua::pushEnum<Key>(L, Key::KP_COMMA);
		Lua::setField(L, -2, "KP_COMMA");
		Lua::pushEnum<Key>(L, Key::KP_EQUALSAS400);
		Lua::setField(L, -2, "KP_EQUALSAS400");
		Lua::pushEnum<Key>(L, Key::ALTERASE);
		Lua::setField(L, -2, "ALTERASE");
		Lua::pushEnum<Key>(L, Key::SYSREQ);
		Lua::setField(L, -2, "SYSREQ");
		Lua::pushEnum<Key>(L, Key::CANCEL);
		Lua::setField(L, -2, "CANCEL");
		Lua::pushEnum<Key>(L, Key::CLEAR);
		Lua::setField(L, -2, "CLEAR");
		Lua::pushEnum<Key>(L, Key::PRIOR);
		Lua::setField(L, -2, "PRIOR");
		Lua::pushEnum<Key>(L, Key::RETURN2);
		Lua::setField(L, -2, "RETURN2");
		Lua::pushEnum<Key>(L, Key::SEPARATOR);
		Lua::setField(L, -2, "SEPARATOR");
		Lua::pushEnum<Key>(L, Key::KEY_OUT);
		Lua::setField(L, -2, "KEY_OUT");
		Lua::pushEnum<Key>(L, Key::OPER);
		Lua::setField(L, -2, "OPER");
		Lua::pushEnum<Key>(L, Key::CLEARAGAIN);
		Lua::setField(L, -2, "CLEARAGAIN");
		Lua::pushEnum<Key>(L, Key::CRSEL);
		Lua::setField(L, -2, "CRSEL");
		Lua::pushEnum<Key>(L, Key::EXSEL);
		Lua::setField(L, -2, "EXSEL");
		Lua::pushEnum<Key>(L, Key::KP_00);
		Lua::setField(L, -2, "KP_00");
		Lua::pushEnum<Key>(L, Key::KP_000);
		Lua::setField(L, -2, "KP_000");
		Lua::pushEnum<Key>(L, Key::THOUSANDSSEPARATOR);
		Lua::setField(L, -2, "THOUSANDSSEPARATOR");
		Lua::pushEnum<Key>(L, Key::DECIMALSEPARATOR);
		Lua::setField(L, -2, "DECIMALSEPARATOR");
		Lua::pushEnum<Key>(L, Key::CURRENCYUNIT);
		Lua::setField(L, -2, "CURRENCYUNIT");
		Lua::pushEnum<Key>(L, Key::CURRENCYSUBUNIT);
		Lua::setField(L, -2, "CURRENCYSUBUNIT");
		Lua::pushEnum<Key>(L, Key::KP_LEFTPAREN);
		Lua::setField(L, -2, "KP_LEFTPAREN");
		Lua::pushEnum<Key>(L, Key::KP_RIGHTPAREN);
		Lua::setField(L, -2, "KP_RIGHTPAREN");
		Lua::pushEnum<Key>(L, Key::KP_LEFTBRACE);
		Lua::setField(L, -2, "KP_LEFTBRACE");
		Lua::pushEnum<Key>(L, Key::KP_RIGHTBRACE);
		Lua::setField(L, -2, "KP_RIGHTBRACE");
		Lua::pushEnum<Key>(L, Key::KP_TAB);
		Lua::setField(L, -2, "KP_TAB");
		Lua::pushEnum<Key>(L, Key::KP_BACKSPACE);
		Lua::setField(L, -2, "KP_BACKSPACE");
		Lua::pushEnum<Key>(L, Key::KP_A);
		Lua::setField(L, -2, "KP_A");
		Lua::pushEnum<Key>(L, Key::KP_B);
		Lua::setField(L, -2, "KP_B");
		Lua::pushEnum<Key>(L, Key::KP_C);
		Lua::setField(L, -2, "KP_C");
		Lua::pushEnum<Key>(L, Key::KP_D);
		Lua::setField(L, -2, "KP_D");
		Lua::pushEnum<Key>(L, Key::KP_E);
		Lua::setField(L, -2, "KP_E");
		Lua::pushEnum<Key>(L, Key::KP_F);
		Lua::setField(L, -2, "KP_F");
		Lua::pushEnum<Key>(L, Key::KP_XOR);
		Lua::setField(L, -2, "KP_XOR");
		Lua::pushEnum<Key>(L, Key::KP_POWER);
		Lua::setField(L, -2, "KP_POWER");
		Lua::pushEnum<Key>(L, Key::KP_PERCENT);
		Lua::setField(L, -2, "KP_PERCENT");
		Lua::pushEnum<Key>(L, Key::KP_LESS);
		Lua::setField(L, -2, "KP_LESS");
		Lua::pushEnum<Key>(L, Key::KP_GREATER);
		Lua::setField(L, -2, "KP_GREATER");
		Lua::pushEnum<Key>(L, Key::KP_AMPERSAND);
		Lua::setField(L, -2, "KP_AMPERSAND");
		Lua::pushEnum<Key>(L, Key::KP_DBLAMPERSAND);
		Lua::setField(L, -2, "KP_DBLAMPERSAND");
		Lua::pushEnum<Key>(L, Key::KP_VERTICALBAR);
		Lua::setField(L, -2, "KP_VERTICALBAR");
		Lua::pushEnum<Key>(L, Key::KP_DBLVERTICALBAR);
		Lua::setField(L, -2, "KP_DBLVERTICALBAR");
		Lua::pushEnum<Key>(L, Key::KP_COLON);
		Lua::setField(L, -2, "KP_COLON");
		Lua::pushEnum<Key>(L, Key::KP_HASH);
		Lua::setField(L, -2, "KP_HASH");
		Lua::pushEnum<Key>(L, Key::KP_SPACE);
		Lua::setField(L, -2, "KP_SPACE");
		Lua::pushEnum<Key>(L, Key::KP_AT);
		Lua::setField(L, -2, "KP_AT");
		Lua::pushEnum<Key>(L, Key::KP_EXCLAM);
		Lua::setField(L, -2, "KP_EXCLAM");
		Lua::pushEnum<Key>(L, Key::KP_MEMSTORE);
		Lua::setField(L, -2, "KP_MEMSTORE");
		Lua::pushEnum<Key>(L, Key::KP_MEMRECALL);
		Lua::setField(L, -2, "KP_MEMRECALL");
		Lua::pushEnum<Key>(L, Key::KP_MEMCLEAR);
		Lua::setField(L, -2, "KP_MEMCLEAR");
		Lua::pushEnum<Key>(L, Key::KP_MEMADD);
		Lua::setField(L, -2, "KP_MEMADD");
		Lua::pushEnum<Key>(L, Key::KP_MEMSUBTRACT);
		Lua::setField(L, -2, "KP_MEMSUBTRACT");
		Lua::pushEnum<Key>(L, Key::KP_MEMMULTIPLY);
		Lua::setField(L, -2, "KP_MEMMULTIPLY");
		Lua::pushEnum<Key>(L, Key::KP_MEMDIVIDE);
		Lua::setField(L, -2, "KP_MEMDIVIDE");
		Lua::pushEnum<Key>(L, Key::KP_PLUSMINUS);
		Lua::setField(L, -2, "KP_PLUSMINUS");
		Lua::pushEnum<Key>(L, Key::KP_CLEAR);
		Lua::setField(L, -2, "KP_CLEAR");
		Lua::pushEnum<Key>(L, Key::KP_CLEARENTRY);
		Lua::setField(L, -2, "KP_CLEARENTRY");
		Lua::pushEnum<Key>(L, Key::KP_BINARY);
		Lua::setField(L, -2, "KP_BINARY");
		Lua::pushEnum<Key>(L, Key::KP_OCTAL);
		Lua::setField(L, -2, "KP_OCTAL");
		Lua::pushEnum<Key>(L, Key::KP_DECIMAL);
		Lua::setField(L, -2, "KP_DECIMAL");
		Lua::pushEnum<Key>(L, Key::KP_HEXADECIMAL);
		Lua::setField(L, -2, "KP_HEXADECIMAL");
		Lua::pushEnum<Key>(L, Key::LCTRL);
		Lua::setField(L, -2, "LCTRL");
		Lua::pushEnum<Key>(L, Key::LSHIFT);
		Lua::setField(L, -2, "LSHIFT");
		Lua::pushEnum<Key>(L, Key::LALT);
		Lua::setField(L, -2, "LALT");
		Lua::pushEnum<Key>(L, Key::LGUI);
		Lua::setField(L, -2, "LGUI");
		Lua::pushEnum<Key>(L, Key::RCTRL);
		Lua::setField(L, -2, "RCTRL");
		Lua::pushEnum<Key>(L, Key::RSHIFT);
		Lua::setField(L, -2, "RSHIFT");
		Lua::pushEnum<Key>(L, Key::RALT);
		Lua::setField(L, -2, "RALT");
		Lua::pushEnum<Key>(L, Key::RGUI);
		Lua::setField(L, -2, "RGUI");
		Lua::pushEnum<Key>(L, Key::MODE);
		Lua::setField(L, -2, "MODE");
		Lua::pushEnum<Key>(L, Key::AUDIONEXT);
		Lua::setField(L, -2, "AUDIONEXT");
		Lua::pushEnum<Key>(L, Key::AUDIOPREV);
		Lua::setField(L, -2, "AUDIOPREV");
		Lua::pushEnum<Key>(L, Key::AUDIOSTOP);
		Lua::setField(L, -2, "AUDIOSTOP");
		Lua::pushEnum<Key>(L, Key::AUDIOPLAY);
		Lua::setField(L, -2, "AUDIOPLAY");
		Lua::pushEnum<Key>(L, Key::AUDIOMUTE);
		Lua::setField(L, -2, "AUDIOMUTE");
		Lua::pushEnum<Key>(L, Key::MEDIASELECT);
		Lua::setField(L, -2, "MEDIASELECT");
		Lua::pushEnum<Key>(L, Key::WWW);
		Lua::setField(L, -2, "WWW");
		Lua::pushEnum<Key>(L, Key::MAIL);
		Lua::setField(L, -2, "MAIL");
		Lua::pushEnum<Key>(L, Key::CALCULATOR);
		Lua::setField(L, -2, "CALCULATOR");
		Lua::pushEnum<Key>(L, Key::COMPUTER);
		Lua::setField(L, -2, "COMPUTER");
		Lua::pushEnum<Key>(L, Key::AC_SEARCH);
		Lua::setField(L, -2, "AC_SEARCH");
		Lua::pushEnum<Key>(L, Key::AC_HOME);
		Lua::setField(L, -2, "AC_HOME");
		Lua::pushEnum<Key>(L, Key::AC_BACK);
		Lua::setField(L, -2, "AC_BACK");
		Lua::pushEnum<Key>(L, Key::AC_FORWARD);
		Lua::setField(L, -2, "AC_FORWARD");
		Lua::pushEnum<Key>(L, Key::AC_STOP);
		Lua::setField(L, -2, "AC_STOP");
		Lua::pushEnum<Key>(L, Key::AC_REFRESH);
		Lua::setField(L, -2, "AC_REFRESH");
		Lua::pushEnum<Key>(L, Key::AC_BOOKMARKS);
		Lua::setField(L, -2, "AC_BOOKMARKS");
		Lua::pushEnum<Key>(L, Key::BRIGHTNESSDOWN);
		Lua::setField(L, -2, "BRIGHTNESSDOWN");
		Lua::pushEnum<Key>(L, Key::BRIGHTNESSUP);
		Lua::setField(L, -2, "BRIGHTNESSUP");
		Lua::pushEnum<Key>(L, Key::DISPLAYSWITCH);
		Lua::setField(L, -2, "DISPLAYSWITCH");
		Lua::pushEnum<Key>(L, Key::KBDILLUMTOGGLE);
		Lua::setField(L, -2, "KBDILLUMTOGGLE");
		Lua::pushEnum<Key>(L, Key::KBDILLUMDOWN);
		Lua::setField(L, -2, "KBDILLUMDOWN");
		Lua::pushEnum<Key>(L, Key::KBDILLUMUP);
		Lua::setField(L, -2, "KBDILLUMUP");
		Lua::pushEnum<Key>(L, Key::EJECT);
		Lua::setField(L, -2, "EJECT");
		Lua::pushEnum<Key>(L, Key::SLEEP);
		Lua::setField(L, -2, "SLEEP");
		Lua::finishEnum(L, "Key");
	}
}