/*************************************************
* Команда 2
* Гипертекстовый редактор
*
* Файл заголовков класса окна диалога поиска
**************************************************/

#pragma once

#include <QDialog>

class MainWindow;

namespace Ui
{
class FindDialog;
}

/*!
 * \brief FindDialog класс диалога поиска
 */
class FindDialog : public QDialog
{
    Q_OBJECT

public:
    /// Конструктор
    explicit FindDialog(QWidget *parent = nullptr);

    /// Деструктор
    ~FindDialog();

    /*!
     * \brief SetButtonLabel Задать надпись на кнопке
     * \param label Надпись на кнопке
     */
    void SetButtonLabel(QString label);

    /*!
     * \brief SetWTCheckBoxLabel Задать метку чекбокса "Текст полностью"
     * \param label Метка чекбокса
     */
    void SetWTCheckBoxLabel(QString label);

    /*!
     * \brief GetSearchRequest Возвращает поисковый запрос
     * \return Строка поиска
     */
    QString GetSearchRequest();

    /*!
     * \brief GetWTCheckBoxStatus Проверка флага "Слова целиком"
     * \return Флаг "Слова целиком"
     */
    bool GetWTCheckBoxStatus();

    /*!
     * \brief GetCSCheckBoxStatus Проверка флага "С учётом регистра"
     * \return Флаг "С учётом регистра"
     */
    bool GetCSCheckBoxStatus();

    /*!
     * \brief GetBackwardCheckBoxStatus Проверка флага "В обратном направлении"
     * \return Флаг "В обратном направлении"
     */
    bool GetBackwardCheckBoxStatus();

    /*!
     * \brief ClearRequest Очистка строки поиска
     */
    void ClearRequest();

private slots:
    /// Слот - нажатие клавиши "Поиск"
    void SlotButtonFind();

private:
    Ui::FindDialog *ui;             // Указатель на пользовательский интерфейс
    MainWindow* _mainWindow;        // указатель на главное окно
};
