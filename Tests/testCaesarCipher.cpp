#include "pch.h"
#include "../DrWebTest/CaesarCipher.hpp"

TEST(CaesarCipher, InitialTest)
{
	std::wstring str = L"Somebody once told me the world is gonna roll me! (Chars for test: とげとげタルめいろ一時 間スーパードンキーコング)";
	std::wstring str_crypted = get_ceasar_string(str);
	ASSERT_STREQ(str_crypted.c_str(), L"Vrphergb rqfh wrog ph wkh zruog lv jrqqd uroo ph! (Fkduv iru whvw: とげとげタルめいろ一時 間スーパードンキーコング)");
}