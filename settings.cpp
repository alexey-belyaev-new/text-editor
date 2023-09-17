/**************************************
* Команда 2
* Гипертекстовый редактор
*
* Код класса окна настроек
***************************************/

#include "settings.h"

Settings::Settings():
    _language(Language::Russian),
    _theme(Theme::Light)
{
    if (!LoadSettings())
        SaveSettings();
}

// Задать значение настройки текущего языка интерфейса
void Settings::SetLanguage(const Language language)
{
    _language = language;

    SaveSettings();
}

// Задать значение настройки текущей темы интерфейса
void Settings::SetTheme(const Theme theme)
{
    _theme = theme;

    SaveSettings();
}

// Загрузка настроек
bool Settings::LoadSettings()
{

    return false;
}

// Сохранение настроек
bool Settings::SaveSettings()
{

    return false;
}
