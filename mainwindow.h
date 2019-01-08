#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/video.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <QTimer>
using namespace cv;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_open_cam_clicked();
    void getFrame();

    void on_SaveVideo_clicked();

    void on_OpenVideo_clicked();

    void on_pushButton_exit_clicked();

    void on_CloseCam_clicked();

private:
    Ui::MainWindow *ui;
    Mat frame;//摄像头每次抓取的图像为一帧，使用该指针指向一帧图像的内存空间
    QTimer *timer;//定时器用于定时取帧，上面说的隔一段时间就去取就是用这个实现
    VideoCapture cam;
    VideoWriter write;
    bool OPEN;
};

#endif // MAINWINDOW_H
