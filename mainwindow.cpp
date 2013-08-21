#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <Qsci/qscilexersql.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this->ui->actionQuit, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(this->ui->actionAbout_Qt, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    QLayout *sqlPaneLayout = new QHBoxLayout();
    this->sqlpane = new QsciScintilla(this);
    sqlPaneLayout->addWidget(this->sqlpane);
    sqlPaneLayout->setContentsMargins(0,0,0,0);
    ui->sqlPaneContents->setLayout(sqlPaneLayout);

    QsciLexerSQL *lexer = new QsciLexerSQL(this);
    this->sqlpane->setLexer(lexer);
    this->sqlpane->setFont(QFont("Monospace"));

    this->setWindowState(Qt::WindowMaximized);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
