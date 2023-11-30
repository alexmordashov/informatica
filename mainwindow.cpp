#include "mainwindow.h"
#include "./ui_mainwindow.h"
//#include <string>
QString otvet = "";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_0_clicked()
{
    ui->lbl_temp->setText(ui->lbl_temp->text() + ui->btn_0 ->text());
}

void MainWindow::on_btn_1_clicked()
{
    ui->lbl_temp->setText(ui->lbl_temp->text() + ui->btn_1 ->text());
}

void MainWindow::on_btn_2_clicked()
{
    ui->lbl_temp->setText(ui->lbl_temp->text() + ui->btn_2 ->text());
}

void MainWindow::on_btn_3_clicked()
{
    ui->lbl_temp->setText(ui->lbl_temp->text() + ui->btn_3 ->text());
}

void MainWindow::on_btn_4_clicked()
{
    ui->lbl_temp->setText(ui->lbl_temp->text() + ui->btn_4 ->text());
}

void MainWindow::on_btn_5_clicked()
{
    ui->lbl_temp->setText(ui->lbl_temp->text() + ui->btn_5 ->text());
}

void MainWindow::on_btn_6_clicked()
{
    ui->lbl_temp->setText(ui->lbl_temp->text() + ui->btn_6 ->text());
}

void MainWindow::on_btn_7_clicked()
{
    ui->lbl_temp->setText(ui->lbl_temp->text() + ui->btn_7 ->text());
}

void MainWindow::on_btn_8_clicked()
{
    ui->lbl_temp->setText(ui->lbl_temp->text() + ui->btn_8 ->text());
}

void MainWindow::on_btn_9_clicked()
{
    ui->lbl_temp->setText(ui->lbl_temp->text() + ui->btn_9 ->text());
}

void MainWindow::on_btn_add_clicked()
{
    ui->lbl_temp->setText(ui->lbl_temp->text() + " " + ui->btn_add ->text() + " ");
}

void MainWindow::on_btn_backspace_clicked()
{
    QString text_entry = ui->le_entry->text();
    QString text_temp = ui->lbl_temp->text();
    text_entry.chop(1);
    text_temp.chop(1);
    ui->le_entry->setText(text_entry);
    ui->lbl_temp->setText(text_temp);
}

void MainWindow::on_btn_calc_clicked()
{
    QString expression = ui->lbl_temp->text();
    QString result = calculateExpression(expression);
    ui->le_entry->setText(result);
    otvet = expression;
}


void MainWindow::on_btn_ce_clicked()
{
    ui->le_entry->clear();
    ui->lbl_temp->clear();
}

void MainWindow::on_btn_clear_clicked()
{
    ui->lbl_temp->clear();
    ui->lbl_temp->setText(ui->lbl_temp->text() + otvet);

}

void MainWindow::on_btn_div_clicked()
{
    ui->lbl_temp->setText(ui->lbl_temp->text() + " " + ui->btn_div ->text() + " ");
}

void MainWindow::on_btn_mul_clicked()
{
    ui->lbl_temp->setText(ui->lbl_temp->text() + " " + ui->btn_mul ->text() + " ");
}

void MainWindow::on_btn_neg_clicked()
{
    QString text = ui->lbl_temp->text();
    if (text.isEmpty()) {
        return;
    }
    if (text.at(0) == '-') {
        text.remove(0, 1);
    }
    else {
        text.prepend("-");
    }
    ui->lbl_temp->setText(text);
}

void MainWindow::on_btn_point_clicked()
{
    ui->lbl_temp->setText(ui->lbl_temp->text() + ui->btn_point ->text());
}

void MainWindow::on_btn_sub_clicked()
{
    ui->lbl_temp->setText(ui->lbl_temp->text() + " " + ui->btn_sub ->text() + " ");
}

QString MainWindow::calculateExpression(const QString &expression) {
    qDebug() << "Expression:" << expression;
    QStringList tokens = expression.split(" ");
    qDebug() << "Tokens:" << tokens;
    QList <QString> numbers;
    QList <QString> operators;
    for (const QString &token: tokens) {
        if (token != "+" && token != "-" && token != "*" && token != "/") {
            numbers.push_back(token);
        }
        else {
            operators.push_back(token);
        }
    }
    for (int i = 0; i < operators.size(); i++) {
        if (operators.at(i) == "*" || operators.at(i) == "/") {
            double a = numbers.at(i).toDouble();
            QString op = operators.at(i);
            double b = numbers.at(i + 1).toDouble();
            if (op == "*") {
                numbers[i] = QString::number(a * b);
            }
            else if (op == "/") {
                if (b == 0.0) {
                    return "Error: Division by zero";
                }
                numbers[i] = QString::number(a / b);
            }
            operators.removeAt(i);
            numbers.removeAt(i + 1);
            --i;
        }
    }
    while (!operators.isEmpty()) {
        double a = numbers.takeFirst().toDouble();
        QString op = operators.takeFirst();
        double b = numbers.takeFirst().toDouble();
        if (op == "+") {
            numbers.push_front(QString::number(a + b));
        }
        else if (op == "-") {
            numbers.push_front(QString::number(a - b));
        }
    }
    if (numbers.size() == 1) {
        QString result = numbers.takeFirst();
        qDebug() << "Result:" << result;
        return result;
    }
    else {
        return "Error";
    }
}
