#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

     ui->setupUi(this);
     timer = new QTimer(this);
     cam = NULL;
     OPEN = true;
     connect(timer,SIGNAL(timeout()),this,SLOT(getFrame()));
}



void MainWindow::on_open_cam_clicked()
{
    // 设置摄像头的拍摄属性为 分辨率640x480，帧率30fps
//    cam.set(CAP_PROP_FRAME_HEIGHT, 480);
//    cam.set(CAP_PROP_FRAME_WIDTH, 640);
//    cam.set(CAP_PROP_FPS, 30.0);
    //打开摄像头 从摄像头中获取视频
    cam.open(0);
    //开启定时器，每隔0.05秒刷新一次
    timer->start(50);
}

void MainWindow::getFrame()
{
   //读取摄像头信息 将读取回来的帧转换成QImage类型
   //从摄像头中抓取并返回每一帧
   cam >> frame;
   //将抓取到的帧转换成QImage格式
   QImage img1 = QImage((const unsigned char*)frame.data, frame.cols, frame.rows, QImage::Format_RGB888).rgbSwapped();//个人测试时可以试试去掉.rgbSwapped()后的效果
   //将图片显示到QLabel上
   //ui->label->setPixmap(QPixmap::fromImage(img1));
   namedWindow("VideoPlay", WINDOW_NORMAL);
   imshow("VideoPlay", frame);
   waitKey(1000 / 30);
}
void MainWindow::on_SaveVideo_clicked()
{
    if(!cam.isOpened())
           cam.open(0);
     VideoWriter write("D:\\test.avi", CV_FOURCC('X', 'V', 'I', 'D'), 30.0, Size(640, 480), true);
      // write.open("D:\\test.avi",VideoWriter::fourcc('M', 'J', 'P', 'G'), 30.0, Size(640, 480), true);
       while(OPEN)
       {
           cam >> frame;
           //设置保存视频的格式为AVI，编码为MJPG
           write.write(frame);
           namedWindow("VideoPlay", WINDOW_NORMAL);
           imshow("VideoPlay", frame);
           waitKey(1000 / 30);
       }
}

void MainWindow::on_OpenVideo_clicked()
{
    VideoCapture video;
       Mat frame2;
       video.open("D:\\test.avi");
       while (video.isOpened())
       {
           video >> frame2;
           imshow("video", frame2);
           if (cvWaitKey(40) == 27)  //cvWaitKey的参数相当于多少ms一帧，现在是40ms一帧，1s25帧
               break;                //按ESC就退出
       }


}
MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButton_exit_clicked()
{
    exit(0);
}

void MainWindow::on_CloseCam_clicked()
{
    timer->stop();
    cam.release();
    OPEN = false;
    write.release();
    destroyWindow("VideoPlay");
}
