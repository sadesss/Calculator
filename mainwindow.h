#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define FLAG 1

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:

    void on_num_clicked();

    void on_pbn_reset_clicked();

    void on_pbn_del_clicked();

    void on_sub_clicked();

    void on_pbn_res_clicked();

    void on_pbn_comma_clicked();

    void on_pbn_root_clicked();

    void on_pbn_change_clicked();

    void on_trig_clicked();

private:
    Ui::MainWindow *ui;

    void set_numbers_true(bool status);

    void set_operations_true(bool status);

    void set_trig_true(bool status);

    void e_in_text();

    void pixel_art();
};
#endif // MAINWINDOW_H
