/**************************************
* Команда 2
* Гипертекстовый редактор
*
* Файл заголовков класса окна настроек
***************************************/

#pragma once

/*!
 * \brief The Languadge enum Перечисление доступных языков интерфейса
 */
enum class Language
{
    Russian,
    English
};

/*!
 * \brief The Theme enum Перечисление доступных тем интерфейса
 */
enum class Theme
{
    Light,
    Dark
};

/*!
 * \brief The settings Класс для загрузки, доступа и сохранения настроек
 */
class Settings
{
    //TODO: Сделать Singleton!!!

public:
    /// Конструктор
    Settings();

    /*!
     * \brief GetLanguage Получить значение настройки текущего языка интерфейса
     * \return Значение настройки текущего языка интерфейса
     */
    Language GetLanguage() { return _language; }

    /*!
     * \brief SetLanguage Задать значение настройки текущего языка интерфейса
     * \param language Устанавливаемый язык
     */
    void SetLanguage(const Language language);

    /*!
     * \brief GetTheme Получить значение настройки текущей темы
     * \return Текущая тема
     */
    Theme GetTheme() { return _theme; }

    /*!
     * \brief SetTheme Задать значение настройки текущей темы интерфейса
     * \param theme Устанавливаемая тема
     */
    void SetTheme(const Theme theme);

private:
    /*!
     * \brief LoadSettings Загрузка настроек
     * \return Признак успешной загрузки настроек
     */
    bool LoadSettings();

    /*!
     * \brief SaveSettings Сохранение настроек
     * \return Признак успешного сохранения настроек
     */
    bool SaveSettings();

    Language _language;     // текущий язык
    Theme _theme;           // текущая тема
};

