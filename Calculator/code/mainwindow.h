#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QGridLayout>
#include <QTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_0_clicked();
    void on_btn_1_clicked();
    void on_btn_2_clicked();
    void on_btn_3_clicked();
    void on_btn_4_clicked();
    void on_btn_5_clicked();
    void on_btn_6_clicked();
    void on_btn_7_clicked();
    void on_btn_8_clicked();
    void on_btn_9_clicked();
    void on_btn_add_clicked();
    void on_btn_backspace_clicked();
    void on_btn_calc_clicked();
    void on_btn_ce_clicked();
    void on_btn_clear_clicked();
    void on_btn_div_clicked();
    void on_btn_mul_clicked();
    void on_btn_neg_clicked();
    void on_btn_point_clicked();
    void on_btn_sub_clicked();
    QString calculateExpression(const QString &expression);

private:
    Ui::MainWindow *ui;
    QLabel *lbl_temp;
    QGridLayout *gridLayout_button;
    QTextEdit *le_entry;
};
#endif // MAINWINDOW_H
