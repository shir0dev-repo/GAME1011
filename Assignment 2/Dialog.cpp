#include "Dialog.h"

Dialog::Dialog() {
	m_Speaker = "";
	m_Text = "";
}
Dialog::Dialog(std::string speaker, std::string text)
{
	m_Speaker = speaker;
	m_Text = text;
}