#include"Text.h"
void main()
{
	TText text;
	text.ReadS("text.txt");
	text.SaveS("read.txt");
	text.PrintS();
	std::cout << '\n';
	TText copy(text);
	copy.PrintS();
}