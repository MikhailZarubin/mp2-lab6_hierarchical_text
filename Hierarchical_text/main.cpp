#include"Text.h"
TMem TTextLink::mem;
void main()
{
	TTextLink::InitMem();
	TText text;
	text.Read("text.txt");
	text.Print();
	std::cout << '\n';
	std::cout << std::endl << "Free list : ";
	TTextLink::PrintFree(text);
	TTextLink::clean(text);
	std::cout << std::endl << "New free list : " << std::endl;
	TTextLink::PrintFree(text);
	char str[] = "gamm";
	for (text.Reset(); !text.IsEmpty(); text.GoNext())
	{
		if (!strcmp(text.GetCurr()->str, str))
		{
			text.DelDownLine();
			break;
		}
	}
	std::cout << '\n';
	text.Print();
	std::cout << std::endl << "Free list : ";
	TTextLink::PrintFree(text);
	TTextLink::clean(text);
	std::cout << std::endl << "New free list : " << std::endl;
	TTextLink::PrintFree(text);
	for (text.Reset(); !text.IsEmpty(); text.GoNext())
	{
		if (text.GetCurr()->str[0] == str[0] && text.GetCurr()->str[1] == str[1] && text.GetCurr()->str[3] == str[3])
		{
			text.InsDownLine("new_line");
			break;
		}
	}
	std::cout << '\n';
	text.Print();
	std::cout << std::endl << "Free list : ";
	TTextLink::PrintFree(text);
	TTextLink::clean(text);
	std::cout << std::endl << "New free list : " << std::endl;
	TTextLink::PrintFree(text);
	for (text.Reset(); !text.IsEmpty(); text.GoNext())
	{
		if (text.GetCurr()->str[0] == str[0] && text.GetCurr()->str[1] == str[1] && text.GetCurr()->str[3] == str[3])
		{
			text.DelNextLine();
			break;
		}
	}
	std::cout << '\n';
	text.Print();
	std::cout << std::endl << "Free list : ";
	TTextLink::PrintFree(text);
	TTextLink::clean(text);
	std::cout << std::endl << "New free list : ";
	TTextLink::PrintFree(text);
	text.SaveS("read.txt");
}