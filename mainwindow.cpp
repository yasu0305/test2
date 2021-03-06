#include <random>

void gen_random(char *s, const int len)
{

    static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < len; ++i)
        s[i] = alphanum[std::rand() % (sizeof(alphanum) - 1)];

    s[len] = 0;

}


#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    timer = new QTimer(this);
    timer->setInterval(1000);
    connect(timer, SIGNAL(timeout()), SLOT(disp_text_browser()));

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    int ret = QMessageBox::question( this, tr("title"), tr("test") );

    if( ret == QMessageBox::Yes )
        ui->label->setText("Yes");
    else
        ui->label->setText("No");

}


void MainWindow::disp_text_browser()
{

    static int i=0;

    ui->textBrowser->setText(QString::number(i++));

}


void MainWindow::on_pushButton_2_clicked()
{

    if(!timer->isActive())
        timer->start();

}


void MainWindow::on_pushButton_3_clicked()
{

    timer->stop();

}


void MainWindow::on_pushButton_4_clicked()
{

    const int ROWS = 5;
    const int COLS = 4;

    ui->tableWidget->setSortingEnabled(false);
    ui->tableWidget->clear();
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setRowCount(ROWS);
    ui->tableWidget->setColumnCount(COLS);

    for (int col = 0; col < COLS; col++)
        ui->tableWidget->setHorizontalHeaderItem(col,new QTableWidgetItem(tr("Header:%1").arg(col)));

    char str[256]="";
    int length = 10;

    srand((unsigned int)time(NULL));

    for(int row = 0; row < ROWS; row++){
        for(int col = 0; col < COLS; col++){
            length = rand()%20 + 1;
            gen_random(str, length);
            QTableWidgetItem *item = new QTableWidgetItem(str);
            ui->tableWidget->setItem(row, col, item);
        }
    }

    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->setSortingEnabled(true);

}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{

    for(int i=0; i<ui->tableWidget->rowCount(); i++){
        ui->tableWidget->hideRow(i);
        for(int j=0; j<ui->tableWidget->columnCount(); j++){
            if(ui->tableWidget->item(i, j)->text().contains(arg1, Qt::CaseInsensitive))
                ui->tableWidget->showRow(i);
        }
    }

    if(arg1 == ""){
        for(int i=0; i<ui->tableWidget->rowCount(); i++)
            ui->tableWidget->showRow(i);
    }

}
