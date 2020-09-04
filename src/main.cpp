#include "water-hammer-simulation.h"
#include <QApplication>

int main(int argc, char *argv[])
{

#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
    QApplication::setGraphicsSystem("raster");
#endif
    QApplication::setApplicationName("water-hammer-simulation");
    QApplication::setOrganizationName("HAFIANE Mohamed");
    QApplication a(argc, argv);
    water_hammer_simulation w;
    QPixmap pixmap = QPixmap (":/icons/water-hammer-simulation.ico");
    w.setWindowIcon(QIcon(pixmap));
    w.show();

    return a.exec();
}
