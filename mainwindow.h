#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStack>
#include <QString>

QT_BEGIN_NAMESPACE
class QListWidget;
class QLineEdit;
class QPushButton;
class QLabel;
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onPushClicked();   // Добавление в стек
    void onPopClicked();    // Удаление из стека
    void onTopClicked();    // Показать вершину
    void onClearClicked();  // Очистить стек
    void updateDisplay();   // Обновить отображение стека

private:
    QStack<QString> m_stack;   // Стек строк

    // Виджеты
    QLineEdit   *m_lineEdit;
    QPushButton *m_pushButton;
    QPushButton *m_popButton;
    QPushButton *m_topButton;
    QPushButton *m_clearButton;
    QListWidget *m_listWidget;
    QLabel      *m_statusLabel;
};

#endif // MAINWINDOW_H
