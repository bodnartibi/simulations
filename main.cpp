#include <QApplication>

#include <main-helper.h>


int main(int argc, char *argv[ ])
{
  QApplication app(argc, argv);

  MainHelper helper(50, 50);
  helper.run();

  return app.exec();
}

