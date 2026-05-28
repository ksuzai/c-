#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QLabel>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Создаем центральный виджет
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Создаем элементы управления
    m_lineEdit = new QLineEdit(this);
    m_lineEdit->setPlaceholderText("Введите строку для добавления в стек");

    m_pushButton = new QPushButton("Push (добавить)", this);
    m_popButton  = new QPushButton("Pop (удалить)", this);
    m_topButton  = new QPushButton("Top (верхушка)", this);
    m_clearButton = new QPushButton("Clear (очистить)", this);

    m_listWidget = new QListWidget(this);
    m_statusLabel = new QLabel("Стек пуст", this);

    // Раскладка
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    QHBoxLayout *inputLayout = new QHBoxLayout();
    inputLayout->addWidget(m_lineEdit);
    inputLayout->addWidget(m_pushButton);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(m_popButton);
    buttonLayout->addWidget(m_topButton);
    buttonLayout->addWidget(m_clearButton);

    mainLayout->addLayout(inputLayout);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(m_listWidget);
    mainLayout->addWidget(m_statusLabel);

    // Подключаем сигналы
    connect(m_pushButton, &QPushButton::clicked, this, &MainWindow::onPushClicked);
    connect(m_popButton,  &QPushButton::clicked, this, &MainWindow::onPopClicked);
    connect(m_topButton,  &QPushButton::clicked, this, &MainWindow::onTopClicked);
    connect(m_clearButton,&QPushButton::clicked, this, &MainWindow::onClearClicked);

    updateDisplay();

    setWindowTitle("Стек строк (Qt)");
    resize(400, 300);
}

MainWindow::~MainWindow() {}

void MainWindow::onPushClicked() {
    QString text = m_lineEdit->text().trimmed();
    if (text.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите непустую строку!");
        return;
    }

    m_stack.push(text);
    m_lineEdit->clear();
    updateDisplay();
}

void MainWindow::onPopClicked() {
    if (m_stack.isEmpty()) {
        QMessageBox::information(this, "Информация", "Стек пуст, нечего удалять!");
        return;
    }

    QString removed = m_stack.pop();
    m_statusLabel->setText(QString("Удалено: %1").arg(removed));
    updateDisplay();
}

void MainWindow::onTopClicked() {
    if (m_stack.isEmpty()) {
        QMessageBox::information(this, "Информация", "Стек пуст!");
        return;
    }

    QMessageBox::information(this, "Вершина стека",
                             QString("На вершине: %1").arg(m_stack.top()));
}

void MainWindow::onClearClicked() {
    m_stack.clear();
    updateDisplay();
    m_statusLabel->setText("Стек очищен");
}

void MainWindow::updateDisplay() {
    m_listWidget->clear();

    if (m_stack.isEmpty()) {
        m_listWidget->addItem("<пусто>");
        m_statusLabel->setText("Стек пуст");
        return;
    }

    // Показываем стек сверху вниз
    for (int i = m_stack.size() - 1; i >= 0; --i) {
        QString itemText = QString("[%1] %2").arg(i).arg(m_stack[i]);
        m_listWidget->addItem(itemText);
    }

    m_statusLabel->setText(QString("В стеке элементов: %1").arg(m_stack.size()));
}
