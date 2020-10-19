#include <QApplication>

#include <main-helper.h>


int main(int argc, char *argv[ ])
{
  QApplication app(argc, argv);

  MainHelper helper;
  helper.run();

  return app.exec();
}

