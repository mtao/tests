 #include <QApplication>
 #include <QFont>
 #include <QPushButton>
 #include <QWidget>
 #include <QtGui>
 #include <GL/gl.h>


class MyWidget: public QWidget
{
public:
    MyWidget(QWidget *parent =0);
};

MyWidget::MyWidget(QWidget *parent):QWidget(parent)
{
    setFixedSize(200,120);
    
   QPushButton *quit = new QPushButton(tr("Quit"), this);
     quit->setGeometry(62, 40, 75, 30);
     quit->setFont(QFont("Times", 18, QFont::Bold));

     connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
 }








int main(int argc, char *argv[])
{
     QApplication app(argc, argv);
     QWidget window;
     MyWidget widget;


     QLabel *label = new QLabel(QApplication::translate("windowlayout", "Name:"));
     QLineEdit *lineEdit = new QLineEdit();

     QVBoxLayout *layout = new QVBoxLayout();
     layout->addWidget(label);
     layout->addWidget(lineEdit);


     QVBoxLayout *layout2= new QVBoxLayout();
     layout2->addWidget((QWidget *)&widget,0,Qt::AlignVCenter);

     layout->addLayout(layout2);

     window.setLayout(layout);
     window.setWindowTitle(
         QApplication::translate("windowlayout", "Window layout"));
     window.show();
     return app.exec();

}


