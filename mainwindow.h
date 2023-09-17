/***********************************************************
* Команда 2
* Гипертекстовый редактор
*
* Файл заголовков класса главного окна текстового редактора
************************************************************/

#pragma once

#include <QMainWindow>
#include <QPrinter>

#include "filemanager.h"

class QMenu;
class QMdiArea;
class QMdiSubWindow;
class QSignalMapper;
class DocumentWindow;
class QFontComboBox;
class QTextCharFormat;
class QTextList;
class QComboBox;
class FindDialog;
class HyperlinkDialog;
class Settings;

/*!
 * \brief Класс главного окна текстового редактора
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /// Конструктор
    MainWindow(QWidget *parent = nullptr);

    /*!
     * \brief GetMdi Геттер указателя на объект QMdiArea главного окна
     * \return Возвращает указатель на объект QMdiArea главного окна
     */
    QMdiArea* GetMdi() { return _pMdiArea; }

    /*!
     * \brief OpenFile Метод открытия файла в дочернем окне
     * \param fullFileName Полное имя файла: путь и имя
     * \return Признак успешного чтения файла
     */
    bool OpenFile(const QString& pathFileName);

    /*!
     * \brief CreateNewDocument Метод создаёт экземпляр дочернего MDI окна документа
     * \return Возвращает экземпляр дочернего MDI окна документа
     */
    DocumentWindow* CreateNewDocument();

    /*!
     * \brief GetActiveDocumentWindow Возвращает указатель на текущий активный документ
     * \return Указатель на текущий активный документ
     */
    DocumentWindow* GetActiveDocumentWindow();

    /*!
     * \brief getListPath Возвращает указатель на список путей
     */
    QList<QString>* getListPath(){return _pListPath;}

protected:
    /*!
     * \brief closeEvent Перегруженный метод закрытия виджета
     * \param event Указатель на объект с параметрами события
     */
    void closeEvent(QCloseEvent *event) override;

private:

    /*!
     * \brief FontChanged метод формирует отобажение конфигурации шрифта в toolbar главного окна в соответствии с принятым шрифтом
     * \param f шрифт
     */
    void FontChanged(const QFont &f);

    /*!
     * \brief SetupFormatActions метод создает панели и меню форматирования текста
     * \param menu Указатель на меню
     * \return Указатель на тулбар
     */
    QToolBar* SetupFormatActions(QMenu* menu);

    /*!
     * \brief SetupFontActions метод создает панели и меню конфигурирования шрифта
     * \return Указатель на тулбар
     */
    QToolBar* SetupFontActions();

    /*!
     * \brief CreateActions Создаём объекты действий
     */
    void CreateActions();

    /*!
     * \brief SetupBoldActions метод создает панели и меню конфигурирования включения/выключения жирного шрифта
     * \param toolBar указатель на тулбар
     * \param menu указатель на меню
     */
    void SetupBoldActions(QToolBar* toolBar, QMenu* menu);

    /*!
     * \brief SetupBoldActions метод создает панели и меню конфигурирования включения/выключения курсивного шрифта
     * \param toolBar указатель на тулбар
     * \param menu указатель на меню
     */
    void SetupItalicActions(QToolBar* toolBar, QMenu* menu);

    /*!
     * \brief SetupBoldActions метод создает панели и меню конфигурирования включения/выключения подчеркнутого шрифта
     * \param toolBar указатель на тулбар
     * \param menu указатель на меню
     */
    void SetupUnderLineActions(QToolBar* toolBar, QMenu* menu);

    /*!
     * \brief SetupSizeActions метод создает панель изменения размера шрифта
     * \param toolBar ссылка на тулбар
     */
    void SetupSizeActions(QToolBar* toolBar);
    /*!
     * \brief SetupActiveDocument метод удаляет не актуальные соединения сигнал/слот, получает указатель на активное окно класса DocumentWindow и формирует актуальные соединения сигнал/слот
     * \param window указатель на активное окно класса QMdiSubWindow
     */
    void SetupActiveDocument(QMdiSubWindow* window);

    /*!
     * \brief ConnectToActiveDocument метод создания соединений панели и меню конигурирования шрифтов с активным окном класса DocumentWindow
     */
    void ConnectToActiveDocument();

    /*!
     * \brief ConnectToActiveDocument метод удаления соединений панели и меню конигурирования шрифтов с уже неактивным окном класса DocumentWindow
     */
    void DisonnectFromDocument();

    /*!
     * \brief CurrentCharFormatChanged метод формирует отобажение формата текста в toolbar главного окна в соответствии с форматированием
     * \param format ссылка на форматирование
     */
    void CurrentCharFormatChanged(const QTextCharFormat &format);

    /*!
     * \brief MergeFormatOnWordOrSelection установка формата текста в выделение или слово активного документа
     * \param format ссылка на форматирование
     */
    //void MergeFormatOnWordOrSelection(const QTextCharFormat &format);


public slots:
    /*!
     * \brief SlotStatusBarMessage Слот - вывод сообщения в статусбаре главного окна
     */
    void SlotStatusBarMessage(QString);

    /*!
     * \brief SlotOnOpen Слот добавления пути в список путей
     * \param path Путь в формате строки
     */
    void SlotOnOpen(QString path);

    /*!
     * \brief SlotDelPath Слот удаления пути из списка путей
     * \param path Путь в формате строки
     */
    void SlotDelPath(QString path);

private slots:

    /// Слот создания нового документа
    void SlotNewDoc();

    /// Слот загрузки документа
    void SlotLoad();

    /// Слот сохранения документа
    void SlotSave();

    /// Слот сохранить документ как
    void SlotSaveAs();

    /// Слот вызова окна "О программе"
    void SlotAbout();

    /// Слот меню "Окна"
    void SlotWindows();

    /// Слот навигация назад
    void SlotBackward();

    /// Слот навигация Домой
    void SlotHome();

    /// Слот навигация вперёд
    void SlotForward();

    /// Слот вырезать текст
    void SlotCut();

    /// Слот копировать текст
    void SlotCopy();

    /// Слот вставить текст
    void SlotPaste();

    /// Слот печать документа
    void SlotPrint();

    /// Слот предварительного просмотра перед печатью документа
    void SlotPrintPreview();

    /*!
     * \brief SlotPrintPreviewDraw  Слот отображения для предварительного просмотра
     * \param printer Указатель на объект QPrinter
     */
    void SlotPrintPreviewDraw(QPrinter* printer);

    /// Слот сохранить документ в ODT
    void SlotSaveAsOdt();

    /// Слот сохранить документ в PDF
    void SlotPrintPDF();

    /// Слот поиск в тексте
    void SlotFind();

    /// Слот добавление гиперссылки
    void SlotMakeHyperlink();

    /// Слот сделать активными/не активными эементы интерфеса, если документ открыт
    void SlotUpdateMenus();

    /*!
     * \brief SlotSetActiveSubWindow Слот делает дочернее MDI окно активным
     * \param QObject* Указатель на виджет дочернего MDI окна документа
     */
    void SlotSetActiveSubWindow(QObject*);

    /*!
     * \brief SlotSetActiveSubWindowByPath Слот делает дочернее MDI окно активным по имени
     * \param path Имя и путь к файлу в дочернем окне
     */
    void SlotSetActiveSubWindowByPath(QString path);

private:
    int _iUnnamedIndex;                     // индекс для создания имён безымянных файлов

    QMdiArea* _pMdiArea;                    // указатель на MDI виджет
    QMenu* _pMenuWindows;                   // указатель на виджет меню
    QSignalMapper* _pSignalMapper;          // указатель на мапер сигналов
    QToolBar* _pToolBar;                    // указатель на Toolbar
    FileManager* _pFileManager;             // указатель на FileManager - файловый менеджер
    QDockWidget* _pDocWidget;               // указатель на DocWidget файлового менеджера
    DocumentWindow* _pCurrentDocument;      // указатель на активный виджет класса DocumentWindow
    FindDialog* _pFindDialog;               // указатель на FindDialog - диалог поиска
    HyperlinkDialog* _pMakeLinkDialog;      // указатель на HyperlinkDialog - диалог добавления ссылки
    QList<QString>* _pListPath;             // указатель на лист путей открытых файлов
    QList<QMdiSubWindow*> _pListSubWindow;  // Список путей открытых окон
    Settings* _pSettings;                   // указатель на объект настроек

    QAction *actionTextBold;                // включение жирного шрифта
    QAction *actionTextUnderline;           // включение жирного подчеркнутого шрифта
    QAction *actionTextItalic;              // включение жирного курсивного шрифта
    QFontComboBox *comboFont;               // выбор семейства шрифта
    QComboBox* comboSize;                   // выбор размер шрифта

    QAction* _pNewAct;                      // указатель на действие "Новый файл"
    QAction* _pOpenAct;                     // указатель на действие "Открыть файл"
    QAction* _pSaveAct;                     // указатель на действие "Сохранить"
    QAction* _pSaveAsAct;                   // указатель на действие "Сохранить как"
    QAction* _pBackwardAct;                 // указатель на действие "Назад"
    QAction* _pHomeAct;                     // указатель на действие "Домой"
    QAction* _pForwardAct;                  // указатель на действие "Вперёд"
    QAction* _pCutAct;                      // указатель на действие "Вырезать"
    QAction* _pCopyAct;                     // указатель на действие "Копировать"
    QAction* _pPasteAct;                    // указатель на действие "Вставить"
    QAction* _pFindAct;                     // указатель на действие "Поиск"
    QAction* _pPrintAct;                    // указатель на действие "Печать файла"
    QAction* _pPrintPreviewAct;             // указатель на действие "Предпросмотр перед печатю файла"
    QAction* _pPrintPDFAct;                 // указатель на действие "Сохранить как PDF файл"
    QAction* _pCloseAct;                    // указатель на действие закрыть дочернее окно
    QAction* _pCloseAllAct;                 // указатель на действие закрыть всё дочерние окна
    QAction* _pSaveAsOdt;                   // указатель на действие "Сохранить как *.odt"
    QAction* _pMakeLinkAct;                 // указатель на действие добавить гиперссылку
    QAction* _pAboutAct;                    // указатель на действие "О программе"
};
