#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_btnAdd_clicked();

    void on_btnSub_clicked();

    void on_btnDiv_clicked();

    void on_btnMult_clicked();

private:
    Ui::MainWindow *ui;

    enum class MathOp {
        Add, Sub, Mult, Div,
    };

    float performOp(MathOp op) const;
};
#endif // MAINWINDOW_H
