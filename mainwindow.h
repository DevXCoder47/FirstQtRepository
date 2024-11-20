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
    Q_PROPERTY(QString message READ getMessage WRITE setMessage)
public:
    MainWindow(QWidget *parent = nullptr);
    QString getMessage() const {return message;}
    void setMessage(QString val){
        message = val;
    }
    ~MainWindow();
private slots:
    void on_AddButton_clicked();
    void on_TakeButton_clicked();
    void on_StepBox_valueChanged(int arg1);
private:
    Ui::MainWindow *ui;
    const QString TITLE = "Out of limits";
    int step;
    QString message;
    void renderMessage(const QString msg);
};
#endif // MAINWINDOW_H
