#include "cgraph.h"

// definicja zmiennych statycznych
QPixmap* CGraph::layout;
vector<QPixmap>* CGraph::tab_layout;
int CGraph::tab_layout_index;
double CGraph::dx;
double CGraph::dy;
double CGraph::xmax;
double CGraph::xmin;
double CGraph::ymax;
double CGraph::ymin;
bool CGraph::skalowaniex;
string CGraph::colorname;

CGraph::CGraph()
{
    static bool first = true;
    if(first)
    {
        layout = new QPixmap("data/background.jpg");
        tab_layout = new vector<QPixmap>;
        first = false;
        colorname = "red";
        skalowaniex = true;
    }
}

CGraph::~CGraph()
{
}

void CGraph::DrawGraph(Ui::MainWindow *ui)
{
    static bool first = true;
    if(first)
    {
        DrawLayout(ui);
        first = false;
    }
    // jezeli jest zaznaczony checkbox, zeby czyscic uklad przed rysowanie, to czysc
    if(ui->CheckBoxCzyscUklad->checkState() == Qt::Checked)
    {
        DrawLayout(ui);
    }
    // sklej nazwe pliku
    int widthline = ui->SpinBoxGruboscLinii->value();
    string file("data/");
    file += colorname;
    char grubosc = '0' + widthline;
    file += grubosc;
    file += ".jpg";

    QString exp = ui->LineEditFunction->text();
    string exp2 = exp.toLocal8Bit().constData();
    double x1 = QString(ui->LineEditx1->text()).toDouble();
    double x2 = QString(ui->LineEditx2->text()).toDouble();
    int occ = ui->SliderOccuracy->value();
    double occuracy = 2.0/occ;
    ui->progressBar->setValue(0);
    double podzialkax = (double)ui->SpinBoxPodzialkaX->value();
    double podzialkay = (double)ui->SpinBoxPodzialkaY->value();

    QPixmap punkt(file.c_str());
    QPainter p;
    p.begin(layout);
    double y;
    double x11 = x1*dx;
    double x22 = x2*dx;
    double progressbar = (x22 - x11) * occuracy / 100.0;
    double progressbarvalue = 0.0;
    if(!exp2.empty())
    {
        for(double x = x11; x < x22; x += occuracy)
        {
            CMathParser parser;
            y = parser.Parse(exp2, (x/dx)*podzialkax)*dy/podzialkay;
            if(!parser.IsError())
            {
                if(skalowaniex)
                    p.drawPixmap((int)(x+std::abs(xmin*dx)), (int)(-y+std::abs(ymax*dy)), punkt);
                else
                    p.drawPixmap((int)(y+std::abs(ymax*dy)), (int)(x+std::abs(xmin*dx)), punkt);
            }
            progressbarvalue += progressbar;
            ui->progressBar->setValue((int)(progressbarvalue));
        }
        p.end();
        // zapisz pixmape do tablicy
        if(tab_layout->size() < 20)
        {
            tab_layout->push_back(*layout);
            tab_layout_index = tab_layout->size()-1;
        }
        ui->label->setPixmap(*layout);
    }
}

void CGraph::DrawLayout(Ui::MainWindow *ui)
{
    // pobierz przedzialy ukladu
    xmin = QString(ui->LineEditXmin->text()).toDouble();
    xmax = QString(ui->LineEditXmax->text()).toDouble();
    ymin = QString(ui->LineEditYmin->text()).toDouble();
    ymax = QString(ui->LineEditYmax->text()).toDouble();
    double ilex = (std::abs(xmin) + std::abs(xmax));
    double iley = (std::abs(ymin) + std::abs(ymax));
    dx = 550.0 / ilex;
    dy = 550.0 / iley;

    layout->load("data/background.jpg");
    QPainter p;
    p.begin(layout);
    QPen pen(Qt::black, 1, Qt::DotLine);
    p.setPen(pen);

    ///////////   PODZIALKA  UKLADU WSPOLRZEDNYCH  /////////////////////
    // rysuj pionowe linie po lewej stronie
    for(double i = xmin*dx; i >= 0; i -= dx)
    {
        p.drawLine(i, 0, i, 550);
    }
    // rysuj pionowe linie po prawej stronie
    for(double i = xmin*dx; i <= 550; i += dx)
    {
        p.drawLine(i, 0, i, 550);
    }
    // rysuj poziome linie na dole
    for(double i = ymax*dy; i <= 550; i += dy)
    {
        p.drawLine(0, i, 550, i);
    }
    // rysuj poziome linie na gorze
    for(double i = ymax*dy; i >= 0; i -= dy)
    {
        p.drawLine(0, i, 550, i);
    }
    ////////////////  OSIE  UKLADU  WSPOLRZEDNYCH   ////////////////
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(2);
    p.setPen(pen);
    // pionowa
    p.drawLine(550-xmax*dx, 0, 550-xmax*dx, 550);
    // pozioma
    p.drawLine(0, ymax*dy, 550, ymax*dy);
    p.end();
    ui->label->setPixmap(*layout);

}

void CGraph::GetFilenamePunkt()
{
    //filename = file;
}

double CGraph::Getdx()
{
    xmin = QString(ui->LineEditXmin->text()).toDouble();
    xmax = QString(ui->LineEditXmax->text()).toDouble();
    int ilex = (int)(std::abs(xmin) + std::abs(xmax));
    dx = 550 / ilex;
return dx;
}

double CGraph::Getdy()
{
    ymin = QString(ui->LineEditYmin->text()).toDouble();
    ymax = QString(ui->LineEditYmax->text()).toDouble();
    int iley = (int)(std::abs(ymin) + std::abs(ymax));
    dy = 550 / iley;
return dy;
}
