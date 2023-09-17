/****************************************
* Команда 2
* Гипертекстовый редактор
*
* Код класса файлового менеджера
*****************************************/

#include "documentwindow.h"
#include "filemanager.h"
#include "mainwindow.h"

#include <QHeaderView>
#include <QMessageBox>
#include <QMdiArea>


FileManager::FileManager(QWidget *pParent) : QTreeView(pParent)
{
    _mainWindow = dynamic_cast<MainWindow*>(parent());
    _fileSystem = new QFileSystemModel;
    _fileSystem->setRootPath(QDir::currentPath());
    setModel(_fileSystem);
    hideColumn(1);
    hideColumn(2);
    hideColumn(3);
    setMinimumWidth(240);
    setMinimumHeight(480);
    QModelIndex index = _fileSystem->index(QDir::currentPath());
    expand(index);
    scrollTo(index);
    resizeColumnToContents(0);
    setIndentation(5);

}

// Переопределенный метод двойного нажатия левой кнопки мыши открывает файл в Hypertext editor
void FileManager::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        QModelIndex index = indexAt(event->pos());
        if (_fileSystem->fileInfo(index).isFile())
        {
            QString pathToFile = _fileSystem->fileInfo(index).absoluteFilePath();
            //setColumnWidth(1, 100);
            if(!_mainWindow->getListPath()->contains(pathToFile)){
                DocumentWindow *doc;
                if(_mainWindow)
                    doc = _mainWindow->CreateNewDocument();
                else
                    doc = new DocumentWindow();
                doc->setAttribute(Qt::WA_DeleteOnClose);
//                qDebug()<<_mainWindow->getListPath()->contains(pathToFile);
// перенесено!               _mainWindow->getListPath()->append(pathToFile);
                doc->OpenFile(pathToFile);
                doc->show();
            }
            else
                emit SignalSetActive(pathToFile);
        }
        else
        {
            if (isExpanded(index))
                setExpanded(index, false);
            else
                setExpanded(index, true);
        }
    }
}
